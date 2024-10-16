#include "DiemOxy.cpp"
#include <iostream>
#include <vector>

void runTestCase(Diem& x, int testCase) {
    std::cout << "Test Case " << testCase << ":\n";
    
    // Thuc hien cac buoc theo tung test case
    switch (testCase) {
        case 1:  // Nhan doi toa do
            std::cout << "Nhap: 1\n";
            NhanDoi(x);
            break;
        case 2:  // Tinh tien theo truc Y
            std::cout << "Nhap: 3 (k = 1, d = 5)\n";
            std::cout << "Nhap k va d: 1 5\n"; // Gia su nhap tu ban phim
            TinhTien(x);  // Thuc hien tinh tien
            break;
        case 3:  // Nhan doi toa do va tinh tien theo truc X
            std::cout << "Nhap: 1\n";
            NhanDoi(x);
            std::cout << "Nhap: 3 (k = 0, d = 3)\n";
            std::cout << "Nhap k va d: 0 3\n"; // Gia su nhap tu ban phim
            TinhTien(x);  // Thuc hien tinh tien
            break;
        case 4:  // Gan ve goc toa do va tinh tien theo truc Y
            std::cout << "Nhap: 2\n";
            GanVeO(x);
            std::cout << "Nhap: 3 (k = 1, d = 2)\n";
            std::cout << "Nhap k va d: 1 2\n"; // Gia su nhap tu ban phim
            TinhTien(x);  // Thuc hien tinh tien
            break;
        case 5:  // Nhan doi toa do
            std::cout << "Nhap: 1\n";
            NhanDoi(x);
            break;
        case 6:  // Tinh tien theo truc X
            std::cout << "Nhap: 3 (k = 0, d = 4)\n";
            std::cout << "Nhap k va d: 0 4\n"; // Gia su nhap tu ban phim
            TinhTien(x);  // Thuc hien tinh tien
            break;
        case 7:  // Gan ve goc toa do va nhan doi toa do
            std::cout << "Nhap: 2\n";
            GanVeO(x);
            std::cout << "Nhap: 1\n";
            NhanDoi(x);
            break;
        case 8:  // Tinh tien theo truc Y voi do tinh tien am
            std::cout << "Nhap: 3 (k = 1, d = -3)\n";
            std::cout << "Nhap k va d: 1 -3\n"; // Gia su nhap tu ban phim
            TinhTien(x);  // Thuc hien tinh tien
            break;
        case 9:  // Nhan doi toa do va sau do tinh tien theo truc X
            std::cout << "Nhap: 1\n";
            NhanDoi(x);
            std::cout << "Nhap: 3 (k = 0, d = 2)\n";
            std::cout << "Nhap k va d: 0 2\n"; // Gia su nhap tu ban phim
            TinhTien(x);  // Thuc hien tinh tien
            break;
        case 10:  // Gan ve goc toa do va tinh tien theo truc Y voi do tinh tien duong
            std::cout << "Nhap: 2\n";
            GanVeO(x);
            std::cout << "Nhap: 3 (k = 1, d = 7)\n";
            std::cout << "Nhap k va d: 1 7\n"; // Gia su nhap tu ban phim
            TinhTien(x);  // Thuc hien tinh tien
            break;
        default:
            std::cout << "Test case khong hop le!\n";
            break;
    }
    
    // Xuat toa do cuoi cung cua diem
    std::cout << "Toa do cuoi cung: (" << x.GetHoanhDo() << ", " << x.GetTungDo() << ")\n";
    std::cout << "---------------------------\n";
}

int main() {
    Diem x;
    // Nhap toa do diem ban dau
    std::cout << "Nhap toa do ban dau (x y): ";
    float xCoord, yCoord;
    std::cin >> xCoord >> yCoord;
    x.SetHoanhDo(xCoord);
    x.SetTungDo(yCoord);

    // Chay cac test case
    for (int i = 1; i <= 10; i++) {
        runTestCase(x, i);
    }

    return 0;
}
