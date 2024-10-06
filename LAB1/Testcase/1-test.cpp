#include <iostream>
#include <numeric>
#include <vector>
#include <stdexcept>
#include <sstream>

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

// Function to run test cases
void runTestCases(const std::vector<std::pair<int, int>>& testCases) {
    for (const auto& testCase : testCases) {
        int numerator = testCase.first;
        int denominator = testCase.second;
        
        try {
            Fraction fraction(numerator, denominator);
            std::cout << "Input: (" << numerator << ", " << denominator << ") => "
                      << "Simplified fraction: " << fraction << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Input: (" << numerator << ", " << denominator << ") => "
                      << e.what() << std::endl;
        }
    }
}

int main() {
    // Test cases: (numerator, denominator)
    std::vector<std::pair<int, int>> testCases = {
        {4, 8}, {10, 5}, {-3, 9}, {0, 5}, {5, 0},
        {-4, -8}, {1, 3}, {7, -14}, {15, 45}, {20, 100},
        {-18, 24}, {8, 12}, {5, 1}, {-5, -1}, {2, 6},
        {9, 27}, {2, -4}, {-16, 32}, {100, -250}, {12, 8}
    };

    runTestCases(testCases);

    return 0;
}
