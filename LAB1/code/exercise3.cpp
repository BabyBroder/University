#include <iostream>
#include <numeric> // For std::gcd in C++17 and above

/**
 * @class Fraction
 * @brief A class to represent and operate on fractions.
 * 
 * The `Fraction` class supports creating, simplifying, and performing arithmetic operations 
 * on fractions, including addition, subtraction, multiplication, and division.
 */
class Fraction {
private:
    int numerator;   ///< Numerator of the fraction
    int denominator; ///< Denominator of the fraction

public:
    /**
     * @brief Constructor to initialize the Fraction object.
     * 
     * This constructor initializes the fraction with a numerator and denominator, simplifies 
     * the fraction, and checks for a zero denominator. If the denominator is zero, 
     * an `std::invalid_argument` exception is thrown.
     * 
     * @param num Numerator of the fraction (default: 0).
     * @param den Denominator of the fraction (default: 1).
     * @throws std::invalid_argument if the denominator is zero.
     */
    Fraction(int num = 0, int den = 1) {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        numerator = num;
        denominator = den;
        simplify();
    }

    /**
     * @brief Simplifies the fraction using the greatest common divisor (GCD).
     * 
     * This function uses `std::gcd` to reduce the fraction to its simplest form. 
     * It also ensures that the denominator is positive by moving any negative sign to the numerator.
     */
    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // Ensure that the denominator is positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    /**
     * @brief Overload the "+" operator to add two fractions.
     * 
     * This operator performs fraction addition by cross-multiplying and returning the result 
     * as a simplified fraction.
     * 
     * @param other The fraction to be added.
     * @return Fraction The resulting fraction after addition.
     */
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den); // Return the result as a new simplified fraction
    }

    /**
     * @brief Overload the "-" operator to subtract two fractions.
     * 
     * This operator performs fraction subtraction by cross-multiplying and returning the result 
     * as a simplified fraction.
     * 
     * @param other The fraction to be subtracted.
     * @return Fraction The resulting fraction after subtraction.
     */
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den); // Return the result as a new simplified fraction
    }

    /**
     * @brief Overload the "*" operator to multiply two fractions.
     * 
     * This operator multiplies two fractions by multiplying their numerators and denominators,
     * returning the result as a simplified fraction.
     * 
     * @param other The fraction to be multiplied.
     * @return Fraction The resulting fraction after multiplication.
     */
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den); // Return the result as a new simplified fraction
    }

    /**
     * @brief Overload the "/" operator to divide two fractions.
     * 
     * This operator divides the current fraction by another fraction by multiplying with the 
     * reciprocal of the second fraction. It throws an exception if division by zero occurs.
     * 
     * @param other The fraction to divide by.
     * @throws std::invalid_argument if the numerator of the second fraction is zero.
     * @return Fraction The resulting fraction after division.
     */
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by a fraction with a numerator of zero.");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den); // Return the result as a new simplified fraction
    }

    /**
     * @brief Overload the stream insertion operator to print the fraction.
     * 
     * This allows the fraction to be printed using the `<<` operator. If the fraction 
     * simplifies to a whole number (denominator == 1), only the numerator is printed. 
     * Otherwise, the fraction is printed in the format "numerator/denominator".
     * 
     * @param os The output stream.
     * @param fraction The fraction to be printed.
     * @return std::ostream& The output stream after inserting the fraction.
     */
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
    try {
        int num1, den1, num2, den2;

        // Input first fraction
        std::cout << "Enter numerator and denominator for the first fraction: ";
        std::cin >> num1 >> den1;
        Fraction fraction1(num1, den1);

        // Input second fraction
        std::cout << "Enter numerator and denominator for the second fraction: ";
        std::cin >> num2 >> den2;
        Fraction fraction2(num2, den2);

        /**
         * @brief Perform and print arithmetic operations on two fractions.
         * 
         * The main function creates two fractions based on user input and calculates
         * their sum, difference, product, and quotient. It then prints the results.
         */
        Fraction sum = fraction1 + fraction2;
        Fraction difference = fraction1 - fraction2;
        Fraction product = fraction1 * fraction2;
        Fraction quotient = fraction1 / fraction2;

        std::cout << "Sum: " << sum << std::endl;
        std::cout << "Difference: " << difference << std::endl;
        std::cout << "Product: " << product << std::endl;
        std::cout << "Quotient: " << quotient << std::endl;

    } catch (const std::invalid_argument& e) {
        // Catch and display invalid_argument exceptions
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
