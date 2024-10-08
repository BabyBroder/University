#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * @brief Checks if a string contains only alphabetic characters.
 * @param str The string to check.
 * @return True if the string is alphabetic, false otherwise.
 */
bool isAlphabetic(const string &str) {
    return all_of(str.begin(), str.end(), [](char c) {
        return isalpha(c) || isspace(c);
    });
}

/**
 * @brief Validates the format of the date.
 * @param date The date string in dd/mm/yyyy format.
 * @return True if the date is valid, false otherwise.
 */
bool isValidDate(const string &date) {
    if (date.length() != 10 || date[2] != '/' || date[5] != '/') return false;
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    // Check days in each month
    if (month == 2) {
        bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leapYear) return day <= 29;
        else return day <= 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) return day <= 30;
    return true;
}

struct SavingsBook {
    string bookCode;
    string savingsType;
    string fullName;
    string identityCard;
    string openingDate;
    double depositAmount;
    double interestRate;
};

/**
 * @brief Initializes the savings book and calculates interest rate.
 * @param book The SavingsBook struct to initialize.
 */
void initializeSavingsBook(SavingsBook &book) {
    cout << "Enter Book Code (max 5 characters): ";
    cin >> book.bookCode;
    while (book.bookCode.length() > 5 || !isAlphabetic(book.bookCode)) {
        cout << "Invalid book code. Try again: ";
        cin >> book.bookCode;
    }

    cout << "Enter Savings Type (short-term/long-term): ";
    cin >> book.savingsType;
    while (book.savingsType != "short-term" && book.savingsType != "long-term") {
        cout << "Invalid savings type. Enter 'short-term' or 'long-term': ";
        cin >> book.savingsType;
    }

    cout << "Enter Full Name (max 30 characters): ";
    cin.ignore();
    getline(cin, book.fullName);
    while (book.fullName.length() > 30 || !isAlphabetic(book.fullName)) {
        cout << "Invalid full name. Try again: ";
        getline(cin, book.fullName);
    }

    cout << "Enter Identity Card (9 or 12 digits): ";
    cin >> book.identityCard;
    while (book.identityCard.length() != 9 && book.identityCard.length() != 12) {
        cout << "Invalid identity card. Enter 9 or 12 digits: ";
        cin >> book.identityCard;
    }

    cout << "Enter Opening Date (dd/mm/yyyy): ";
    cin >> book.openingDate;
    while (!isValidDate(book.openingDate)) {
        cout << "Invalid date format. Try again: ";
        cin >> book.openingDate;
    }

    cout << "Enter Deposit Amount: ";
    cin >> book.depositAmount;
    while (book.depositAmount <= 0) {
        cout << "Deposit amount must be positive. Try again: ";
        cin >> book.depositAmount;
    }

    if (book.savingsType == "short-term") {
        book.interestRate = 5.0;
    } else {
        book.interestRate = 10.0;
    }
}

/**
 * @brief Calculates the interest earned on the savings account.
 * @param book The SavingsBook whose interest is to be calculated.
 * @return The interest amount earned.
 */
double calculateInterest(const SavingsBook &book) {
    time_t t = time(0);
    tm *now = localtime(&t);

    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;

    int openYear = stoi(book.openingDate.substr(6, 4));
    int openMonth = stoi(book.openingDate.substr(3, 2));

    int monthsPassed = (currentYear - openYear) * 12 + (currentMonth - openMonth);

    // Interest calculation based on the months passed
    if (book.savingsType == "short-term" && monthsPassed <= 6) {
        return book.depositAmount * (book.interestRate / 100) * (monthsPassed / 12.0);
    } else if (book.savingsType == "long-term" && monthsPassed > 6) {
        return book.depositAmount * (book.interestRate / 100) * (monthsPassed / 12.0);
    }
    return 0.0;
}

/**
 * @brief Withdraws a specified amount from the savings account.
 * @param book The SavingsBook from which to withdraw.
 * @param amount The amount to withdraw.
 */
void withdraw(SavingsBook &book, double amount) {
    if (amount > book.depositAmount) {
        cout << "Cannot withdraw more than the deposited amount.\n";
        return;
    }

    book.depositAmount -= amount;

    // Recalculate interest if withdrawn early (before maturity)
    if (book.savingsType == "long-term") {
        double reducedInterestRate = 0.5; // Example reduced rate for long-term accounts
        book.interestRate = reducedInterestRate;
        cout << "Warning: Withdrawing from long-term account. Interest rate has been reduced.\n";
    }
}

/**
 * @brief Displays the savings book information.
 * @param book The SavingsBook to display.
 */
