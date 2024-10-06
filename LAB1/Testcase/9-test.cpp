#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using namespace std;

class SavingsBook {
private:
    string bookCode;
    string savingsType;
    string fullName;
    string identityCard; // Đổi từ int sang string
    string openingDate;
    double depositAmount;
    double interestRate;

    // Helper function to check if a string contains only alphabetic characters
    bool isAlphabetic(const string &str) {
        return all_of(str.begin(), str.end(), [](char c) {
            return isalpha(c) || isspace(c);
        });
    }

    // Helper function to check if a string contains alphanumeric characters
    bool isAlphanumeric(const string &str) {
        return all_of(str.begin(), str.end(), [](char c) {
            return isalnum(c); // Chấp nhận cả ký tự chữ và số
        });
    }

    // Helper function to check if the date is valid
    bool isValidDate(const string &date) const {
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

public:
    // Constructor
    SavingsBook(string bookCode, string savingsType, string fullName, string identityCard, string openingDate, double depositAmount) {
        cout << "Trying to add book with code: " << bookCode << endl; // Debug output
        setBookCode(bookCode);
        setSavingsType(savingsType);
        setFullName(fullName);
        setIdentityCard(identityCard);
        setOpeningDate(openingDate);
        setDepositAmount(depositAmount);
        
        // Cập nhật lãi suất theo loại tài khoản
        if (savingsType == "short-term") {
            interestRate = 5.0; // Ví dụ: 5% cho short-term
        } else if (savingsType == "long-term") {
            interestRate = 10.0; // Ví dụ: 10% cho long-term
        } else {
            interestRate = 0.0; // Lãi suất mặc định nếu không hợp lệ
        }
    }

    // Setters with validation
    void setBookCode(string bookCode) {
        if (bookCode.length() > 5 || !isAlphanumeric(bookCode)) {
            throw invalid_argument("Invalid book code.");
        }
        this->bookCode = bookCode;
    }

    void setSavingsType(string savingsType) {
        if (savingsType.length() > 10) {
            throw invalid_argument("Invalid savings type.");
        }
        this->savingsType = savingsType;
    }

    void setFullName(string fullName) {
        if (fullName.length() > 30 || !isAlphabetic(fullName)) {
            throw invalid_argument("Invalid full name.");
        }
        this->fullName = fullName;
    }

    void setIdentityCard(string identityCard) {
        if (identityCard.length() != 9 && identityCard.length() != 12) {
            throw invalid_argument("Invalid identity card. It must be 9 or 12 digits.");
        }
        this->identityCard = identityCard;
    }

    void setOpeningDate(string openingDate) {
        if (!isValidDate(openingDate)) {
            throw invalid_argument("Invalid opening date.");
        }
        this->openingDate = openingDate;
    }

    void setDepositAmount(double depositAmount) {
        if (depositAmount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }
        this->depositAmount = depositAmount;
    }

    // Getters
    string getBookCode() const {
        return bookCode;
    }

    string getSavingsType() const {
        return savingsType;
    }

    string getFullName() const {
        return fullName;
    }

    string getIdentityCard() const {
        return identityCard;
    }

    string getOpeningDate() const {
        return openingDate;
    }

    double getDepositAmount() const {
        return depositAmount;
    }

    // Function to update the interest rate
    void updateInterestRate(double rate) {
        interestRate = rate;
    }

    // Function to calculate the interest
    double calculateInterest() const {
        // Assume all terms are in years for simplicity
        time_t t = time(0);
        tm *now = localtime(&t);

        int currentYear = now->tm_year + 1900;
        int currentMonth = now->tm_mon + 1;

        int openYear = stoi(openingDate.substr(6, 4));
        int openMonth = stoi(openingDate.substr(3, 2));

        int monthsPassed = (currentYear - openYear) * 12 + (currentMonth - openMonth);

        // Cách tính lãi suất dựa trên tháng đã qua
        if (savingsType == "short-term" && monthsPassed <= 6) {
            return depositAmount * (interestRate / 100) * (monthsPassed / 12.0);
        }
        else if (savingsType == "long-term" && monthsPassed > 6) {
            return depositAmount * (interestRate / 100) * (monthsPassed / 12.0);
        }
        return 0.0;
    }

    // Function to withdraw
    void withdraw(double amount) {
        if (amount > depositAmount) {
            cout << "Cannot withdraw more than the deposited amount.\n";
            return;
        }

        depositAmount -= amount;

        // Recalculate interest if withdrawn early (before maturity)
        if (savingsType == "long-term") {
            double reducedInterestRate = 0.5; // Example reduced rate for long-term accounts
            updateInterestRate(reducedInterestRate);
            cout << "Warning: Withdrawing from long-term account. Interest rate has been reduced.\n";
        }
    }

    // Function to display savings book information
    void display() const {
        cout << "Book Code: " << bookCode << "\n";
        cout << "Savings Type: " << savingsType << "\n";
        cout << "Full Name: " << fullName << "\n";
        cout << "Identity Card: " << identityCard << "\n";
        cout << "Opening Date: " << openingDate << "\n";
        cout << "Deposit Amount: " << fixed << setprecision(2) << depositAmount << "\n";
        cout << "Interest Amount: " << fixed << setprecision(2) << calculateInterest() << "\n";
        cout << "-------------------------------------\n";
    }

    // Function to check if the opening date is within the given range
    bool isWithinDateRange(const string &startDate, const string &endDate) const {
        if (!isValidDate(startDate) || !isValidDate(endDate)) {
            throw invalid_argument("Invalid start or end date.");
        } 
        // Convert opening date to comparable format
        int openYear = stoi(openingDate.substr(6, 4));
        int openMonth = stoi(openingDate.substr(3, 2));
        int openDay = stoi(openingDate.substr(0, 2));

        // Convert start date
        int startYear = stoi(startDate.substr(6, 4));
        int startMonth = stoi(startDate.substr(3, 2));
        int startDay = stoi(startDate.substr(0, 2));

        // Convert end date
        int endYear = stoi(endDate.substr(6, 4));
        int endMonth = stoi(endDate.substr(3, 2));
        int endDay = stoi(endDate.substr(0, 2));

        // Create comparable date format (yyyymmdd)
        int openingDateComparable = openYear * 10000 + openMonth * 100 + openDay;
        int startDateComparable = startYear * 10000 + startMonth * 100 + startDay;
        int endDateComparable = endYear * 10000 + endMonth * 100 + endDay;

        return openingDateComparable >= startDateComparable && openingDateComparable <= endDateComparable;
    }
};

// Compare functions for sorting
bool compareByDepositAmount(const SavingsBook &a, const SavingsBook &b) {
    return a.getDepositAmount() < b.getDepositAmount();
}

bool compareByOpeningDate(const SavingsBook &a, const SavingsBook &b) {
    // Convert opening date to comparable format
    int yearA = stoi(a.getOpeningDate().substr(6, 4));
    int monthA = stoi(a.getOpeningDate().substr(3, 2));
    int dayA = stoi(a.getOpeningDate().substr(0, 2));

    int yearB = stoi(b.getOpeningDate().substr(6, 4));
    int monthB = stoi(b.getOpeningDate().substr(3, 2));
    int dayB = stoi(b.getOpeningDate().substr(0, 2));

    if (yearA != yearB) return yearA < yearB;
    if (monthA != monthB) return monthA < monthB;
    return dayA < dayB;
}

int main() {
    vector<SavingsBook> books;

    // Test case 1: Add savings books
    try {
        books.emplace_back("AB123", "short-term", "John Doe", "123456789", "01/01/2024", 1000);
        books.emplace_back("CD456", "long-term", "Jane Smith", "987654321", "15/03/2024", 2000);
        books.emplace_back("EF789", "long-term", "Alice Johnson", "123123123", "10/04/2024", 3000);
        cout << "Test case 1 passed: Books added successfully.\n";
    } catch (const exception &e) {
        cout << "Test case 1 failed: " << e.what() << endl;
    }

    // Test case 2: Withdraw from a savings book
    try {
        books[0].withdraw(500);
        cout << "Test case 2 passed: Withdraw successful.\n";
    } catch (const exception &e) {
        cout << "Test case 2 failed: " << e.what() << endl;
    }

    // Test case 3: Calculate interest for books
    if (books.size() < 2) {
        cout << "Test case 3 skipped: Not enough books to calculate interest.\n";
    } else {
        for (const auto &book : books) {
            cout << "Interest for " << book.getFullName() << ": " << book.calculateInterest() << "\n";
        }
        cout << "Test case 3 passed: Interest calculated successfully.\n";
    }

    // Test case 4: Find book by identity card
    string identityToFind = "987654321";
    bool found = false;
    for (const auto &book : books) {
        if (book.getIdentityCard() == identityToFind) {
            book.display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Test case 4 failed: No book found with identity card " << identityToFind << ".\n";
    }

    // Test case 5: Get books opened within a specific date range
    string startDate = "01/01/2024";
    string endDate = "30/04/2024";
    cout << "Test case 5: Books opened between " << startDate << " and " << endDate << ":\n";
    bool foundBooks = false;
    for (const auto &book : books) {
        if (book.isWithinDateRange(startDate, endDate)) {
            book.display();
            foundBooks = true;
        }
    }
    if (!foundBooks) {
        cout << "No books found within the specified date range.\n";
    }

    // Test case 6: Calculate interest for a specific book
    if (!books.empty()) {
        double interest = books[0].calculateInterest();
        cout << "Interest for the first book: " << interest << "\n";
        cout << "Test case 6 passed: Interest calculated successfully.\n";
    }

    // Test case 7: Withdraw with an invalid amount
    try {
        books[0].withdraw(1500); // Withdraw more than available
        cout << "Test case 7 passed: Withdraw handled correctly.\n";
    } catch (const exception &e) {
        cout << "Test case 7 failed: " << e.what() << endl;
    }

    // Test case 8: Withdraw from an empty book
    try {
        SavingsBook emptyBook("GH000", "short-term", "No Name", "000000000", "01/01/2024", 0);
        emptyBook.withdraw(100); // This should not throw, but should warn
        cout << "Test case 8 passed: Withdrawal from empty book handled correctly.\n";
    } catch (const exception &e) {
        cout << "Test case 8 failed: " << e.what() << endl;
    }

    // Test case 9: Sort books by deposit amount
    sort(books.begin(), books.end(), compareByDepositAmount);
    cout << "Test case 9: Books sorted by deposit amount:\n";
    for (const auto &book : books) {
        book.display();
    }

    // Test case 10: Sort books by opening date
    sort(books.begin(), books.end(), compareByOpeningDate);
    cout << "Test case 10: Books sorted by opening date:\n";
    for (const auto &book : books) {
        book.display();
    }

    return 0;
}
