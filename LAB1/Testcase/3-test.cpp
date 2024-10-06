#include <iostream>
#include <numeric> // For std::gcd in C++17 and above
#include <vector>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int num = 0, int den = 1) {
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

    // Overload the "+" operator for fraction addition
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den); // Return the result as a new simplified fraction
    }

    // Overload the "-" operator for fraction subtraction
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den); // Return the result as a new simplified fraction
    }

    // Overload the "*" operator for fraction multiplication
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den); // Return the result as a new simplified fraction
    }

    // Overload the "/" operator for fraction division
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by a fraction with a numerator of zero.");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den); // Return the result as a new simplified fraction
    }

    // Overload the stream insertion operator to print the fraction
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
            Fraction fraction1(num1, den1);
            Fraction fraction2(num2, den2);

            Fraction sum = fraction1 + fraction2;
            Fraction difference = fraction1 - fraction2;
            Fraction product = fraction1 * fraction2;
            Fraction quotient = fraction1 / fraction2;

            std::cout << "  Fraction 1: " << fraction1 << "\n";
            std::cout << "  Fraction 2: " << fraction2 << "\n";
            std::cout << "  Sum: " << sum << "\n";
            std::cout << "  Difference: " << difference << "\n";
            std::cout << "  Product: " << product << "\n";
            std::cout << "  Quotient: " << quotient << "\n";
            std::cout << "-----------------------------\n";
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error in Test Case " << i+1 << ": " << e.what() << std::endl;
        }
    }

    return 0;
}
