#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iomanip>

using namespace std;

/**
 * @class Flight
 * @brief Represents a flight with details such as flight code, departure date, time, and places.
 */
class Flight {
private:
    string flightCode; /**< The flight code. */
    string departureDate; /**< The departure date in DD/MM/YYYY format. */
    string departureTime; /**< The departure time in HH:MM (24h) format. */
    string departurePlace; /**< The departure place. */
    string arrivalPlace; /**< The arrival place. */

    /**
     * @brief Validates the flight code format (maximum 5 characters).
     * @param code The flight code to validate.
     * @return True if the code is valid, false otherwise.
     */
    bool isValidFlightCode(const string &code) {
        return regex_match(code, regex("^[A-Za-z0-9]{1,5}$"));
    }

    /**
     * @brief Validates the date format (DD/MM/YYYY).
     * @param date The date to validate.
     * @return True if the date is valid, false otherwise.
     */
    bool isValidDate(const string &date) {
        return regex_match(date, regex("^([0-2][0-9]|(3)[0-1])/(0[1-9]|1[0-2])/([0-9]{4})$"));
    }

    /**
     * @brief Validates the time format (HH:MM, 24h).
     * @param time The time to validate.
     * @return True if the time is valid, false otherwise.
     */
    bool isValidTime(const string &time) {
        return regex_match(time, regex("^([01]?[0-9]|2[0-3]):([0-5][0-9])$"));
    }

    /**
     * @brief Validates the place name (no numbers or special characters).
     * @param place The place name to validate.
     * @return True if the place name is valid, false otherwise.
     */
    bool isValidPlace(const string &place) {
        return regex_match(place, regex("^[A-Za-z ]{1,20}$"));
    }

public:
    /** 
     * @brief Default constructor for Flight. 
     */
    Flight() {}

    /**
     * @brief Inputs flight information from the user.
     */
    void inputFlight() {
        do {
            cout << "Enter flight code (maximum 5 characters, no whitespace or special characters): ";
            cin >> flightCode;
            if (!isValidFlightCode(flightCode)) {
                cout << "Invalid flight code. Please try again.\n";
            }
        } while (!isValidFlightCode(flightCode));

        do {
            cout << "Enter departure date (dd/mm/yyyy): ";
            cin >> departureDate;
            if (!isValidDate(departureDate)) {
                cout << "Invalid departure date. Please try again.\n";
            }
        } while (!isValidDate(departureDate));

        do {
            cout << "Enter departure time (hh:mm, 24h): ";
            cin >> departureTime;
            if (!isValidTime(departureTime)) {
                cout << "Invalid departure time. Please try again.\n";
            }
        } while (!isValidTime(departureTime));

        cin.ignore(); // Clear the input buffer
        do {
            cout << "Enter departure place (maximum 20 characters, no numbers or special characters): ";
            getline(cin, departurePlace);
            if (!isValidPlace(departurePlace)) {
                cout << "Invalid departure place name. Please try again.\n";
            }
        } while (!isValidPlace(departurePlace));

        do {
            cout << "Enter arrival place (maximum 20 characters, no numbers or special characters): ";
            getline(cin, arrivalPlace);
            if (!isValidPlace(arrivalPlace)) {
                cout << "Invalid arrival place name. Please try again.\n";
            }
        } while (!isValidPlace(arrivalPlace));
    }

    /**
     * @brief Displays flight information in a formatted manner.
     */
    void displayFlight() const {
        cout << left << setw(10) << flightCode 
             << setw(15) << departureDate 
             << setw(10) << departureTime 
             << setw(20) << departurePlace 
             << setw(20) << arrivalPlace << endl;
    }

    /** 
     * @brief Getter for flight code.
     * @return The flight code.
     */
    string getFlightCode() const { return flightCode; }

    /** 
     * @brief Getter for departure date.
     * @return The departure date.
     */
    string getDepartureDate() const { return departureDate; }

    /** 
     * @brief Getter for departure time.
     * @return The departure time.
     */
    string getDepartureTime() const { return departureTime; }

    /** 
     * @brief Getter for departure place.
     * @return The departure place.
     */
    string getDeparturePlace() const { return departurePlace; }

    /** 
     * @brief Getter for arrival place.
     * @return The arrival place.
     */
    string getArrivalPlace() const { return arrivalPlace; }

    /**
     * @brief Comparison operator for sorting flights by departure date and time.
     * @param f The flight to compare against.
     * @return True if this flight is earlier than the other, false otherwise.
     */
    bool operator<(const Flight &f) const {
        if (departureDate == f.departureDate) {
            return departureTime < f.departureTime;
        }
        return departureDate < f.departureDate;
    }
};

/**
 * @class FlightManager
 * @brief Manages a collection of flights, allowing for adding, displaying, and searching.
 */
