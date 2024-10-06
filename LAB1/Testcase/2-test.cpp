#include <iostream>
#include <numeric> // For std::gcd in C++17 and above
#include <stdexcept>

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

    // Overload the ">" operator to compare fractions
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    // Overload the "<" operator to compare fractions
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    // Overload the "==" operator to check equality of fractions
    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
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
            Fraction fraction1(testCases[i][0], testCases[i][1]);
            Fraction fraction2(testCases[i][2], testCases[i][3]);

            if (fraction1 > fraction2) {
                std::cout << "Larger fraction is: " << fraction1 << std::endl;
            } else if (fraction1 < fraction2) {
                std::cout << "Larger fraction is: " << fraction2 << std::endl;
            } else {
                std::cout << "Both fractions are equal." << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr  << e.what() << std::endl;
        }
    }

    return 0;
}
