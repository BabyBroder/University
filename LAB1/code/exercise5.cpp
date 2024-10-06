#include <iostream>
#include <cstdlib>  // For exit()

/**
 * @class Date
 * @brief A class to represent and manipulate dates.
 * 
 * The Date class provides functionality to work with dates, including checking if 
 * a date is valid, calculating the next and previous dates, and determining what 
 * day of the year a given date corresponds to.
 */
class Date {
private:
    int day, month, year;

    // Array to store the number of days in each month
    const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /**
     * @brief Check if a given year is a leap year.
     * 
     * A year is considered a leap year if it is divisible by 4 but not by 100,
     * unless it is divisible by 400.
     * 
     * @param y The year to check.
     * @return true if the year is a leap year, false otherwise.
     */
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    /**
     * @brief Get the number of days in a given month and year.
     * 
     * This function returns the number of days in the specified month. If the 
     * month is February and the year is a leap year, it returns 29 days.
     * 
     * @param m The month (1-12).
     * @param y The year.
     * @return int The number of days in the specified month.
     */
    int daysInThisMonth(int m, int y) const {
        if (m == 2 && isLeapYear(y)) {
            return 29;  // February in a leap year
        }
        return daysInMonth[m - 1];
    }

    /**
     * @brief Check if a given date is valid.
     * 
     * A valid date has a valid year, a month between 1 and 12, and a day that 
     * does not exceed the number of days in the specified month and year.
     * 
     * @param d The day.
     * @param m The month.
     * @param y The year.
     * @return true if the date is valid, false otherwise.
     */
    bool isValidDate(int d, int m, int y) const {
        if (y < 1 || m < 1 || m > 12 || d < 1) {
            return false; // Invalid year, month, or day
        }
        if (d > daysInThisMonth(m, y)) {
            return false; // Day exceeds the number of days in the given month
        }
        return true;
    }

public:
    /**
     * @brief Constructor to initialize the date and validate it.
     * 
     * This constructor takes a day, month, and year, validates the date, and 
     * initializes the Date object. If the date is invalid, the program will 
     * terminate with an error.
     * 
     * @param d The day (1-31).
     * @param m The month (1-12).
     * @param y The year.
     */
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        if (!isValidDate(day, month, year)) {
            std::cerr << "Error: Invalid date entered!" << std::endl;
            exit(1);  // Terminate the program on invalid date
        }
    }

    /**
     * @brief Calculate and return the next date.
     * 
     * This function calculates the next date by incrementing the current day. 
     * If the incremented day exceeds the number of days in the current month, 
     * it moves to the next month, and possibly the next year.
     * 
     * @return Date The next date.
     */
    Date nextDate() const {
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
        return Date(nextDay, nextMonth, nextYear);
    }

    /**
     * @brief Calculate and return the previous date.
     * 
     * This function calculates the previous date by decrementing the current day. 
     * If the decremented day is less than 1, it moves to the previous month, and 
     * possibly the previous year.
     * 
     * @return Date The previous date.
     */
    Date previousDate() const {
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
        return Date(prevDay, prevMonth, prevYear);
    }

    /**
     * @brief Calculate what day of the year this date is.
     * 
     * This function calculates the ordinal day of the year by summing the days of 
     * all months before the current month and adding the current day.
     * 
     * @return int The day of the year.
     */
    int dayOfYear() const {
        int totalDays = 0;
        for (int m = 1; m < month; ++m) {
            totalDays += daysInThisMonth(m, year);  // Sum days of all months before the current one
        }
        totalDays += day;  // Add the current day
        return totalDays;
    }

    /**
     * @brief Display the date in dd/mm/yyyy format.
     */
    void display() const {
        std::cout << day << "/" << month << "/" << year;
    }
};

int main() {
    int day, month, year;

    /**
     * @brief Main function to demonstrate the Date class.
     * 
     * The function prompts the user for a date, creates a Date object, and displays
     * the next date, previous date, and the day of the year for the given date.
     */
    std::cout << "Enter the date (dd mm yyyy): ";
    std::cin >> day >> month >> year;

    // Create a Date object
    Date date(day, month, year);

    // Calculate and display the next date
    Date nextDate = date.nextDate();
    std::cout << "Next Date: ";
    nextDate.display();
    std::cout << std::endl;

    // Calculate and display the previous date
    Date prevDate = date.previousDate();
    std::cout << "Previous Date: ";
    prevDate.display();
    std::cout << std::endl;

    // Calculate and display the day of the year
    int dayOfYear = date.dayOfYear();
    std::cout << "Day of the year: " << dayOfYear << std::endl;

    return 0;
}
