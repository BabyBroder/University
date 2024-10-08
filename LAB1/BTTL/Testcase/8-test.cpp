#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iomanip>

using namespace std;

// Flight struct to represent a flight
struct Flight {
    string flightCode;
    string departureDate;
    string departureTime;
    string departurePlace;
    string arrivalPlace;

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

    // Function to input flight information from the user
    void inputFlight(const string& code, const string& date, const string& time, const string& departure, const string& arrival) {
        flightCode = code;
        departureDate = date;
        departureTime = time;
        departurePlace = departure;
        arrivalPlace = arrival;

        if (!isValidFlightCode(code)) {
            cout << "Invalid flight code: " << code << endl;
        }
        if (!isValidDate(date)) {
            cout << "Invalid departure date: " << date << endl;
        }
        if (!isValidTime(time)) {
            cout << "Invalid departure time: " << time << endl;
        }
        if (!isValidPlace(departure)) {
            cout << "Invalid departure place: " << departure << endl;
        }
        if (!isValidPlace(arrival)) {
            cout << "Invalid arrival place: " << arrival << endl;
        }
    }

    // Function to display flight information in a formatted manner
    void displayFlight() const {
        cout << left << setw(10) << flightCode 
             << setw(15) << departureDate 
             << setw(10) << departureTime 
             << setw(20) << departurePlace 
             << setw(20) << arrivalPlace << endl;
    }

    // Operator overload for sorting
    bool operator<(const Flight &f) const {
        if (departureDate == f.departureDate) {
            return departureTime < f.departureTime;
        }
        return departureDate < f.departureDate;
    }
};

// FlightManager struct to manage a collection of flights
struct FlightManager {
    vector<Flight> flights;

    // Function to add a new flight
    void addFlight(const Flight& flight) {
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
            flight.displayFlight();
        }
    }

    // Function to search for a flight by its flight code
    void searchFlightByCode(const string &code) {
        bool found = false;
        for (const auto &flight : flights) {
            if (flight.flightCode == code) {
                flight.displayFlight();
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
                flight.displayFlight();
                found = true;
            }
        }
        if (!found) {
            cout << "No flight found with " << (isDeparture ? "departure" : "arrival") << " place: " << place << endl;
        }
    }

    // Function to sort the list of flights by their departure date and time
    void sortFlightsByDateTime() {
        sort(flights.begin(), flights.end());
    }

    // Function to display flights that depart from a specific place on a specified date
    void displayFlightsByPlaceAndDate(const string &place, const string &date) {
        bool found = false;
        for (const auto &flight : flights) {
            if (flight.departurePlace == place && flight.departureDate == date) {
                flight.displayFlight();
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

// Test case execution function
void runTestCases(FlightManager& manager) {
    cout << "\nRunning Test Cases...\n";

    // Test Case 1: Add a valid flight
    Flight flight1;
    flight1.inputFlight("VN123", "10/10/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");
    manager.addFlight(flight1);

    // Test Case 2: Add a flight with invalid code
    Flight flight2;
    flight2.inputFlight("VN@123", "10/10/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");

    // Test Case 3: Add a flight with invalid date
    Flight flight3;
    flight3.inputFlight("VN123", "31/04/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");

    // Test Case 4: Add a flight with invalid time
    Flight flight4;
    flight4.inputFlight("VN124", "10/10/2024", "25:00", "Hà Nội", "TP Hồ Chí Minh");

    // Test Case 5: Add a flight with departure and arrival the same
    Flight flight5;
    flight5.inputFlight("VN125", "10/10/2024", "12:30", "Hà Nội", "Hà Nội");

    // Test Case 6: Add a flight with special characters in places
    Flight flight6;
    flight6.inputFlight("VN126", "10/10/2024", "12:30", "Hà Nội!", "TP Hồ Chí Minh@");

    // Test Case 7: Search flight by invalid code
    manager.searchFlightByCode("VN@123");

    // Test Case 8: Search for a flight when none exists
    manager.searchFlightByPlace("Quảng Ninh", true);

    // Test Case 9: Search for flights on an invalid date
    manager.displayFlightsByPlaceAndDate("Hà Nội", "15/15/2024");

    // Test Case 10: Display flights with an invalid date format
    manager.displayFlightsByPlaceAndDate("Hà Nội", "10-10-2024");

    // Test Case 11: Check the list of flights
    manager.displayAllFlights();

    // Test Case 12: Check for duplicate flights
    Flight flight7;
    flight7.inputFlight("VN123", "10/10/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");
    manager.addFlight(flight7); // Add duplicate flight

    // Test Case 13: Check for input exceeding character limits
    Flight flight8;
    flight8.inputFlight("VN12345", "10/10/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");

    // Test Case 14: Search flights by departure time
    manager.searchFlightByPlace("12:30", true); // Search by time

    // Test Case 15: Search flights by multiple criteria (date and place)
    manager.displayFlightsByPlaceAndDate("Hà Nội", "10/10/2024");

    // Test Case 16: Add a flight with an invalid format
    Flight flight9;
    flight9.inputFlight("VN127", "2024/10/10", "12:30", "Hà Nội", "TP Hồ Chí Minh");

    cout << "\nTest Cases Completed.\n";
}

// Main function
int main() {
    FlightManager manager;

    // Run the test cases
    runTestCases(manager);

    return 0;
}
