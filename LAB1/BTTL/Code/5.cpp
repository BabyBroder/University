#include <iostream>
#include <cstdlib>  // For exit()

// Array to store the number of days in each month
const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to check if a given year is a leap year
bool isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Function to get the number of days in a given month and year
int daysInThisMonth(int m, int y) {
    if (m == 2 && isLeapYear(y)) {
        return 29;  // February in a leap year
    }
    return daysInMonth[m - 1];
}

// Function to check if a given date is valid
bool isValidDate(int d, int m, int y) {
    if (y < 1 || m < 1 || m > 12 || d < 1) {
        return false; // Invalid year, month, or day
    }
    if (d > daysInThisMonth(m, y)) {
        return false; // Day exceeds the number of days in the given month
    }
    return true;
}

// Function to calculate and return the next date
void nextDate(int &day, int &month, int &year) {
    int nextDay = day + 1;
    int nextMonth = month;
    int nextYear = year;

    // Check if the next day exceeds the number of days in the current month
    if (nextDay > daysInThisMonth(month, year)) {
        nextDay = 1;  // Reset day to 1
        nextMonth++;  // Move to the next month

        // If the month exceeds December, move to the next year
        if (nextMonth > 12) {
            nextMonth = 1;  // January
            nextYear++;     // Next year
        }
    }

    day = nextDay;
    month = nextMonth;
    year = nextYear;
}

// Function to calculate and return the previous date
void previousDate(int &day, int &month, int &year) {
    int prevDay = day - 1;
    int prevMonth = month;
    int prevYear = year;

    // Check if the previous day goes below 1
    if (prevDay < 1) {
        prevMonth--;  // Move to the previous month
        if (prevMonth < 1) {
            prevMonth = 12;  // Move to December of the previous year
            prevYear--;
        }
        prevDay = daysInThisMonth(prevMonth, prevYear);  // Last day of the previous month
    }

    day = prevDay;
    month = prevMonth;
    year = prevYear;
}

// Function to calculate what day of the year the given date is
int dayOfYear(int day, int month, int year) {
    int totalDays = 0;
    for (int m = 1; m < month; ++m) {
        totalDays += daysInThisMonth(m, year);  // Sum days of all months before the current one
    }
    totalDays += day;  // Add the current day
    return totalDays;
}

// Function to display the date in dd/mm/yyyy format
void displayDate(int day, int month, int year) {
    std::cout << day << "/" << month << "/" << year;
}

int main() {
    int day, month, year;

    // Main function to demonstrate the date operations
    std::cout << "Enter the date (dd mm yyyy): ";
    std::cin >> day >> month >> year;

    // Validate the input date
    if (!isValidDate(day, month, year)) {
        std::cerr << "Error: Invalid date entered!" << std::endl;
        exit(1);  // Terminate the program on invalid date
    }

    // Calculate and display the next date
    int nextDay = day, nextMonth = month, nextYear = year;
    nextDate(nextDay, nextMonth, nextYear);
    std::cout << "Next Date: ";
    displayDate(nextDay, nextMonth, nextYear);
    std::cout << std::endl;

    // Calculate and display the previous date
    int prevDay = day, prevMonth = month, prevYear = year;
    previousDate(prevDay, prevMonth, prevYear);
    std::cout << "Previous Date: ";
    displayDate(prevDay, prevMonth, prevYear);
    std::cout << std::endl;

    // Calculate and display the day of the year
    int dayOfTheYear = dayOfYear(day, month, year);
    std::cout << "Day of the year: " << dayOfTheYear << std::endl;

    return 0;
}
