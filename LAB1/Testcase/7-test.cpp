#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
#include <iomanip>  // For std::fixed and std::setprecision

class Student {
private:
    std::string fullName;
    float mathScore, literatureScore, foreignLanguageScore;

public:
    // Constructor
    Student(const std::string& name, float math, float literature, float language)
        : fullName(name), mathScore(math), literatureScore(literature), foreignLanguageScore(language) {}

    // Getter methods
    std::string getFullName() const { return fullName; }
    float getMathScore() const { return mathScore; }
    float getLiteratureScore() const { return literatureScore; }
    float getForeignLanguageScore() const { return foreignLanguageScore; }

    // Method to calculate average score with math weighted more
    float calculateAverageScore() const {
        return (2 * mathScore + literatureScore + foreignLanguageScore) / 4;
    }

    // Method to classify students based on average score
    std::string classifyStudent() const {
        float avg = calculateAverageScore();
        if (avg >= 9) return "Excellent";
        else if (avg >= 8) return "Good";
        else if (avg >= 6.5) return "Fair";
        else if (avg >= 5) return "Average";
        else return "Weak";
    }

    // Static method to validate names (no numeric characters allowed)
    static bool isValidName(const std::string& name) {
        return std::all_of(name.begin(), name.end(), [](char c) {
            return std::isalpha(c) || std::isspace(c);
        });
    }

    // Static method to validate scores (between 0 and 10)
    static bool isValidScore(float score) {
        return score >= 0 && score <= 10;
    }
};

class StudentManager {
private:
    std::vector<Student> students;

public:
    // Method to add a student
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Method to find and return the student with the highest average score
    Student findTopStudent() const {
        if (students.empty()) {
            throw std::runtime_error("No students available!");
        }
        float maxAverage = -1;
        Student topStudent = students[0];
        for (const auto& student : students) {
            float avg = student.calculateAverageScore();
            if (avg > maxAverage) {
                maxAverage = avg;
                topStudent = student;
            }
        }
        return topStudent;
    }

    // Method to search for students by (partial) name, case insensitive
    std::vector<Student> searchStudentsByName(const std::string& query) const {
        std::vector<Student> results;
        std::string lowerQuery = toLower(query);
        for (const auto& student : students) {
            std::string lowerName = toLower(student.getFullName());
            if (lowerName.find(lowerQuery) != std::string::npos) {
                results.push_back(student);
            }
        }
        return results;
    }

    // Method to find and return students with the lowest math score
    std::vector<Student> findLowestMathScoreStudents() const {
        if (students.empty()) {
            throw std::runtime_error("No students available!");
        }
        float minMathScore = std::numeric_limits<float>::max();
        for (const auto& student : students) {
            if (student.getMathScore() < minMathScore) {
                minMathScore = student.getMathScore();
            }
        }

        std::vector<Student> result;
        for (const auto& student : students) {
            if (student.getMathScore() == minMathScore) {
                result.push_back(student);
            }
        }
        return result;
    }

    // Helper function to convert a string to lowercase
    static std::string toLower(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });
        return result;
    }

    // Method to print all student information (for display purposes)
    void printAllStudents() const {
        for (const auto& student : students) {
            std::cout << "Name: " << student.getFullName() << "\n";
            std::cout << "Math Score: " << student.getMathScore() << ", Literature Score: " << student.getLiteratureScore()
                      << ", Foreign Language Score: " << student.getForeignLanguageScore() << "\n";
            std::cout << "Average Score: " << std::fixed << std::setprecision(2) 
                      << student.calculateAverageScore() << ", Classification: " 
                      << student.classifyStudent() << "\n\n";
        }
    }
};

int main() {
    StudentManager manager;

    // Test case data as specified in your table
    std::vector<Student> testCases = {
        {"Nguyễn Văn A", 9.0, 8.5, 8.75},
        {"Trần Thị B", 7.5, 6.0, 6.75},
        {"Lê Văn C", 5.0, 6.0, 5.50},
        {"Phạm Minh D", 8.0, 7.0, 7.50},
        {"Đặng Thị E", 4.0, 5.0, 4.50},
        {"Hoàng Văn F", 9.0, 9.5, 9.25},
        {"Bùi Thị G", 6.0, 5.5, 5.75},
        {"Ngô Văn H", 8.5, 7.5, 8.00},
        {"Vũ Thị I", 9.0, 6.5, 7.75},
        {"Trịnh Văn K", 5.5, 6.0, 5.75},
        {"Phan Thị L", 7.0, 8.0, 7.50},
        {"Dương Văn M", 6.0, 7.0, 6.50},
        {"Nguyễn Thị N", 9.5, 8.5, 9.00},
        {"Trần Văn O", 7.5, 7.0, 7.25},
        {"Lê Thị P", 4.0, 5.5, 4.75},
        {"Ngô Văn Q", 8.0, 8.0, 8.00},
        {"Đặng Thị R", 6.5, 6.0, 6.25},
        {"Bùi Văn S", 9.0, 7.5, 8.25},
        {"Phạm Thị T", 5.0, 5.5, 5.25},
        {"Hoàng Văn U", 8.0, 9.0, 8.50}
    };

    // Add test cases to the manager
    for (const auto& student : testCases) {
        manager.addStudent(student);
    }

    // Display all student details
    std::cout << "\nAll Student Information:\n";
    manager.printAllStudents();

    // Find and display the student with the highest average score
    try {
        Student topStudent = manager.findTopStudent();
        std::cout << "\nStudent with the highest average score:\n";
        std::cout << "Name: " << topStudent.getFullName() << ", Average Score: " 
                  << std::fixed << std::setprecision(2) << topStudent.calculateAverageScore() << "\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    // Search for students by name
    std::string query = "Nguyễn";  // Example search query
    std::vector<Student> foundStudents = manager.searchStudentsByName(query);

    if (!foundStudents.empty()) {
        std::cout << "\nSearch results:\n";
        for (const auto& student : foundStudents) {
            std::cout << "Name: " << student.getFullName() << ", Average Score: " 
                      << std::fixed << std::setprecision(2) << student.calculateAverageScore() << "\n";
        }
    } else {
        std::cout << "No students found with the name " << query << ".\n";
    }

    // Find and display students with the lowest math score
    try {
        std::vector<Student> lowestMathStudents = manager.findLowestMathScoreStudents();
        std::cout << "\nStudents with the lowest math score:\n";
        for (const auto& student : lowestMathStudents) {
            std::cout << "Name: " << student.getFullName() << ", Math Score: " 
                      << std::fixed << std::setprecision(2) << student.getMathScore() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}
