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
    try {
        int num1, den1, num2, den2;
        int simp_num1, simp_den1, simp_num2, simp_den2;

        // Input first fraction
        std::cout << "Enter numerator and denominator for the first fraction: ";
        std::cin >> num1 >> den1;
        simplifyFraction(num1, den1, simp_num1, simp_den1);

        // Input second fraction
        std::cout << "Enter numerator and denominator for the second fraction: ";
        std::cin >> num2 >> den2;
        simplifyFraction(num2, den2, simp_num2, simp_den2);

        // Compare the two fractions and print the larger one
        if (isGreaterThan(simp_num1, simp_den1, simp_num2, simp_den2)) {
            std::cout << "The larger fraction is: ";
            printFraction(simp_num1, simp_den1);
            std::cout << std::endl;
        } else if (isLessThan(simp_num1, simp_den1, simp_num2, simp_den2)) {
            std::cout << "The larger fraction is: ";
            printFraction(simp_num2, simp_den2);
            std::cout << std::endl;
        } else {
            std::cout << "Both fractions are equal." << std::endl;
        }
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
