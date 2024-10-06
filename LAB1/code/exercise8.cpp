#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iomanip>
using namespace std;

/**
 * @class Flight
 * @brief Represents a flight with relevant details like code, date, time, and places.
 */
class Flight {
private:
    string flightCode;           /**< Flight code (e.g., "AA123"). */
    string departureDate;        /**< Departure date in format DD/MM/YYYY. */
    string departureTime;        /**< Departure time in format HH:MM (24h). */
    string departurePlace;       /**< Departure place name. */
    string arrivalPlace;         /**< Arrival place name. */

    /**
     * @brief Validates the format of the flight code.
     * @param code The flight code to validate.
     * @return True if valid, false otherwise.
     */
    bool isValidFlightCode(const string &code);

    /**
     * @brief Validates the format of the date.
     * @param date The date to validate.
     * @return True if valid, false otherwise.
     */
    bool isValidDate(const string &date);

    /**
     * @brief Validates the format of the time.
     * @param time The time to validate.
     * @return True if valid, false otherwise.
     */
    bool isValidTime(const string &time);

    /**
     * @brief Validates the format of the place name.
     * @param place The place name to validate.
     * @return True if valid, false otherwise.
     */
    bool isValidPlace(const string &place);

public:
    /** @brief Default constructor for Flight class. */
    Flight() {}

    /**
     * @brief Inputs flight information from the user.
     * Prompts the user for flight details and validates input.
     */
    void inputFlight();

    /**
     * @brief Displays flight information.
     */
    void displayFlight() const;

    /**
     * @brief Gets the flight code.
     * @return The flight code.
     */
    string getFlightCode() const;

    /**
     * @brief Gets the departure date.
     * @return The departure date.
     */
    string getDepartureDate() const;

    /**
     * @brief Gets the departure time.
     * @return The departure time.
     */
    string getDepartureTime() const;

    /**
     * @brief Gets the departure place.
     * @return The departure place.
     */
    string getDeparturePlace() const;

    /**
     * @brief Gets the arrival place.
     * @return The arrival place.
     */
    string getArrivalPlace() const;

    /**
     * @brief Compares two flights based on departure date and time.
     * @param f The flight to compare with.
     * @return True if this flight is earlier than the other, false otherwise.
     */
    bool operator<(const Flight &f) const;
};

/**
 * @class FlightManager
 * @brief Manages a collection of flights and provides various operations.
 */
class FlightManager {
private:
    vector<Flight> flights; /**< Collection of flights managed by this class. */

public:
    /**
     * @brief Adds a new flight to the collection.
     * Inputs flight information from the user.
     */
    void addFlight();

    /**
     * @brief Displays all flights in the collection.
     */
    void displayAllFlights();

    /**
     * @brief Searches for a flight by its flight code.
     * @param code The flight code to search for.
     */
    void searchFlightByCode(const string &code);

    /**
     * @brief Searches for flights by departure place.
     * @param place The departure place to search for.
     * @param isDeparture Boolean indicating if the search is for departure place.
     */
    void searchFlightByPlace(const string &place, bool isDeparture);

    /**
     * @brief Sorts the list of flights by departure date and time.
     */
    void sortFlightsByDateTime();

    /**
     * @brief Displays flights departing from a specified place on a specified date.
     * @param place The departure place to filter flights.
     * @param date The departure date to filter flights.
     */
    void displayFlightsByPlaceAndDate(const string &place, const string &date);

    /**
     * @brief Counts the number of flights from a specified departure to arrival place.
     * @param departure The departure place.
     * @param arrival The arrival place.
     * @return The count of flights from departure to arrival.
     */
    int countFlightsByRoute(const string &departure, const string &arrival);
};

/**
 * @brief Main function to run the flight management system.
 * Provides a menu for the user to interact with the flight manager.
 * @return Exit status.
 */
int main() {
    FlightManager manager;
    int choice;

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
