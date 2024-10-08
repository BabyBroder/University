#include <iostream>
#include <cmath>  // For M_PI and fabs

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Normalize x to the range [-π, π] to avoid large values
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

// Function to calculate sin(x) using Taylor series with given accuracy
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

// Function to compare the calculated result with the expected value
bool compareResults(double calculated, double expected, double tolerance = 0.0001) {
    return fabs(calculated - expected) < tolerance;
}

int main() {
    // Define the 20 test cases with inputs and expected outputs
    struct TestCase {
        double x;
        double expected;
    };

    TestCase testCases[20] = {
        {0.0, 0.00000},
        {M_PI / 6, 0.50000},
        {M_PI / 4, 0.70711},
        {M_PI / 3, 0.86603},
        {M_PI / 2, 1.00000},
        {2 * M_PI / 3, 0.86603},
        {3 * M_PI / 4, 0.70711},
        {5 * M_PI / 6, 0.50000},
        {M_PI, 0.00000},
        {3 * M_PI / 2, -1.00000},
        {2 * M_PI, 0.00000},
        {-M_PI / 6, -0.50000},
        {-M_PI / 4, -0.70711},
        {-M_PI / 3, -0.86603},
        {-M_PI / 2, -1.00000},
        {-2 * M_PI / 3, -0.86603},
        {-3 * M_PI / 4, -0.70711},
        {-5 * M_PI / 6, -0.50000},
        {-M_PI, 0.00000},
        {-3 * M_PI / 2, 1.00000}
    };

    // Loop over test cases and run the test
    for (int i = 0; i < 20; ++i) {
        double x = testCases[i].x;
        double expected = testCases[i].expected;
        double result = calculateSin(x);

        // Check if the calculated result matches the expected result
        if (compareResults(result, expected)) {
            std::cout << "Test Case " << (i + 1) << " Passed: sin(" << x << ") = " << result << std::endl;
        } else {
            std::cout << "Test Case " << (i + 1) << " Failed: Expected " << expected << ", but got " << result << std::endl;
        }
    }

    return 0;
}
