#include "DaGiac.cpp"

void runTestCases() {
    // Test case 1: Khoi tao doi tuong DaGiac co 3 dinh (tam giac)
    std::cout << "Test case 1: Da giac co 3 dinh (tam giac)\n";
    DaGiac daGiac1(3);
    std::cout << "Nhap toa do cac dinh cua tam giac:\n";
    daGiac1.Nhap();
    std::cout << "\nTam giac vua nhap:\n";
    daGiac1.Xuat();

    // Test case 2: Khoi tao da giac co 4 dinh (tu giac)
    std::cout << "\nTest case 2: Da giac co 4 dinh (tu giac)\n";
    DaGiac daGiac2(4);
    std::cout << "Nhap toa do cac dinh cua tu giac:\n";
    daGiac2.Nhap();
    std::cout << "\nTu giac vua nhap:\n";
    daGiac2.Xuat();

    // Test case 3: Tinh tien tam giac theo vector (3, 4)
    std::cout << "\nTest case 3: Tinh tien tam giac theo vector (3, 4)\n";
    daGiac1.TinhTien(3, 4);
    std::cout << "\nTam giac sau khi tinh tien la:\n";
    daGiac1.Xuat();

    // Test case 4: Tinh tien tu giac theo vector (-2, -3)
    std::cout << "\nTest case 4: Tinh tien tu giac theo vector (-2, -3)\n";
    daGiac2.TinhTien(-2, -3);
    std::cout << "\nTu giac sau khi tinh tien la:\n";
    daGiac2.Xuat();

    // Test case 5: Phong to tam giac voi ty le 2.0
    std::cout << "\nTest case 5: Phong to tam giac voi ti le 2.0\n";
    daGiac1.PhongTo(2.0);
    std::cout << "\nTam giac sau khi phong to 2 lan la:\n";
    daGiac1.Xuat();

    // Test case 6: Thu nho tu giac voi ty le 0.5
    std::cout << "\nTest case 6: Thu nho tu giac voi ti le 0.5\n";
    daGiac2.ThuNho(0.5);
    std::cout << "\nTu giac sau khi thu nho 0.5 lan la:\n";
    daGiac2.Xuat();

    // Test case 7: Quay tam giac quanh diem goc (0, 0) goc pi/4 radian
    std::cout << "\nTest case 7: Quay tam giac quanh goc (0, 0) goc pi/4\n";
    Diem I1(0, 0);
    daGiac1.Quay(I1, M_PI / 4);
    std::cout << "\nTam giac sau khi quay goc pi/4 la:\n";
    daGiac1.Xuat();

    // Test case 8: Quay tu giac quanh diem I(1, 1) goc pi/6 radian
    std::cout << "\nTest case 8: Quay tu giac quanh diem I(1, 1) goc pi/6\n";
    Diem I2(1, 1);
    daGiac2.Quay(I2, M_PI / 6);
    std::cout << "\nTu giac sau khi quay goc pi/6 quanh I(1, 1) la:\n";
    daGiac2.Xuat();

    // Test case 9: Khoi tao da giac co 5 dinh (ngu giac)
    std::cout << "\nTest case 9: Da giac co 5 dinh (ngu giac)\n";
    DaGiac daGiac3(5);
    std::cout << "Nhap toa do cac dinh cua ngu giac:\n";
    daGiac3.Nhap();
    std::cout << "\nNgu giac vua nhap:\n";
    daGiac3.Xuat();

    // Test case 10: Phong to ngu giac voi ty le 1.2
    std::cout << "\nTest case 10: Phong to ngu giac voi ti le 1.2\n";
    daGiac3.PhongTo(1.2);
    std::cout << "\nNgu giac sau khi phong to voi ti le 1.2 la:\n";
    daGiac3.Xuat();
}

int main() {
    runTestCases();
    return 0;
}
