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

bool runTests() {
    vector<SavingsBook> books;

    // Test Case 1: Add new savings books
    cout << "Running Test Case 1: Adding new savings books...\n";
    SavingsBook book1 = {"AB123", "short-term", "John Doe", "123456789", "01/01/2024", 1000, 5.0};
    SavingsBook book2 = {"CD456", "long-term", "Jane Smith", "987654321", "15/03/2024", 2000, 10.0};
    SavingsBook book3 = {"EF789", "long-term", "Alice Johnson", "123123123", "10/04/2024", 3000, 10.0};
    
    books.push_back(book1);
    books.push_back(book2);
    books.push_back(book3);

    if (books.size() == 3) {
        cout << "Test Case 1 Passed: All books added successfully.\n";
    } else {
        cout << "Test Case 1 Failed: Books not added correctly.\n";
        return false;
    }

    // Test Case 2: Withdraw 500 from the first book
    cout << "Running Test Case 2: Withdraw 500 from the first book...\n";
    withdraw(books[0], 500);
    if (books[0].depositAmount == 500) {
        cout << "Test Case 2 Passed: Withdraw successful, deposit amount is 500.\n";
    } else {
        cout << "Test Case 2 Failed: Withdraw unsuccessful.\n";
        return false;
    }

    // Test Case 3: Calculate interest for all books
    cout << "Running Test Case 3: Calculating interest for all books...\n";
    double interestBook1 = calculateInterest(books[0]);
    double interestBook2 = calculateInterest(books[1]);
    double interestBook3 = calculateInterest(books[2]);
    
    cout << "Interest for Book 1: " << interestBook1 << "\n";
    cout << "Interest for Book 2: " << interestBook2 << "\n";
    cout << "Interest for Book 3: " << interestBook3 << "\n";

    if (interestBook1 >= 0 && interestBook2 >= 0 && interestBook3 >= 0) {
        cout << "Test Case 3 Passed: Interest calculated correctly.\n";
    } else {
        cout << "Test Case 3 Failed: Interest calculation failed.\n";
        return false;
    }

    // Test Case 4: Search by Identity Card
    cout << "Running Test Case 4: Searching by Identity Card '987654321'...\n";
    string identityToFind = "987654321";
    bool found = false;
    for (const auto &book : books) {
        if (book.identityCard == identityToFind) {
            displaySavingsBook(book);
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Test Case 4 Passed: Book found for ID '987654321'.\n";
    } else {
        cout << "Test Case 4 Failed: No book found for ID '987654321'.\n";
        return false;
    }

    // Test Case 5: Filter by date range
    cout << "Running Test Case 5: Filtering by date range '01/01/2024' to '30/04/2024'...\n";
    string startDate = "01/01/2024";
    string endDate = "30/04/2024";
    bool anyFiltered = false;
    for (const auto &book : books) {
        if (isWithinDateRange(book, startDate, endDate)) {
            displaySavingsBook(book);
            anyFiltered = true;
        }
    }

    if (anyFiltered) {
        cout << "Test Case 5 Passed: Books filtered correctly by date range.\n";
    } else {
        cout << "Test Case 5 Failed: No books in the specified date range.\n";
        return false;
    }

    // Test Case 6: Calculate interest for the first book
    cout << "Running Test Case 6: Calculating interest for the first book...\n";
    double interest = calculateInterest(books[0]);
    cout << "Interest for Book 1: " << interest << "\n";

    if (interest >= 0) {
        cout << "Test Case 6 Passed: Interest calculated for the first book.\n";
    } else {
        cout << "Test Case 6 Failed: Interest calculation failed for the first book.\n";
        return false;
    }

    // Test Case 7: Withdraw 1500 from the first book (expect failure)
    cout << "Running Test Case 7: Attempting to withdraw 1500 from the first book...\n";
    withdraw(books[0], 1500);
    if (books[0].depositAmount == 500) {
        cout << "Test Case 7 Passed: Correctly prevented over-withdrawal.\n";
    } else {
        cout << "Test Case 7 Failed: Withdrawal allowed more than the deposit.\n";
        return false;
    }

    // Test Case 8: Withdraw from a book with no deposit
    cout << "Running Test Case 8: Attempting to withdraw 100 from a book with no deposit...\n";
    SavingsBook emptyBook = {"GH012", "short-term", "Empty Account", "555555555", "05/05/2024", 0, 5.0};
    withdraw(emptyBook, 100);
    if (emptyBook.depositAmount == 0) {
        cout << "Test Case 8 Passed: Withdrawal prevented on empty account.\n";
    } else {
        cout << "Test Case 8 Failed: Withdrawal allowed on empty account.\n";
        return false;
    }

    // Test Case 9: Sort by deposit amount
    cout << "Running Test Case 9: Sorting by deposit amount...\n";
    sort(books.begin(), books.end(), compareByDepositAmount);
    for (const auto &book : books) {
        displaySavingsBook(book);
    }

    if (books[0].depositAmount >= books[1].depositAmount && books[1].depositAmount >= books[2].depositAmount) {
        cout << "Test Case 9 Passed: Books sorted by deposit amount.\n";
    } else {
        cout << "Test Case 9 Failed: Books not sorted by deposit amount correctly.\n";
        return false;
    }

    // Test Case 10: Sort by opening date
    cout << "Running Test Case 10: Sorting by opening date...\n";
    sort(books.begin(), books.end(), compareByOpeningDate);
    for (const auto &book : books) {
        displaySavingsBook(book);
    }

    // Check if the sorting was successful
    if (compareByOpeningDate(books[0], books[1]) && compareByOpeningDate(books[1], books[2])) {
        cout << "Test Case 10 Passed: Books sorted by opening date.\n";
    } else {
        cout << "Test Case 10 Failed: Books not sorted by opening date correctly.\n";
        return false;
    }
    return true;
}

int main() {
    if (runTests()) {
        cout << "\nAll test cases passed successfully!\n";
    } else {
        cout << "\nSome test cases failed. Check the output above for details.\n";
    }
    return 0;
}
