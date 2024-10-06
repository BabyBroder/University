#include <iostream>
#include <cassert>

class Date {
private:
    int day, month, year;

    const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInThisMonth(int m, int y) const {
        if (m == 2 && isLeapYear(y)) {
            return 29;
        }
        return daysInMonth[m - 1];
    }

    bool isValidDate(int d, int m, int y) const {
        if (y < 1 || m < 1 || m > 12 || d < 1) {
            return false;
        }
        if (d > daysInThisMonth(m, y)) {
            return false;
        }
        return true;
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        if (!isValidDate(day, month, year)) {
            std::cerr << "Error: Invalid date entered!" << std::endl;
            exit(1);
        }
    }

    Date nextDate() const {
        int nextDay = day + 1;
        int nextMonth = month;
        int nextYear = year;

        if (nextDay > daysInThisMonth(month, year)) {
            nextDay = 1;
            nextMonth++;

            if (nextMonth > 12) {
                nextMonth = 1;
                nextYear++;
            }
        }
        return Date(nextDay, nextMonth, nextYear);
    }

    Date previousDate() const {
        int prevDay = day - 1;
        int prevMonth = month;
        int prevYear = year;

        if (prevDay < 1) {
            prevMonth--;
            if (prevMonth < 1) {
                prevMonth = 12;
                prevYear--;
            }
            prevDay = daysInThisMonth(prevMonth, prevYear);
        }
        return Date(prevDay, prevMonth, prevYear);
    }

    int dayOfYear() const {
        int totalDays = 0;
        for (int m = 1; m < month; ++m) {
            totalDays += daysInThisMonth(m, year);
        }
        totalDays += day;
        return totalDays;
    }

    void display() const {
        std::cout << day << "/" << month << "/" << year;
    }

    bool equals(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
};

void runTestCase(int testCaseNum, int d, int m, int y, int expectedNextD, int expectedNextM, int expectedNextY, 
                 int expectedPrevD, int expectedPrevM, int expectedPrevY, int expectedDayOfYear) {
    Date date(d, m, y);
    Date nextDate = date.nextDate();
    Date prevDate = date.previousDate();
    int dayOfYear = date.dayOfYear();

    std::cout << "Test Case " << testCaseNum << ":\n";
    std::cout << "  Input Date: "; date.display(); std::cout << "\n";

    std::cout << "  Expected Next Date: " << expectedNextD << "/" << expectedNextM << "/" << expectedNextY << "\n";
    std::cout << "  Calculated Next Date: "; nextDate.display(); std::cout << "\n";
    std::cout << "  Expected Previous Date: " << expectedPrevD << "/" << expectedPrevM << "/" << expectedPrevY << "\n";
    std::cout << "  Calculated Previous Date: "; prevDate.display(); std::cout << "\n";
    std::cout << "  Expected Day of Year: " << expectedDayOfYear << "\n";
    std::cout << "  Calculated Day of Year: " << dayOfYear << "\n";

    bool nextDateCorrect = nextDate.equals(Date(expectedNextD, expectedNextM, expectedNextY));
    bool prevDateCorrect = prevDate.equals(Date(expectedPrevD, expectedPrevM, expectedPrevY));
    bool dayOfYearCorrect = dayOfYear == expectedDayOfYear;

    if (nextDateCorrect && prevDateCorrect && dayOfYearCorrect) {
        std::cout << "  Result: PASS\n\n";
    } else {
        std::cout << "  Result: FAIL\n\n";
    }
}

int main() {
    runTestCase(1, 1, 1, 2023, 2, 1, 2023, 31, 12, 2022, 1);
    runTestCase(2, 31, 12, 2023, 1, 1, 2024, 30, 12, 2023, 365);
    runTestCase(3, 28, 2, 2020, 29, 2, 2020, 27, 2, 2020, 59);
    runTestCase(4, 29, 2, 2020, 1, 3, 2020, 28, 2, 2020, 60);
    runTestCase(5, 1, 3, 2020, 2, 3, 2020, 29, 2, 2020, 61);
    runTestCase(6, 28, 2, 2021, 1, 3, 2021, 27, 2, 2021, 59);
    runTestCase(7, 31, 1, 2021, 1, 2, 2021, 30, 1, 2021, 31);
    runTestCase(8, 1, 2, 2021, 2, 2, 2021, 31, 1, 2021, 32);
    runTestCase(9, 15, 6, 2023, 16, 6, 2023, 14, 6, 2023, 166);
    runTestCase(10, 31, 8, 2023, 1, 9, 2023, 30, 8, 2023, 243);
    runTestCase(11, 1, 1, 2020, 2, 1, 2020, 31, 12, 2019, 1);
    runTestCase(12, 15, 8, 2020, 16, 8, 2020, 14, 8, 2020, 228);
    runTestCase(13, 31, 7, 2020, 1, 8, 2020, 30, 7, 2020, 213);
    runTestCase(14, 30, 6, 2023, 1, 7, 2023, 29, 6, 2023, 181);
    runTestCase(15, 15, 3, 2021, 16, 3, 2021, 14, 3, 2021, 74);
    runTestCase(16, 30, 4, 2022, 1, 5, 2022, 29, 4, 2022, 120);
    runTestCase(17, 29, 2, 2016, 1, 3, 2016, 28, 2, 2016, 60);
    runTestCase(18, 1, 12, 2023, 2, 12, 2023, 30, 11, 2023, 335);
    runTestCase(19, 25, 12, 2024, 26, 12, 2024, 24, 12, 2024, 360);
    runTestCase(20, 31, 10, 2023, 1, 11, 2023, 30, 10, 2023, 304);

    return 0;
}
