/**
 * @file FractionSimplifier.cpp
 * @brief A C++ program to create, simplify, and display fractions using class-based design.
 * 
 * This program defines a `Fraction` class that represents a mathematical fraction.
 * The class includes methods to simplify the fraction using the greatest common divisor (GCD),
 * and overloads the `<<` operator for easy output. The program allows the user to input 
 * the numerator and denominator of a fraction, simplifies the fraction, and then outputs it.
 * 
 * Key functionalities:
 * - Constructor to initialize the fraction and ensure the denominator is non-zero.
 * - Simplification of the fraction using the GCD from the standard library.
 * - Adjustment to ensure that the denominator is always positive.
 * - Overloading of the stream insertion operator for easy printing of fractions.
 * 
 * Exception Handling:
 * - Throws an `std::invalid_argument` if the denominator is zero.
 * 
 * Example:
 * Input: 
 *   numerator = 4, denominator = 8
 * Output: 
 *   Simplified fraction: 1/2
 * 
 * @note This code requires C++17 or later for `std::gcd`.
 * 
 * @author Đoàn Đức Anh
 * @date October 2024
 */

#include <iostream>
#include <numeric> // For std::gcd in C++17 and above

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int num, int den) {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        numerator = num;
        denominator = den;
        simplify();
    }

    // Function to simplify the fraction using the GCD
    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // If denominator is negative, move the sign to the numerator
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Overloading the stream insertion operator to print the fraction
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        if (fraction.denominator == 1) {
            os << fraction.numerator;  // Display whole number if denominator is 1
        } else {
            os << fraction.numerator << "/" << fraction.denominator;
        }
        return os;
    }
};

int main() {
    int numerator, denominator;
    
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;
    
    std::cout << "Enter the denominator: ";
    std::cin >> denominator;

    try {
        // Create a Fraction object
        Fraction fraction(numerator, denominator);

        // Output the simplified fraction
        std::cout << "Simplified fraction: " << fraction << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