class FlightManager {
private:
    vector<Flight> flights; /**< A vector containing all the flights. */

public:
    /**
     * @brief Adds a new flight by inputting its information.
     */
    void addFlight() {
        Flight flight;
        flight.inputFlight();
        flights.push_back(flight);
    }

    /**
     * @brief Displays all flights in a formatted table.
     */
    void displayAllFlights() {
        cout << left << setw(10) << "Flight Code" 
             << setw(15) << "Departure Date" 
             << setw(10) << "Departure Time" 
             << setw(20) << "Departure Place" 
             << setw(20) << "Arrival Place" << endl;
        for (const auto &flight : flights) {
            flight.displayFlight();
        }
    }

    /**
     * @brief Searches for a flight by its flight code.
     * @param code The flight code to search for.
     */
    void searchFlightByCode(const string &code) {
        bool found = false;
        for (const auto &flight : flights) {
            if (flight.getFlightCode() == code) {
                flight.displayFlight();
                found = true;
            }
        }
        if (!found) {
            cout << "No flight found with code: " << code << endl;
        }
    }

    /**
     * @brief Searches for flights by departure or arrival place.
     * @param place The place to search for.
     * @param isDeparture True if searching for departure place, false for arrival place.
     */
    void searchFlightByPlace(const string &place, bool isDeparture) {
        bool found = false;
        for (const auto &flight : flights) {
            if ((isDeparture && flight.getDeparturePlace() == place) ||
                (!isDeparture && flight.getArrivalPlace() == place)) {
                flight.displayFlight();
                found = true;
            }
        }
        if (!found) {
            cout << "No flight found with " << (isDeparture ? "departure" : "arrival") << " place: " << place << endl;
        }
    }

    /**
     * @brief Sorts the list of flights by their departure date and time.
     */
    void sortFlightsByDateTime() {
        sort(flights.begin(), flights.end());
    }

    /**
     * @brief Displays flights that depart from a specific place on a specified date.
     * @param place The departure place to filter by.
     * @param date The departure date to filter by.
     */
    void displayFlightsByPlaceAndDate(const string &place, const string &date) {
        bool found = false;
        for (const auto &flight : flights) {
            if (flight.getDeparturePlace() == place && flight.getDepartureDate() == date) {
                flight.displayFlight();
                found = true;
            }
        }
        if (!found) {
            cout << "No flights departing from " << place << " on " << date << endl;
        }
    }

    /**
     * @brief Counts the number of flights from a specific departure to an arrival place.
     * @param departure The departure place.
     * @param arrival The arrival place.
     * @return The number of flights on that route.
     */
    int countFlightsByRoute(const string &departure, const string &arrival) {
        int count = 0;
        for (const auto &flight : flights) {
            if (flight.getDeparturePlace() == departure && flight.getArrivalPlace() == arrival) {
                count++;
            }
        }
        return count;
    }
};

/**
 * @brief The main function that executes the flight management program.
 * @return 0 on successful execution.
 */
int main() {
    FlightManager manager; /**< Instance of the FlightManager. */
    int choice; /**< User's menu choice. */

    do {
        cout << "\n1. Add flight\n"
             << "2. Display flight list\n"
             << "3. Search flight by code\n"
             << "4. Search flight by departure place\n"
             << "5. Search flight by arrival place\n"
             << "6. Sort flights by date and time\n"
             << "7. Display flights by departure place and date\n"
             << "8. Count flights by route\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addFlight();
                break;
            case 2:
                manager.displayAllFlights();
                break;
            case 3: {
                string code;
                cout << "Enter flight code: ";
                cin >> code;
                manager.searchFlightByCode(code);
                break;
            }
            case 4: {
                string place;
                cin.ignore();
                cout << "Enter departure place: ";
                getline(cin, place);
                manager.searchFlightByPlace(place, true);
                break;
            }
            case 5: {
                string place;
                cin.ignore();
                cout << "Enter arrival place: ";
                getline(cin, place);
                manager.searchFlightByPlace(place, false);
                break;
            }
            case 6:
                manager.sortFlightsByDateTime();
                manager.displayAllFlights();
                break;
            case 7: {
                string place, date;
                cin.ignore();
                cout << "Enter departure place: ";
                getline(cin, place);
                cout << "Enter departure date: ";
                getline(cin, date);
                manager.displayFlightsByPlaceAndDate(place, date);
                break;
            }
            case 8: {
                string departure, arrival;
                cin.ignore();
                cout << "Enter departure place: ";
                getline(cin, departure);
                cout << "Enter arrival place: ";
                getline(cin, arrival);
                cout << "Number of flights from " << departure << " to " << arrival << ": "
                     << manager.countFlightsByRoute(departure, arrival) << endl;
                break;
            }
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
