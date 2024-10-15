#include "Diem.cpp"  // Include the Diem class implementation

// Function to run test cases
void runTestCases() {
    // Test case 1: Default constructor (expect (0, 0))
    std::cout << "Test case 1: Default constructor\n";
    Diem diem1;
    diem1.Xuat();  

    // Test case 2: Parameterized constructor with positive values
    std::cout << "\nTest case 2: Parameterized constructor (positive values)\n";
    Diem diem2(3.5, 7.2);
    diem2.Xuat();  // Expect (3.5, 7.2)

    // Test case 3: Parameterized constructor with negative values
    std::cout << "\nTest case 3: Parameterized constructor (negative values)\n";
    Diem diem3(-4.5, -8.3);
    diem3.Xuat();  // Expect (-4.5, -8.3)

    // Test case 4: Parameterized constructor with zero
    std::cout << "\nTest case 4: Parameterized constructor (zero values)\n";
    Diem diem4(0.0, 0.0);
    diem4.Xuat();  // Expect (0.0, 0.0)

    // Test case 5: Set hoanh do (change x-coordinate)
    std::cout << "\nTest case 5: Set hoanh do\n";
    diem2.SetHoanhDo(9.1);
    diem2.Xuat();  // Expect (9.1, 7.2)

    // Test case 6: Set tung do (change y-coordinate)
    std::cout << "\nTest case 6: Set tung do\n";
    diem2.SetTungDo(5.5);
    diem2.Xuat();  // Expect (9.1, 5.5)

    // Test case 7: TinhTien with positive values
    std::cout << "\nTest case 7: TinhTien (positive values)\n";
    diem2.TinhTien(2.0, 3.0);
    diem2.Xuat();  // Expect (11.1, 8.5)

    // Test case 8: TinhTien with negative values
    std::cout << "\nTest case 8: TinhTien (negative values)\n";
    diem3.TinhTien(-1.5, -2.3);
    diem3.Xuat();  // Expect (-6.0, -10.6)

    // Test case 9: Copy constructor
    std::cout << "\nTest case 9: Copy constructor\n";
    Diem diem5 = diem2;
    diem5.Xuat();  // Expect same as diem2 (11.1, 8.5)

    // Test case 10: Translation with zero vector
    std::cout << "\nTest case 10: Translation with zero vector\n";
    diem5.TinhTien(0, 0);
    diem5.Xuat();  // Expect no change (11.1, 8.5)

    // Test case 11: GetHoanhDo (expect 11.1)
    std::cout << "\nTest case 11: GetHoanhDo\n";
    std::cout << "Hoanh do: " << diem5.GetHoanhDo() << "\n";  // Expect 11.1

    // Test case 12: GetTungDo (expect 8.5)
    std::cout << "\nTest case 12: GetTungDo\n";
    std::cout << "Tung do: " << diem5.GetTungDo() << "\n";  // Expect 8.5

    // Test case 13: Modify coordinates after copy constructor
    std::cout << "\nTest case 13: Modify coordinates after copy\n";
    diem5.SetHoanhDo(20.0);
    diem5.SetTungDo(30.0);
    diem5.Xuat();  // Expect (20.0, 30.0)
    diem2.Xuat();  // Expect diem2 unchanged (11.1, 8.5)

    // Test case 14: Negative translation after setting new values
    std::cout << "\nTest case 14: Negative translation\n";
    diem5.TinhTien(-5.0, -10.0);
    diem5.Xuat();  // Expect (15.0, 20.0)

    // Test case 15: Translation causing hoanh do to be zero
    std::cout << "\nTest case 15: Translation causing hoanh do to be zero\n";
    diem5.TinhTien(-15.0, 0);
    diem5.Xuat();  // Expect (0.0, 20.0)

    // Test case 16: Translation causing tung do to be zero
    std::cout << "\nTest case 16: Translation causing tung do to be zero\n";
    diem5.TinhTien(0, -20.0);
    diem5.Xuat();  // Expect (0.0, 0.0)

    // Test case 17: Set coordinates to extreme values
    std::cout << "\nTest case 17: Set coordinates to extreme values\n";
    diem5.SetHoanhDo(1e9);  // Large x-coordinate
    diem5.SetTungDo(-1e9);  // Large negative y-coordinate
    diem5.Xuat();  // Expect (1e9, -1e9)

    // Test case 18: Translation with small floating-point values
    std::cout << "\nTest case 18: Translation with small floating-point values\n";
    diem5.TinhTien(0.0001, -0.0001);
    diem5.Xuat();  // Expect (1e9 + 0.0001, -1e9 - 0.0001)

    // Test case 19: Translation with very large values
    std::cout << "\nTest case 19: Translation with very large values\n";
    diem5.TinhTien(1e9, 1e9);
    diem5.Xuat();  // Expect (2e9 + 0.0001, 0 - 0.0001)

    // Test case 20: Input coordinates from user
    std::cout << "\nTest case 20: Input coordinates from user\n";
    Diem diem6;
    diem6.Nhap();  // User inputs values
    diem6.Xuat();  // Expect user-defined coordinates
}

int main() {
    // Run all test cases
    runTestCases();
    return 0;
}
