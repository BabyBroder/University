#include <iostream>
#include <numeric> // For std::gcd in C++17 and above
#include <stdexcept>

/**
 * @brief Simplifies a fraction using the greatest common divisor (GCD).
 * 
 * This function reduces a fraction to its simplest form using GCD.
 * It also ensures that the denominator is positive by moving any negative sign
 * to the numerator.
 * 
 * @param num Numerator of the fraction.
 * @param den Denominator of the fraction.
 * @param simp_num Reference to store the simplified numerator.
 * @param simp_den Reference to store the simplified denominator.
 * @throws std::invalid_argument if the denominator is zero.
 */
void simplifyFraction(int num, int den, int &simp_num, int &simp_den) {
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
 * @brief Compares two fractions to see if the first is greater than the second.
 * 
 * @param num1 Numerator of the first fraction.
 * @param den1 Denominator of the first fraction.
 * @param num2 Numerator of the second fraction.
 * @param den2 Denominator of the second fraction.
 * @return true if the first fraction is greater than the second.
 * @return false otherwise.
 */
bool isGreaterThan(int num1, int den1, int num2, int den2) {
    return num1 * den2 > num2 * den1;
}

/**
 * @brief Compares two fractions to see if the first is less than the second.
 * 
 * @param num1 Numerator of the first fraction.
 * @param den1 Denominator of the first fraction.
 * @param num2 Numerator of the second fraction.
 * @param den2 Denominator of the second fraction.
 * @return true if the first fraction is less than the second.
 * @return false otherwise.
 */
bool isLessThan(int num1, int den1, int num2, int den2) {
    return num1 * den2 < num2 * den1;
}

/**
 * @brief Compares two fractions to check if they are equal.
 * 
 * @param num1 Numerator of the first fraction.
 * @param den1 Denominator of the first fraction.
 * @param num2 Numerator of the second fraction.
 * @param den2 Denominator of the second fraction.
 * @return true if the fractions are equal.
 * @return false otherwise.
 */
bool isEqual(int num1, int den1, int num2, int den2) {
    return num1 * den2 == num2 * den1;
}

/**
 * @brief Outputs a fraction in string form.
 * 
 * If the fraction is a whole number (denominator == 1), only the numerator is printed.
 * Otherwise, it prints the fraction as "numerator/denominator".
 * 
 * @param num The numerator of the fraction.
 * @param den The denominator of the fraction.
 */
void printFraction(int num, int den) {
    if (den == 1) {
        std::cout << num;  // Display whole number if denominator is 1
    } else {
        std::cout << num << "/" << den;  // Fraction format
    }
}

int main() {
    // Test cases as tuples of (numerator1, denominator1, numerator2, denominator2)
    int testCases[20][4] = {
        {1, 2, 1, 3},
        {3, 4, 2, 5},
        {5, 6, 5, 6},
        {7, 8, 3, 4},
        {1, 2, 3, 4},
        {0, 1, 1, 2},
        {4, 1, 2, 1},
        {1, -2, -1, 2},
        {-1, 3, 1, 3},
        {5, 10, 2, 5},
        {10, 2, 5, 1},
        {-4, 6, 4, -6},
        {3, 9, 1, 3},
        {3, 7, 2, 5},
        {2, -4, -1, 2},
        {8, 12, 2, 3},
        {5, 3, 4, 3},
        {1, 1, 0, 1},
        {6, 9, 2, 3},
        {1, 5, 3, 10}
    };

    // Running test cases
    for (int i = 0; i < 20; i++) {
        try {
            int num1, den1, num2, den2;
            simplifyFraction(testCases[i][0], testCases[i][1], num1, den1);
            simplifyFraction(testCases[i][2], testCases[i][3], num2, den2);

            if (isGreaterThan(num1, den1, num2, den2)) {
                std::cout << "Larger fraction is: ";
                printFraction(num1, den1);
                std::cout << std::endl;
            } else if (isLessThan(num1, den1, num2, den2)) {
                std::cout << "Larger fraction is: ";
                printFraction(num2, den2);
                std::cout << std::endl;
            } else {
                std::cout << "Both fractions are equal." << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr  << e.what() << std::endl;
        }
    }

    return 0;
}
