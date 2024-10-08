#include <iostream>
#include <numeric>
#include <vector>
#include <stdexcept>
#include <sstream>

/**
 * @brief Simplifies a fraction using the greatest common divisor (GCD).
 * 
 * This function reduces a fraction to its simplest form using the GCD.
 * It also ensures the denominator is positive by moving any negative sign
 * to the numerator.
 * 
 * @param num The numerator of the fraction.
 * @param den The denominator of the fraction.
 * @param simp_num Reference to store the simplified numerator.
 * @param simp_den Reference to store the simplified denominator.
 * @throws std::invalid_argument if the denominator is zero.
 */
void simplifyFraction(int num, int den, int& simp_num, int& simp_den) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }

    int gcd = std::gcd(num, den);
    simp_num = num / gcd;
    simp_den = den / gcd;

    // Ensure the denominator is positive
    if (simp_den < 0) {
        simp_num = -simp_num;
        simp_den = -simp_den;
    }
}

/**
 * @brief Converts a simplified fraction to a string.
 * 
 * If the fraction represents a whole number (denominator == 1), 
 * it returns only the numerator as a string. Otherwise, it returns
 * the fraction in "numerator/denominator" format.
 * 
 * @param num The simplified numerator.
 * @param den The simplified denominator.
 * @return std::string The fraction or whole number in string format.
 */
std::string fractionToString(int num, int den) {
    std::ostringstream os;
    if (den == 1) {
        os << num;  // Whole number if denominator is 1
    } else {
        os << num << "/" << den;  // Fraction format
    }
    return os.str();
}

/**
 * @brief Function to run test cases and print the results.
 * 
 * This function takes a vector of test cases where each test case is a pair of 
 * numerator and denominator. It simplifies the fraction, handles zero-denominator 
 * cases, and prints the results.
 * 
 * @param testCases A vector of test cases (numerator, denominator).
 */
void runTestCases(const std::vector<std::pair<int, int>>& testCases) {
    for (const auto& testCase : testCases) {
        int numerator = testCase.first;
        int denominator = testCase.second;
        
        try {
            int simplifiedNumerator, simplifiedDenominator;
            simplifyFraction(numerator, denominator, simplifiedNumerator, simplifiedDenominator);
            std::cout << "Input: (" << numerator << ", " << denominator << ") => "
                      << "Simplified fraction: " << fractionToString(simplifiedNumerator, simplifiedDenominator) << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Input: (" << numerator << ", " << denominator << ") => "
                      << e.what() << std::endl;
        }
    }
}

int main() {
    // Test cases: (numerator, denominator)
    std::vector<std::pair<int, int>> testCases = {
        {4, 8}, {10, 5}, {-3, 9}, {0, 5}, {5, 0},
        {-4, -8}, {1, 3}, {7, -14}, {15, 45}, {20, 100},
        {-18, 24}, {8, 12}, {5, 1}, {-5, -1}, {2, 6},
        {9, 27}, {2, -4}, {-16, 32}, {100, -250}, {12, 8}
    };

    runTestCases(testCases);

    return 0;
}
