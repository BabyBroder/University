#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * @class SavingsBook
 * @brief Represents a savings book with various details about a savings account.
 */
class SavingsBook {
private:
    string bookCode;          /**< Code of the savings book. */
    string savingsType;       /**< Type of savings (short-term or long-term). */
    string fullName;          /**< Full name of the account holder. */
    string identityCard;      /**< Identity card number of the account holder. */
    string openingDate;       /**< Opening date of the savings book (dd/mm/yyyy). */
    double depositAmount;     /**< Amount deposited in the savings account. */
    double interestRate;      /**< Interest rate applicable to the savings book. */

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
    /**
     * @brief Constructs a SavingsBook object.
     * @param bookCode The code of the savings book.
     * @param savingsType The type of savings (short-term/long-term).
     * @param fullName The full name of the account holder.
     * @param identityCard The identity card number of the account holder.
     * @param openingDate The opening date of the savings book (dd/mm/yyyy).
     * @param depositAmount The initial deposit amount.
     */
    SavingsBook(string bookCode, string savingsType, string fullName, string identityCard, string openingDate, double depositAmount) {
        setBookCode(bookCode);
        setSavingsType(savingsType);
        setFullName(fullName);
        setIdentityCard(identityCard);
        setOpeningDate(openingDate);
        setDepositAmount(depositAmount);
        
        // Set interest rate based on savings type
        if (savingsType == "short-term") {
            interestRate = 5.0; // Example: 5% for short-term
        } else if (savingsType == "long-term") {
            interestRate = 10.0; // Example: 10% for long-term
        } else {
            interestRate = 0.0; // Default interest rate if invalid
        }
    }

    /**
     * @brief Sets the book code after validation.
     * @param bookCode The code to set.
     * @throws invalid_argument if the book code is invalid.
     */
    void setBookCode(string bookCode) {
        if (bookCode.length() > 5 || !isAlphabetic(bookCode)) {
            throw invalid_argument("Invalid book code.");
        }
        this->bookCode = bookCode;
    }

    /**
     * @brief Sets the savings type after validation.
     * @param savingsType The type to set.
     * @throws invalid_argument if the savings type is invalid.
     */
    void setSavingsType(string savingsType) {
        if (savingsType.length() > 10) {
            throw invalid_argument("Invalid savings type.");
        }
        this->savingsType = savingsType;
    }

    /**
     * @brief Sets the full name after validation.
     * @param fullName The full name to set.
     * @throws invalid_argument if the full name is invalid.
     */
    void setFullName(string fullName) {
        if (fullName.length() > 30 || !isAlphabetic(fullName)) {
            throw invalid_argument("Invalid full name.");
        }
        this->fullName = fullName;
    }

    /**
     * @brief Sets the identity card after validation.
     * @param identityCard The identity card to set.
     * @throws invalid_argument if the identity card is invalid.
     */
    void setIdentityCard(string identityCard) {
        if (identityCard.length() != 9 && identityCard.length() != 12) {
            throw invalid_argument("Invalid identity card. It must be 9 or 12 digits.");
        }
        this->identityCard = identityCard;
    }

    /**
     * @brief Sets the opening date after validation.
     * @param openingDate The date to set.
     * @throws invalid_argument if the date is invalid.
     */
    void setOpeningDate(string openingDate) {
        if (!isValidDate(openingDate)) {
            throw invalid_argument("Invalid opening date.");
        }
        this->openingDate = openingDate;
    }

    /**
     * @brief Sets the deposit amount after validation.
     * @param depositAmount The amount to set.
     * @throws invalid_argument if the amount is not positive.
     */
    void setDepositAmount(double depositAmount) {
        if (depositAmount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }
        this->depositAmount = depositAmount;
    }

    // Getters

    /**
     * @brief Gets the book code.
     * @return The book code.
     */
    string getBookCode() const {
        return bookCode;
    }

    /**
     * @brief Gets the savings type.
     * @return The savings type.
     */
    string getSavingsType() const {
        return savingsType;
    }

    /**
     * @brief Gets the full name.
     * @return The full name.
     */
    string getFullName() const {
        return fullName;
    }

    /**
     * @brief Gets the identity card.
     * @return The identity card.
     */
    string getIdentityCard() const {
        return identityCard;
    }

    /**
     * @brief Gets the opening date.
     * @return The opening date.
     */
    string getOpeningDate() const {
        return openingDate;
    }

    /**
     * @brief Gets the deposit amount.
     * @return The deposit amount.
     */
    double getDepositAmount() const {
        return depositAmount;
    }

    /**
     * @brief Updates the interest rate.
     * @param rate The new interest rate.
     */
    void updateInterestRate(double rate) {
        interestRate = rate;
    }

    /**
     * @brief Calculates the interest earned on the savings account.
     * @return The interest amount earned.
     */
    double calculateInterest() const {
        time_t t = time(0);
        tm *now = localtime(&t);

        int currentYear = now->tm_year + 1900;
        int currentMonth = now->tm_mon + 1;

        int openYear = stoi(openingDate.substr(6, 4));
        int openMonth = stoi(openingDate.substr(3, 2));

        int monthsPassed = (currentYear - openYear) * 12 + (currentMonth - openMonth);

        // Interest calculation based on the months passed
        if (savingsType == "short-term" && monthsPassed <= 6) {
            return depositAmount * (interestRate / 100) * (monthsPassed / 12.0);
        }
        else if (savingsType == "long-term" && monthsPassed > 6) {
            return depositAmount * (interestRate / 100) * (monthsPassed / 12.0);
        }
        return 0.0;
    }

