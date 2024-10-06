#include <iostream>
#include <cmath>  // For pow and fabs

/**
 * @class SinCalculator
 * @brief A class to calculate the sine of an angle using the Taylor series approximation.
 * 
 * This class provides a method to compute the sine of a given angle (in radians) using the 
 * Taylor series expansion. It includes a method to normalize the angle to the range [-π, π] 
 * to improve precision and efficiency.
 */
class SinCalculator {
private:
    /**
     * @brief Calculate the factorial of a given number.
     * 
     * This function computes the factorial of an integer `n` by multiplying all integers 
     * from 1 to `n`.
     * 
     * @param n The integer whose factorial is to be calculated.
     * @return long long The factorial of the input number `n`.
     */
    long long factorial(int n) {
        long long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

public:
    /**
     * @brief Normalize an angle to the range [-π, π].
     * 
     * This method normalizes the input angle `x` by reducing it modulo 2π, and adjusts 
     * the result to ensure it falls within the range [-π, π]. This helps to improve 
     * the accuracy of the sine approximation for large input values.
     * 
     * @param x The angle in radians to be normalized.
     * @return double The normalized angle within the range [-π, π].
     */
    double normalize(double x) {
        const double two_pi = 2 * M_PI;
        x = fmod(x, two_pi); // Reduce x modulo 2π
        if (x > M_PI) {
            x -= two_pi;  // Adjust to be in the range [-π, π]
        } else if (x < -M_PI) {
            x += two_pi;
        }
        return x;
    }

    /**
     * @brief Calculate the sine of an angle using the Taylor series approximation.
     * 
     * This function computes sin(x) by summing terms of the Taylor series expansion 
     * for sine. It continues adding terms until the magnitude of the next term is 
     * smaller than the specified accuracy. The input angle is first normalized to 
     * the range [-π, π] to improve precision.
     * 
     * @param x The angle in radians for which sine is to be calculated.
     * @param accuracy The accuracy threshold for the Taylor series approximation (default: 0.00001).
     * @return double The sine of the input angle `x` approximated using the Taylor series.
     */
    double calculateSin(double x, double accuracy = 0.00001) {
        x = normalize(x);  // Normalize the input angle
        double term = x;   // First term is x
        double sum = term; // Initialize sum with the first term
        int n = 1;

        // Continue adding terms until the next term is smaller than the given accuracy
        while (fabs(term) >= accuracy) {
            term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
            sum += term;
            n++;
        }

        return sum;
    }
};

int main() {
    SinCalculator sinCalc;  // Create an instance of SinCalculator
    double x;

    /**
     * @brief Main function to calculate and display the sine of a user-provided angle.
     * 
     * This function prompts the user for an angle in radians, then calculates the sine 
     * of the angle using the `SinCalculator` class, and finally outputs the result.
     */
    std::cout << "Enter the value of x (in radians): ";
    std::cin >> x;

    // Calculate sin(x) with the specified accuracy
    double result = sinCalc.calculateSin(x);

    // Output the result
    std::cout << "sin(" << x << ") = " << result << std::endl;

    return 0;
}
