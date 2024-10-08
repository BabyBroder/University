#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

// Function to simplify a fraction using GCD
void simplifyFraction(int &numerator, int &denominator) {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    // Ensure that the denominator is positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Function to add two fractions (represented as numerator and denominator pairs)
void addFractions(int num1, int den1, int num2, int den2, int &result_num, int &result_den) {
    result_num = num1 * den2 + num2 * den1;
    result_den = den1 * den2;
    simplifyFraction(result_num, result_den);
}

// Function to subtract two fractions
void subtractFractions(int num1, int den1, int num2, int den2, int &result_num, int &result_den) {
    result_num = num1 * den2 - num2 * den1;
    result_den = den1 * den2;
    simplifyFraction(result_num, result_den);
}

// Function to multiply two fractions
void multiplyFractions(int num1, int den1, int num2, int den2, int &result_num, int &result_den) {
    result_num = num1 * num2;
    result_den = den1 * den2;
    simplifyFraction(result_num, result_den);
}

// Function to divide two fractions
void divideFractions(int num1, int den1, int num2, int den2, int &result_num, int &result_den) {
    if (num2 == 0) {
        throw std::invalid_argument("Cannot divide by a fraction with a numerator of zero.");
    }
    result_num = num1 * den2;
    result_den = den1 * num2;
    simplifyFraction(result_num, result_den);
}

// Function to print a fraction
void printFraction(int numerator, int denominator) {
    if (denominator == 1) {
        std::cout << numerator;  // Display whole number if denominator is 1
    } else {
        std::cout << numerator << "/" << denominator;
    }
}

int main() {
    // Test cases: Numerator1, Denominator1, Numerator2, Denominator2
    std::vector<std::vector<int>> testCases = {
        {1, 2, 1, 3}, {-1, 2, 1, 3}, {1, 4, 1, 4}, {5, 7, 3, 7}, {0, 3, 4, 5},
        {-3, 4, -2, 3}, {7, 8, 9, 10}, {9, 9, 3, 6}, {8, 11, 5, 9}, {2, 5, 4, 7},
        {-5, 6, 2, 3}, {3, 5, 4, 5}, {4, 7, 1, 3}, {6, 11, 2, 5}, {-7, 8, -3, 4},
        {1, 2, 1, 6}, {2, 9, 5, 6}, {5, 12, 7, 9}, {8, 15, 3, 5}, {7, 16, 5, 8}
    };

    // Loop through each test case and calculate the sum, difference, product, and quotient
    for (size_t i = 0; i < testCases.size(); ++i) {
        int num1 = testCases[i][0];
        int den1 = testCases[i][1];
        int num2 = testCases[i][2];
        int den2 = testCases[i][3];

        try {
            simplifyFraction(num1, den1);
            simplifyFraction(num2, den2);

            int sum_num, sum_den;
            int diff_num, diff_den;
            int prod_num, prod_den;
            int quot_num, quot_den;

            addFractions(num1, den1, num2, den2, sum_num, sum_den);
            subtractFractions(num1, den1, num2, den2, diff_num, diff_den);
            multiplyFractions(num1, den1, num2, den2, prod_num, prod_den);
            divideFractions(num1, den1, num2, den2, quot_num, quot_den);

            std::cout << "  Fraction 1: "; printFraction(num1, den1); std::cout << "\n";
            std::cout << "  Fraction 2: "; printFraction(num2, den2); std::cout << "\n";
            std::cout << "  Sum: "; printFraction(sum_num, sum_den); std::cout << "\n";
            std::cout << "  Difference: "; printFraction(diff_num, diff_den); std::cout << "\n";
            std::cout << "  Product: "; printFraction(prod_num, prod_den); std::cout << "\n";
            std::cout << "  Quotient: "; printFraction(quot_num, quot_den); std::cout << "\n";
            std::cout << "-----------------------------\n";
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error in Test Case " << i+1 << ": " << e.what() << std::endl;
        }
    }

    return 0;
}