void displaySavingsBook(const SavingsBook &book) {
    cout << "Book Code: " << book.bookCode << "\n";
    cout << "Savings Type: " << book.savingsType << "\n";
    cout << "Full Name: " << book.fullName << "\n";
    cout << "Identity Card: " << book.identityCard << "\n";
    cout << "Opening Date: " << book.openingDate << "\n";
    cout << "Deposit Amount: " << fixed << setprecision(2) << book.depositAmount << "\n";
    cout << "Interest Amount: " << fixed << setprecision(2) << calculateInterest(book) << "\n";
    cout << "-------------------------------------\n";
}

/**
 * @brief Checks if the opening date is within the specified date range.
 * @param book The SavingsBook to check.
 * @param startDate The start date of the range (dd/mm/yyyy).
 * @param endDate The end date of the range (dd/mm/yyyy).
 * @return True if the opening date is within the range, false otherwise.
 */
bool isWithinDateRange(const SavingsBook &book, const string &startDate, const string &endDate) {
    int openYear = stoi(book.openingDate.substr(6, 4));
    int openMonth = stoi(book.openingDate.substr(3, 2));
    int openDay = stoi(book.openingDate.substr(0, 2));

    int startYear = stoi(startDate.substr(6, 4));
    int startMonth = stoi(startDate.substr(3, 2));
    int startDay = stoi(startDate.substr(0, 2));

    int endYear = stoi(endDate.substr(6, 4));
    int endMonth = stoi(endDate.substr(3, 2));
    int endDay = stoi(endDate.substr(0, 2));

    // Create comparable date format (yyyymmdd)
    int openingDateComparable = openYear * 10000 + openMonth * 100 + openDay;
    int startDateComparable = startYear * 10000 + startMonth * 100 + startDay;
    int endDateComparable = endYear * 10000 + endMonth * 100 + endDay;

    return openingDateComparable >= startDateComparable && openingDateComparable <= endDateComparable;
}

/**
 * @brief Comparison function for sorting by deposit amount.
 * @param a The first savings book to compare.
 * @param b The second savings book to compare.
 * @return True if the first book has a greater deposit amount, false otherwise.
 */
bool compareByDepositAmount(const SavingsBook &a, const SavingsBook &b) {
    return a.depositAmount > b.depositAmount;
}

/**
 * @brief Comparison function for sorting by opening date.
 * @param a The first savings book to compare.
 * @param b The second savings book to compare.
 * @return True if the first book was opened before the second, false otherwise.
 */
bool compareByOpeningDate(const SavingsBook &a, const SavingsBook &b) {
    int yearA = stoi(a.openingDate.substr(6, 4));
    int monthA = stoi(a.openingDate.substr(3, 2));
    int dayA = stoi(a.openingDate.substr(0, 2));

    int yearB = stoi(b.openingDate.substr(6, 4));
    int monthB = stoi(b.openingDate.substr(3, 2));
    int dayB = stoi(b.openingDate.substr(0, 2));

    return tie(yearA, monthA, dayA) < tie(yearB, monthB, dayB);
}

int main() {
    int n;
    cout << "Enter the number of savings books: ";
    cin >> n;
    
    vector<SavingsBook> books(n);
    for (int i = 0; i < n; ++i) {
        initializeSavingsBook(books[i]);
    }

    cout << "\n---- All Savings Books ----\n";
    for (const auto &book : books) {
        displaySavingsBook(book);
    }

    string startDate, endDate;
    cout << "\nEnter start date (dd/mm/yyyy) for filtering: ";
    cin >> startDate;
    cout << "Enter end date (dd/mm/yyyy) for filtering: ";
    cin >> endDate;

    cout << "\n---- Filtered Savings Books ----\n";
    for (const auto &book : books) {
        if (isWithinDateRange(book, startDate, endDate)) {
            displaySavingsBook(book);
        }
    }

    sort(books.begin(), books.end(), compareByDepositAmount);
    cout << "\n---- Sorted by Deposit Amount ----\n";
    for (const auto &book : books) {
        displaySavingsBook(book);
    }

    sort(books.begin(), books.end(), compareByOpeningDate);
    cout << "\n---- Sorted by Opening Date ----\n";
    for (const auto &book : books) {
        displaySavingsBook(book);
    }

    // Withdraw functionality
    string identityCardToWithdraw;
    cout << "\nEnter Identity Card to withdraw: ";
    cin >> identityCardToWithdraw;

    double amountToWithdraw;
    cout << "Enter amount to withdraw: ";
    cin >> amountToWithdraw;

    for (auto &book : books) {
        if (book.identityCard == identityCardToWithdraw) {
            withdraw(book, amountToWithdraw);
            break;
        }
    }

    // Search by Identity Card or Book Code
    string searchTerm;
    cout << "\nEnter Identity Card or Book Code to search: ";
    cin >> searchTerm;

    cout << "\n---- Search Results ----\n";
    for (const auto &book : books) {
        if (book.identityCard == searchTerm || book.bookCode == searchTerm) {
            displaySavingsBook(book);
        }
    }

    return 0;
}
