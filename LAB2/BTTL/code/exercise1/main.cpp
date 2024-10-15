#include "Diem.cpp"  // Include the header file
int main() {
    // Creating an instance using the default constructor
    Diem diem1;
    std::cout << "Tọa độ của diem1 (sử dụng constructor mặc định):\n";
    diem1.Xuat();

    // Creating an instance using the parameterized constructor
    Diem diem2(3.5, 7.2);
    std::cout << "\nTọa độ của diem2 (sử dụng constructor có tham số):\n";
    diem2.Xuat();

    // Modifying diem2's coordinates using setters
    diem2.SetHoanhDo(4.2);
    diem2.SetTungDo(9.1);
    std::cout << "\nTọa độ của diem2 sau khi cập nhật:\n";
    diem2.Xuat();

    // Translating diem2 by (2.0, -3.0)
    diem2.TinhTien(2.0, -3.0);
    std::cout << "\nTọa độ của diem2 sau khi tịnh tiến (2.0, -3.0):\n";
    diem2.Xuat();

    // Using the copy constructor to create a new instance
    Diem diem3 = diem2;
    std::cout << "\nTọa độ của diem3 (sao chép từ diem2):\n";
    std::cout << "Hoanh do: " << diem3.GetHoanhDo() << "\n";
    std::cout << "Tung do: " << diem3.GetTungDo() << "\n";
    return 0;
}
