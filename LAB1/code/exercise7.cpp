#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
#include <iomanip>  // For std::fixed and std::setprecision

/**
 * @class Student
 * @brief Represents a student with their scores and provides methods to manage and classify them.
 */
class Student {
private:
    std::string fullName; /**< The full name of the student. */
    float mathScore; /**< The student's score in mathematics. */
    float literatureScore; /**< The student's score in literature. */
    float foreignLanguageScore; /**< The student's score in a foreign language. */

public:
    /**
     * @brief Constructs a Student object with given scores.
     * @param name The full name of the student.
     * @param math The student's score in mathematics.
     * @param literature The student's score in literature.
     * @param language The student's score in a foreign language.
     */
    Student(const std::string& name, float math, float literature, float language)
        : fullName(name), mathScore(math), literatureScore(literature), foreignLanguageScore(language) {}

    /** 
     * @brief Gets the full name of the student.
     * @return The student's full name.
     */
    std::string getFullName() const { return fullName; }

    /** 
     * @brief Gets the student's score in mathematics.
     * @return The mathematics score.
     */
    float getMathScore() const { return mathScore; }

    /** 
     * @brief Gets the student's score in literature.
     * @return The literature score.
     */
    float getLiteratureScore() const { return literatureScore; }

    /** 
     * @brief Gets the student's score in a foreign language.
     * @return The foreign language score.
     */
    float getForeignLanguageScore() const { return foreignLanguageScore; }

    /** 
     * @brief Calculates the weighted average score of the student.
     * @return The calculated average score.
     */
    float calculateAverageScore() const {
        return (2 * mathScore + literatureScore + foreignLanguageScore) / 4;
    }

    /** 
     * @brief Classifies the student based on their average score.
     * @return A string representing the classification of the student.
     */
    std::string classifyStudent() const {
        float avg = calculateAverageScore();
        if (avg >= 9) return "Excellent";
        else if (avg >= 8) return "Good";
        else if (avg >= 6.5) return "Fair";
        else if (avg >= 5) return "Average";
        else return "Weak";
    }

    /** 
     * @brief Validates the student's name to ensure it contains only alphabetic characters and spaces.
     * @param name The name to validate.
     * @return True if valid, false otherwise.
     */
    static bool isValidName(const std::string& name) {
        return std::all_of(name.begin(), name.end(), [](char c) {
            return std::isalpha(c) || std::isspace(c);
        });
    }

    /** 
     * @brief Validates the student's score to ensure it is between 0 and 10.
     * @param score The score to validate.
     * @return True if valid, false otherwise.
     */
    static bool isValidScore(float score) {
        return score >= 0 && score <= 10;
    }
};

/**
 * @class StudentManager
 * @brief Manages a collection of students and provides methods to interact with them.
 */
class StudentManager {
private:
    std::vector<Student> students; /**< A vector to hold the list of students. */

public:
    /** 
     * @brief Adds a student to the collection.
     * @param student The student to be added.
     */
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    /** 
     * @brief Finds and returns the student with the highest average score.
     * @return The student with the highest average score.
     * @throws std::runtime_error if no students are available.
     */
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

    /** 
     * @brief Searches for students by name (case insensitive).
     * @param query The name (or part of it) to search for.
     * @return A vector of students matching the search query.
     */
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

    /** 
     * @brief Finds and returns students with the lowest math score.
     * @return A vector of students with the lowest math score.
     * @throws std::runtime_error if no students are available.
     */
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

    /** 
     * @brief Converts a string to lowercase.
     * @param str The string to convert.
     * @return The lowercase version of the input string.
     */
    static std::string toLower(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });
        return result;
    }

    /** 
     * @brief Prints all student information to the console.
     */
    void printAllStudents() const {
        for (const auto& student : students) {
            std::cout << "Name: " << student.getFullName() << "\n";
            std::cout << "Math Score: " << student.getMathScore() 
                      << ", Literature Score: " << student.getLiteratureScore() 
                      << ", Foreign Language Score: " << student.getForeignLanguageScore() << "\n";
            std::cout << "Average Score: " << std::fixed << std::setprecision(2) 
                      << student.calculateAverageScore() << ", Classification: " 
                      << student.classifyStudent() << "\n\n";
        }
    }
};

/** 
 * @brief Helper function to input and validate student scores.
 * @return A valid score between 0 and 10.
 */
float getValidScore() {
    float score;
    while (true) {
        std::cin >> score;
        if (std::cin.fail()) { // Check if input is invalid
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input! Please enter a numeric value between 0 and 10: ";
        } else if (!Student::isValidScore(score)) {
            std::cout << "Score must be between 0 and 10. Please enter again: ";
        } else {
            return score;
        }
    }
}

/** 
 * @brief Inputs student information from the console.
 * @return A Student object containing the inputted information.
 */
Student inputStudent() {
    std::string name;
    float math, literature, language;

    // Input and validate full name
    do {
        std::cout << "Enter full name: ";
        std::getline(std::cin, name);
        if (!Student::isValidName(name)) {
            std::cout << "Invalid name! Name must contain only alphabetic characters and spaces.\n";
        }
    } while (!Student::isValidName(name));

    // Input and validate math score
    std::cout << "Enter math score (0-10): ";
    math = getValidScore();

    // Input and validate literature score
    std::cout << "Enter literature score (0-10): ";
    literature = getValidScore();

    // Input and validate foreign language score
    std::cout << "Enter foreign language score (0-10): ";
    language = getValidScore();

    std::cin.ignore();  // Clear newline from input buffer
    return Student(name, math, literature, language);
}

/** 
 * @brief The main function to execute the student management program.
 * It prompts the user for student data and displays various information about the students.
 * @return Exit status.
 */
int main() {
    int n;
    std::cout << "Enter number of students: ";
    std::cin >> n;
    std::cin.ignore();  // Clear newline from input buffer

    StudentManager manager;

    // Input student information
    for (int i = 0; i < n; ++i) {
        std::cout << "\nInput details for student " << i + 1 << ":\n";
        manager.addStudent(inputStudent());
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
    std::string query;
    std::cout << "\nEnter name to search: ";
    std::getline(std::cin, query);
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
