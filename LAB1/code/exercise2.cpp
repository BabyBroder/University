#include <iostream>
#include <numeric> // For std::gcd in C++17 and above

class Fraction {
private:
    int numerator;   ///< Numerator of the fraction
    int denominator; ///< Denominator of the fraction

public:
    /**
     * @brief Constructor to initialize the Fraction object.
     * 
     * This constructor takes a numerator and a denominator as inputs. 
     * If the denominator is zero, an `std::invalid_argument` exception is thrown.
     * The fraction is automatically simplified upon initialization.
     * 
     * @param num Numerator of the fraction (default: 0)
     * @param den Denominator of the fraction (default: 1)
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
     * @brief Overload of the ">" operator to compare two fractions.
     * 
     * This operator compares two fractions by cross-multiplying to avoid precision errors
     * that may occur with floating-point division.
     * 
     * @param other Another Fraction object to compare with.
     * @return true if the current fraction is greater than the other fraction.
     * @return false otherwise.
     */
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    /**
     * @brief Overload of the "<" operator to compare two fractions.
     * 
     * Similar to the ">" operator, this compares two fractions by cross-multiplying.
     * 
     * @param other Another Fraction object to compare with.
     * @return true if the current fraction is less than the other fraction.
     * @return false otherwise.
     */
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    /**
     * @brief Overload of the "==" operator to check equality between two fractions.
     * 
     * This operator compares two fractions by checking if their cross-products are equal.
     * 
     * @param other Another Fraction object to compare with.
     * @return true if the two fractions are equal.
     * @return false otherwise.
     */
    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    /**
     * @brief Overload of the stream insertion operator to print the fraction.
     * 
     * This allows a Fraction object to be printed using the `<<` operator.
     * If the fraction simplifies to a whole number (denominator == 1), it prints only the numerator.
     * Otherwise, it prints the fraction in the form "numerator/denominator".
     * 
     * @param os The output stream.
     * @param fraction The Fraction object to be printed.
     * @return The output stream after inserting the fraction.
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

        // Compare the two fractions and print the larger one
        if (fraction1 > fraction2) {
            std::cout << "The larger fraction is: " << fraction1 << std::endl;
        } else if (fraction1 < fraction2) {
            std::cout << "The larger fraction is: " << fraction2 << std::endl;
        } else {
            std::cout << "Both fractions are equal." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
