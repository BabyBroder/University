#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iomanip>

using namespace std;

// Flight struct to represent a flight
struct Flight {
    string flightCode;          // The flight code
    string departureDate;       // The departure date in DD/MM/YYYY format
    string departureTime;       // The departure time in HH:MM (24h) format
    string departurePlace;      // The departure place
    string arrivalPlace;        // The arrival place

    // Function to validate the flight code format (maximum 5 characters)
    static bool isValidFlightCode(const string &code) {
        return regex_match(code, regex("^[A-Za-z0-9]{1,5}$"));
    }

    // Function to validate the date format (DD/MM/YYYY)
    static bool isValidDate(const string &date) {
        return regex_match(date, regex("^([0-2][0-9]|(3)[0-1])/(0[1-9]|1[0-2])/([0-9]{4})$"));
    }

    // Function to validate the time format (HH:MM, 24h)
    static bool isValidTime(const string &time) {
        return regex_match(time, regex("^([01]?[0-9]|2[0-3]):([0-5][0-9])$"));
    }

    // Function to validate the place name (no numbers or special characters)
    static bool isValidPlace(const string &place) {
        return regex_match(place, regex("^[A-Za-z ]{1,20}$"));
    }
};

// Function to input flight information from the user
void inputFlight(Flight &flight) {
    do {
        cout << "Enter flight code (maximum 5 characters, no whitespace or special characters): ";
        cin >> flight.flightCode;
        if (!Flight::isValidFlightCode(flight.flightCode)) {
            cout << "Invalid flight code. Please try again.\n";
        }
    } while (!Flight::isValidFlightCode(flight.flightCode));

    do {
        cout << "Enter departure date (dd/mm/yyyy): ";
        cin >> flight.departureDate;
        if (!Flight::isValidDate(flight.departureDate)) {
            cout << "Invalid departure date. Please try again.\n";
        }
    } while (!Flight::isValidDate(flight.departureDate));

    do {
        cout << "Enter departure time (hh:mm, 24h): ";
        cin >> flight.departureTime;
        if (!Flight::isValidTime(flight.departureTime)) {
            cout << "Invalid departure time. Please try again.\n";
        }
    } while (!Flight::isValidTime(flight.departureTime));

    cin.ignore(); // Clear the input buffer
    do {
        cout << "Enter departure place (maximum 20 characters, no numbers or special characters): ";
        getline(cin, flight.departurePlace);
        if (!Flight::isValidPlace(flight.departurePlace)) {
            cout << "Invalid departure place name. Please try again.\n";
        }
    } while (!Flight::isValidPlace(flight.departurePlace));

    do {
        cout << "Enter arrival place (maximum 20 characters, no numbers or special characters): ";
        getline(cin, flight.arrivalPlace);
        if (!Flight::isValidPlace(flight.arrivalPlace)) {
            cout << "Invalid arrival place name. Please try again.\n";
        }
    } while (!Flight::isValidPlace(flight.arrivalPlace));
}

// Function to display flight information in a formatted manner
void displayFlight(const Flight &flight) {
    cout << left << setw(10) << flight.flightCode 
         << setw(15) << flight.departureDate 
         << setw(10) << flight.departureTime 
         << setw(20) << flight.departurePlace 
         << setw(20) << flight.arrivalPlace << endl;
}

// Function to compare flights for sorting by departure date and time
bool compareFlights(const Flight &f1, const Flight &f2) {
    if (f1.departureDate == f2.departureDate) {
        return f1.departureTime < f2.departureTime;
    }
    return f1.departureDate < f2.departureDate;
}

// FlightManager struct to manage a collection of flights
struct FlightManager {
    vector<Flight> flights; // A vector containing all the flights

    // Function to add a new flight
    void addFlight() {
        Flight flight;
        inputFlight(flight);
        flights.push_back(flight);
    }

    // Function to display all flights in a formatted table
    void displayAllFlights() {
        cout << left << setw(10) << "Flight Code" 
             << setw(15) << "Departure Date" 
             << setw(10) << "Departure Time" 
             << setw(20) << "Departure Place" 
             << setw(20) << "Arrival Place" << endl;
        for (const auto &flight : flights) {
            displayFlight(flight);
        }
    }

    // Function to search for a flight by its flight code
    void searchFlightByCode(const string &code) {
        bool found = false;
        for (const auto &flight : flights) {
            if (flight.flightCode == code) {
                displayFlight(flight);
                found = true;
            }
        }
        if (!found) {
            cout << "No flight found with code: " << code << endl;
        }
    }

    // Function to search for flights by departure or arrival place
    void searchFlightByPlace(const string &place, bool isDeparture) {
        bool found = false;
        for (const auto &flight : flights) {
            if ((isDeparture && flight.departurePlace == place) ||
                (!isDeparture && flight.arrivalPlace == place)) {
                displayFlight(flight);
                found = true;
            }
        }
        if (!found) {
            cout << "No flight found with " << (isDeparture ? "departure" : "arrival") << " place: " << place << endl;
        }
    }

    // Function to sort the list of flights by their departure date and time
    void sortFlightsByDateTime() {
        sort(flights.begin(), flights.end(), compareFlights);
    }

    // Function to display flights that depart from a specific place on a specified date
    void displayFlightsByPlaceAndDate(const string &place, const string &date) {
        bool found = false;
        for (const auto &flight : flights) {
            if (flight.departurePlace == place && flight.departureDate == date) {
                displayFlight(flight);
                found = true;
            }
        }
        if (!found) {
            cout << "No flights departing from " << place << " on " << date << endl;
        }
    }

    // Function to count the number of flights from a specific departure to an arrival place
    int countFlightsByRoute(const string &departure, const string &arrival) {
        int count = 0;
        for (const auto &flight : flights) {
            if (flight.departurePlace == departure && flight.arrivalPlace == arrival) {
                count++;
            }
        }
        return count;
    }
};

// Main function that executes the flight management program
int main() {
    FlightManager manager; // Instance of the FlightManager
    int choice;           // User's menu choice

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
