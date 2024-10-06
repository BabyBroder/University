#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iomanip>
using namespace std;

class Flight {
private:
    string flightCode;
    string departureDate;
    string departureTime;
    string departurePlace;
    string arrivalPlace;

    bool isValidFlightCode(const string &code) {
        return regex_match(code, regex("^[A-Za-z0-9]{1,5}$"));
    }

    bool isValidDate(const string &date) {
        return regex_match(date, regex("^([0-2][0-9]|(3)[0-1])/(0[1-9]|1[0-2])/([0-9]{4})$"));
    }

    bool isValidTime(const string &time) {
        return regex_match(time, regex("^([01]?[0-9]|2[0-3]):([0-5][0-9])$"));
    }

    bool isValidPlace(const string &place) {
        return regex_match(place, regex("^[A-Za-z ]{1,20}$"));
    }

public:
    Flight() {}

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

    void displayFlight() const {
        cout << left << setw(10) << flightCode 
             << setw(15) << departureDate 
             << setw(10) << departureTime 
             << setw(20) << departurePlace 
             << setw(20) << arrivalPlace << endl;
    }

    string getFlightCode() const { return flightCode; }
    string getDepartureDate() const { return departureDate; }
    string getDepartureTime() const { return departureTime; }
    string getDeparturePlace() const { return departurePlace; }
    string getArrivalPlace() const { return arrivalPlace; }

    bool operator<(const Flight &f) const {
        if (departureDate == f.departureDate) {
            return departureTime < f.departureTime;
        }
        return departureDate < f.departureDate;
    }
};

class FlightManager {
private:
    vector<Flight> flights;

public:
    void addFlight(const Flight& flight) {
        flights.push_back(flight);
    }

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

    void sortFlightsByDateTime() {
        sort(flights.begin(), flights.end());
    }

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

// Test case execution function
void runTestCases(FlightManager& manager) {
    cout << "\nRunning Test Cases...\n";

    // Test Case 1: Thêm chuyến bay hợp lệ
    Flight flight1;
    flight1.inputFlight("VN123", "10/10/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");
    manager.addFlight(flight1);

    // Test Case 2: Thêm chuyến bay với mã không hợp lệ
    Flight flight2;
    flight2.inputFlight("VN@123", "10/10/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");

    // Test Case 3: Thêm chuyến bay với ngày không hợp lệ
    Flight flight3;
    flight3.inputFlight("VN123", "31/04/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");

    // Test Case 4: Thêm chuyến bay với giờ không hợp lệ
    Flight flight4;
    flight4.inputFlight("VN124", "10/10/2024", "25:00", "Hà Nội", "TP Hồ Chí Minh");

    // Test Case 5: Thêm chuyến bay với nơi khởi hành và nơi đến giống nhau
    Flight flight5;
    flight5.inputFlight("VN125", "10/10/2024", "12:30", "Hà Nội", "Hà Nội");

    // Test Case 6: Thêm chuyến bay với nơi khởi hành và nơi đến chứa ký tự đặc biệt
    Flight flight6;
    flight6.inputFlight("VN126", "10/10/2024", "12:30", "Hà Nội!", "TP Hồ Chí Minh@");

    // Test Case 7: Tìm kiếm chuyến bay theo mã không hợp lệ
    manager.searchFlightByCode("VN@123");

    // Test Case 8: Tìm kiếm chuyến bay khi không có chuyến nào
    manager.searchFlightByPlace("Quảng Ninh", true);

    // Test Case 9: Tìm kiếm chuyến bay với ngày không hợp lệ
    manager.displayFlightsByPlaceAndDate("Hà Nội", "15/15/2024");

    // Test Case 10: Hiển thị chuyến bay với định dạng không hợp lệ
    manager.displayFlightsByPlaceAndDate("Hà Nội", "10-10-2024");

    // Test Case 11: Kiểm tra danh sách chuyến bay
    manager.displayAllFlights();

    // Test Case 12: Kiểm tra chuyến bay trùng lặp
    Flight flight7;
    flight7.inputFlight("VN123", "10/10/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");
    manager.addFlight(flight7); // Thêm chuyến bay trùng lặp

    // Test Case 13: Kiểm tra nhập liệu số ký tự quá giới hạn
    Flight flight8;
    flight8.inputFlight("VN12345", "10/10/2024", "12:30", "Hà Nội", "TP Hồ Chí Minh");

    // Test Case 14: Tìm kiếm chuyến bay theo thời gian khởi hành
    manager.searchFlightByPlace("12:30", true); // Tìm kiếm theo giờ

    // Test Case 15: Tìm kiếm chuyến bay theo nhiều tiêu chí (ngày và nơi)
    manager.displayFlightsByPlaceAndDate("Hà Nội", "10/10/2024");

    // Test Case 16: Thêm chuyến bay với định dạng không hợp lệ
    Flight flight9;
    flight9.inputFlight("VN127", "2024/10/10", "12:30", "Hà Nội", "TP Hồ Chí Minh");

    cout << "\nTest Cases Completed.\n";
}

int main() {
    FlightManager manager;

    // Chạy các test case
    runTestCases(manager);

    return 0;
}
