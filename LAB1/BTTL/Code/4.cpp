#include <iostream>
#include <cmath>  // For pow and fabs

// Function to calculate the factorial of a given number
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to normalize an angle to the range [-π, π]
double normalize(double x) {
    const double two_pi = 2 * M_PI;
    x = fmod(x, two_pi);  // Reduce x modulo 2π
    if (x > M_PI) {
        x -= two_pi;  // Adjust to be in the range [-π, π]
    } else if (x < -M_PI) {
        x += two_pi;
    }
    return x;
}

// Function to calculate the sine of an angle using the Taylor series approximation
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

int main() {
    double x;

    // Main function to calculate and display the sine of a user-provided angle
    std::cout << "Enter the value of x (in radians): ";
    std::cin >> x;

    // Calculate sin(x) with the specified accuracy
    double result = calculateSin(x);

    // Output the result
    std::cout << "sin(" << x << ") = " << result << std::endl;

    return 0;
}
