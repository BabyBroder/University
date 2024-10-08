#include <iostream>
#include <numeric> // For std::gcd in C++17 and above

/**
 * @brief Simplifies a fraction using the greatest common divisor (GCD).
 * 
 * This function reduces a fraction to its simplest form using the GCD. 
 * It ensures the denominator is positive by moving any negative sign to the numerator.
 * 
 * @param num The numerator of the fraction.
 * @param den The denominator of the fraction.
 * @param simp_num A reference to store the simplified numerator.
 * @param simp_den A reference to store the simplified denominator.
 */
void simplifyFraction(int num, int den, int& simp_num, int& simp_den) {
    int gcd = std::gcd(num, den);
    simp_num = num / gcd;
    simp_den = den / gcd;

    // Ensure that the denominator is positive
    if (simp_den < 0) {
        simp_num = -simp_num;
        simp_den = -simp_den;
    }
}

/**
 * @brief Prints a fraction in a simplified form.
 * 
 * This function prints a fraction. If the denominator is 1, it prints just the numerator.
 * Otherwise, it prints the fraction in "numerator/denominator" form.
 * 
 * @param num The simplified numerator of the fraction.
 * @param den The simplified denominator of the fraction.
 */
void printFraction(int num, int den) {
    if (den == 1) {
        std::cout << num;  // Display whole number if denominator is 1
    } else {
        std::cout << num << "/" << den;  // Display as fraction
    }
}

int main() {
    int numerator, denominator;
    
    // Input for numerator and denominator from user
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;
    
    std::cout << "Enter the denominator: ";
    std::cin >> denominator;

    // Check if the denominator is zero
    if (denominator == 0) {
        std::cerr << "Denominator cannot be zero." << std::endl;
        return 1; // Return with error code
    }

    int simplifiedNumerator, simplifiedDenominator;

    /**
     * @brief Simplify the fraction and print its simplified form.
     * 
     * The program simplifies the user-input fraction using the GCD 
     * and then prints the simplified fraction.
     */
    simplifyFraction(numerator, denominator, simplifiedNumerator, simplifiedDenominator);

    // Output the simplified fraction
    std::cout << "Simplified fraction: ";
    printFraction(simplifiedNumerator, simplifiedDenominator);
    std::cout << std::endl;

    return 0;
}
