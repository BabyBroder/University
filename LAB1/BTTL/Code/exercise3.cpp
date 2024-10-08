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
 * @brief Adds two fractions and returns the result as a simplified fraction.
 * 
 * @param num1 Numerator of the first fraction.
 * @param den1 Denominator of the first fraction.
 * @param num2 Numerator of the second fraction.
 * @param den2 Denominator of the second fraction.
 * @param result_num Reference to store the resulting numerator.
 * @param result_den Reference to store the resulting denominator.
 */
void addFractions(int num1, int den1, int num2, int den2, int &result_num, int &result_den) {
    result_num = num1 * den2 + num2 * den1;
    result_den = den1 * den2;
    simplifyFraction(result_num, result_den, result_num, result_den);
}

/**
 * @brief Subtracts two fractions and returns the result as a simplified fraction.
 * 
 * @param num1 Numerator of the first fraction.
 * @param den1 Denominator of the first fraction.
 * @param num2 Numerator of the second fraction.
 * @param den2 Denominator of the second fraction.
 * @param result_num Reference to store the resulting numerator.
 * @param result_den Reference to store the resulting denominator.
 */
void subtractFractions(int num1, int den1, int num2, int den2, int &result_num, int &result_den) {
    result_num = num1 * den2 - num2 * den1;
    result_den = den1 * den2;
    simplifyFraction(result_num, result_den, result_num, result_den);
}

/**
 * @brief Multiplies two fractions and returns the result as a simplified fraction.
 * 
 * @param num1 Numerator of the first fraction.
 * @param den1 Denominator of the first fraction.
 * @param num2 Numerator of the second fraction.
 * @param den2 Denominator of the second fraction.
 * @param result_num Reference to store the resulting numerator.
 * @param result_den Reference to store the resulting denominator.
 */
void multiplyFractions(int num1, int den1, int num2, int den2, int &result_num, int &result_den) {
    result_num = num1 * num2;
    result_den = den1 * den2;
    simplifyFraction(result_num, result_den, result_num, result_den);
}

/**
 * @brief Divides two fractions and returns the result as a simplified fraction.
 * 
 * @param num1 Numerator of the first fraction.
 * @param den1 Denominator of the first fraction.
 * @param num2 Numerator of the second fraction.
 * @param den2 Denominator of the second fraction.
 * @param result_num Reference to store the resulting numerator.
 * @param result_den Reference to store the resulting denominator.
 * @throws std::invalid_argument if the numerator of the second fraction is zero.
 */
void divideFractions(int num1, int den1, int num2, int den2, int &result_num, int &result_den) {
    if (num2 == 0) {
        throw std::invalid_argument("Cannot divide by a fraction with a numerator of zero.");
    }
    result_num = num1 * den2;
    result_den = den1 * num2;
    simplifyFraction(result_num, result_den, result_num, result_den);
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

        // Input first fraction
        std::cout << "Enter numerator and denominator for the first fraction: ";
        std::cin >> num1 >> den1;

        // Simplify the first fraction
        int simp_num1, simp_den1;
        simplifyFraction(num1, den1, simp_num1, simp_den1);

        // Input second fraction
        std::cout << "Enter numerator and denominator for the second fraction: ";
        std::cin >> num2 >> den2;

        // Simplify the second fraction
        int simp_num2, simp_den2;
        simplifyFraction(num2, den2, simp_num2, simp_den2);

        /**
         * @brief Perform and print arithmetic operations on two fractions.
         * 
         * The main function creates two fractions based on user input and calculates
         * their sum, difference, product, and quotient. It then prints the results.
         */
        int result_num, result_den;

        addFractions(simp_num1, simp_den1, simp_num2, simp_den2, result_num, result_den);
        std::cout << "Sum: ";
        printFraction(result_num, result_den);
        std::cout << std::endl;

        subtractFractions(simp_num1, simp_den1, simp_num2, simp_den2, result_num, result_den);
        std::cout << "Difference: ";
        printFraction(result_num, result_den);
        std::cout << std::endl;

        multiplyFractions(simp_num1, simp_den1, simp_num2, simp_den2, result_num, result_den);
        std::cout << "Product: ";
        printFraction(result_num, result_den);
        std::cout << std::endl;

        divideFractions(simp_num1, simp_den1, simp_num2, simp_den2, result_num, result_den);
        std::cout << "Quotient: ";
        printFraction(result_num, result_den);
        std::cout << std::endl;

    } catch (const std::invalid_argument& e) {
        // Catch and display invalid_argument exceptions
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