    /**
     * @brief Withdraws a specified amount from the savings account.
     * @param amount The amount to withdraw.
     */
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

    /**
     * @brief Displays the savings book information.
     */
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

    /**
     * @brief Checks if the opening date is within the specified date range.
     * @param startDate The start date of the range (dd/mm/yyyy).
     * @param endDate The end date of the range (dd/mm/yyyy).
     * @return True if the opening date is within the range, false otherwise.
     */
    bool isWithinDateRange(const string &startDate, const string &endDate) const {
        int openYear = stoi(openingDate.substr(6, 4));
        int openMonth = stoi(openingDate.substr(3, 2));
        int openDay = stoi(openingDate.substr(0, 2));

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
};

/**
 * @brief Comparison function for sorting by deposit amount.
 * @param a The first savings book to compare.
 * @param b The second savings book to compare.
 * @return True if the first book has a greater deposit amount, false otherwise.
 */
bool compareByDepositAmount(const SavingsBook &a, const SavingsBook &b) {
    return a.getDepositAmount() > b.getDepositAmount();
}

/**
 * @brief Comparison function for sorting by opening date.
 * @param a The first savings book to compare.
 * @param b The second savings book to compare.
 * @return True if the first book was opened before the second, false otherwise.
 */
bool compareByOpeningDate(const SavingsBook &a, const SavingsBook &b) {
    int yearA = stoi(a.getOpeningDate().substr(6, 4));
    int monthA = stoi(a.getOpeningDate().substr(3, 2));
    int dayA = stoi(a.getOpeningDate().substr(0, 2));

    int yearB = stoi(b.getOpeningDate().substr(6, 4));
    int monthB = stoi(b.getOpeningDate().substr(3, 2));
    int dayB = stoi(b.getOpeningDate().substr(0, 2));

    if (yearA != yearB) {
        return yearA < yearB;
    }
    if (monthA != monthB) {
        return monthA < monthB;
    }
    return dayA < dayB;
}

/**
 * @brief The main function that manages the savings book program.
 * @return Exit status.
 */
int main() {
    vector<SavingsBook> books;
    int choice;

    while (true) {
        string bookCode, savingsType, fullName, identityCard, openingDate;
        double depositAmount;

        cout << "Enter Book Code (max 5 characters): ";
        cin >> bookCode;

        cout << "Enter Savings Type (short-term/long-term): ";
        cin >> savingsType;

        cout << "Enter Full Name (max 30 characters): ";
        cin.ignore();
        getline(cin, fullName);

        cout << "Enter Identity Card (9 or 12 digits): ";
        cin >> identityCard;

        cout << "Enter Opening Date (dd/mm/yyyy): ";
        cin >> openingDate;

        cout << "Enter Deposit Amount: ";
        cin >> depositAmount;

        try {
            books.emplace_back(bookCode, savingsType, fullName, identityCard, openingDate, depositAmount);
        } catch (const exception &e) {
            cout << e.what() << endl;
        }

        cout << "Do you want to add another savings book? (1: Yes, 0: No): ";
        cin >> choice;
        if (choice == 0) break;
    }

    // Display the savings books
    for (const auto &book : books) {
        book.display();
    }

    // Sort by deposit amount
    sort(books.begin(), books.end(), compareByDepositAmount);
    cout << "Sorted by deposit amount:\n";
    for (const auto &book : books) {
        book.display();
    }

    // Sort by opening date
    sort(books.begin(), books.end(), compareByOpeningDate);
    cout << "Sorted by opening date:\n";
    for (const auto &book : books) {
        book.display();
    }

    // Withdraw functionality
    string identityCardToWithdraw;
    cout << "Enter Identity Card to withdraw: ";
    cin >> identityCardToWithdraw;

    double amountToWithdraw;
    cout << "Enter amount to withdraw: ";
    cin >> amountToWithdraw;

    for (auto &book : books) {
        if (book.getIdentityCard() == identityCardToWithdraw) {
            book.withdraw(amountToWithdraw);
            break;
        }
    }

    // Search by Identity Card or Book Code
    string searchTerm;
    cout << "Enter Identity Card or Book Code to search: ";
    cin >> searchTerm;

    for (const auto &book : books) {
        if (book.getIdentityCard() == searchTerm || book.getBookCode() == searchTerm) {
            book.display();
        }
    }

    // List by date range
    string startDate, endDate;
    cout << "Enter start date (dd/mm/yyyy): ";
    cin >> startDate;
    cout << "Enter end date (dd/mm/yyyy): ";
    cin >> endDate;

    cout << "Savings books opened between " << startDate << " and " << endDate << ":\n";
    for (const auto &book : books) {
        if (book.isWithinDateRange(startDate, endDate)) {
            book.display();
        }
    }

    return 0;
}
