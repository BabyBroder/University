#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
#include <iomanip>  // For std::fixed and std::setprecision

/**
 * @class Student
 * @brief Represents a student with scores in multiple subjects.
 * 
 * The Student class encapsulates the data and functionality related to a student,
 * including their full name and scores in Math, Literature, and Foreign Language.
 */
class Student {
private:
    std::string fullName;                   ///< The student's full name.
    float mathScore;                         ///< The student's Math score.
    float literatureScore;                   ///< The student's Literature score.
    float foreignLanguageScore;              ///< The student's Foreign Language score.

public:
    /**
     * @brief Constructor to initialize a student.
     * 
     * This constructor initializes a student with a full name and scores in three subjects.
     * 
     * @param name The full name of the student.
     * @param math The Math score of the student.
     * @param literature The Literature score of the student.
     * @param language The Foreign Language score of the student.
     */
    Student(const std::string& name, float math, float literature, float language)
        : fullName(name), mathScore(math), literatureScore(literature), foreignLanguageScore(language) {}

    // Getter methods
    std::string getFullName() const;         ///< Returns the full name of the student.
    float getMathScore() const;               ///< Returns the Math score of the student.
    float getLiteratureScore() const;        ///< Returns the Literature score of the student.
    float getForeignLanguageScore() const;   ///< Returns the Foreign Language score of the student.

    /**
     * @brief Calculates the average score of the student.
     * 
     * The average is calculated with a weight of 2 for the Math score and 1 for
     * the other subjects.
     * 
     * @return The average score of the student.
     */
    float calculateAverageScore() const;

    /**
     * @brief Classifies the student based on the average score.
     * 
     * The classification can be "Excellent", "Good", "Fair", "Average", or "Weak".
     * 
     * @return A string representing the classification of the student.
     */
    std::string classifyStudent() const;

    /**
     * @brief Validates a student's name.
     * 
     * Checks if the name contains only alphabetic characters and spaces.
     * 
     * @param name The name to be validated.
     * @return True if the name is valid; false otherwise.
     */
    static bool isValidName(const std::string& name);

    /**
     * @brief Validates a student's score.
     * 
     * Checks if the score is between 0 and 10.
     * 
     * @param score The score to be validated.
     * @return True if the score is valid; false otherwise.
     */
    static bool isValidScore(float score);
};

/**
 * @class StudentManager
 * @brief Manages a collection of students.
 * 
 * The StudentManager class provides functionality to add students, find the top
 * student, search for students by name, and find students with the lowest Math score.
 */
class StudentManager {
private:
    std::vector<Student> students;  ///< A collection of students.

public:
    /**
     * @brief Adds a student to the collection.
     * 
     * This method adds a Student object to the internal collection.
     * 
     * @param student The Student object to be added.
     */
    void addStudent(const Student& student);

    /**
     * @brief Finds the student with the highest average score.
     * 
     * This method searches through the collection of students and returns the one 
     * with the highest average score.
     * 
     * @return The Student object with the highest average score.
     * @throws std::runtime_error if no students are available.
     */
    Student findTopStudent() const;

    /**
     * @brief Searches for students by (partial) name.
     * 
     * This method searches for students whose names contain the specified query, 
     * case insensitive.
     * 
     * @param query The name or part of the name to search for.
     * @return A vector of Student objects matching the search criteria.
     */
    std::vector<Student> searchStudentsByName(const std::string& query) const;

    /**
     * @brief Finds students with the lowest Math score.
     * 
     * This method searches through the collection of students and returns those
     * with the lowest Math score.
     * 
     * @return A vector of Student objects with the lowest Math score.
     * @throws std::runtime_error if no students are available.
     */
    std::vector<Student> findLowestMathScoreStudents() const;

    /**
     * @brief Converts a string to lowercase.
     * 
     * This helper function is used for case insensitive comparisons.
     * 
     * @param str The string to convert.
     * @return The lowercase version of the input string.
     */
    static std::string toLower(const std::string& str);

    /**
     * @brief Prints all student information.
     * 
     * This method outputs the details of all students in the collection, 
     * including their scores and classifications.
     */
    void printAllStudents() const;
};

/**
 * @brief Prompts the user for a valid score input.
 * 
 * This function ensures that the user enters a numeric value between 0 and 10.
 * 
 * @return A valid score as a float.
 */
float getValidScore();

/**
 * @brief Prompts the user to input student information.
 * 
 * This function gathers the full name and scores for a student, ensuring 
 * valid input is provided.
 * 
 * @return A Student object initialized with the inputted data.
 */
Student inputStudent();

/**
 * @brief Main function to run the student management system.
 * 
 * This function handles user input, manages student records, and displays results
 * including the top student and search results based on names.
 * 
 * @return An integer indicating the exit status of the program.
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
