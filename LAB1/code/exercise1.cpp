#include <iostream>
#include <numeric> // For std::gcd in C++17 and above

/**
 * @class Fraction
 * @brief A class to represent and simplify fractions.
 * 
 * The `Fraction` class represents a mathematical fraction with a numerator and a denominator.
 * The class provides a method to simplify the fraction using the greatest common divisor (GCD),
 * and overloads the stream insertion operator (`<<`) to print the fraction in a user-friendly format.
 */
class Fraction {
private:
    int numerator;   ///< Numerator of the fraction
    int denominator; ///< Denominator of the fraction

public:
    /**
     * @brief Constructor to initialize the Fraction object.
     * 
     * This constructor takes a numerator and a denominator as input, 
     * simplifies the fraction, and ensures that the denominator is non-zero.
     * If the denominator is zero, an `std::invalid_argument` exception is thrown.
     * 
     * @param num Numerator of the fraction.
     * @param den Denominator of the fraction.
     * @throws std::invalid_argument if the denominator is zero.
     */
    Fraction(int num, int den) {
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
     * This function uses the `std::gcd` function to reduce the fraction to its simplest form.
     * It also ensures that the denominator is positive by moving any negative sign 
     * to the numerator.
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
     * @brief Overloads the stream insertion operator to output the fraction.
     * 
     * This allows the fraction to be printed using `<<` operator. If the fraction 
     * simplifies to a whole number (denominator == 1), only the numerator is printed.
     * Otherwise, the fraction is printed in the format "numerator/denominator".
     * 
     * @param os The output stream.
     * @param fraction The Fraction object to be printed.
     * @return std::ostream& The output stream with the fraction inserted.
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
    int numerator, denominator;
    
    // Input for numerator and denominator from user
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;
    
    std::cout << "Enter the denominator: ";
    std::cin >> denominator;

    try {
        /**
         * @brief Create a Fraction object and print its simplified form.
         * 
         * The program takes user input for the numerator and denominator, creates a Fraction object,
         * simplifies the fraction, and outputs it. If the denominator is zero, an exception is caught 
         * and an error message is printed.
         */
        Fraction fraction(numerator, denominator);

        // Output the simplified fraction
        std::cout << "Simplified fraction: " << fraction << std::endl;
    } catch (const std::invalid_argument& e) {
        // Catch and display any invalid_argument exception (denominator = 0)
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
