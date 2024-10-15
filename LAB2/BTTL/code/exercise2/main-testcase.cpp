#include "TamGiac.cpp"
#include <math.h>

void runTestCases()
{
    // Test case 1: Nhập tam giác từ người dùng và xuất tọa độ
    std::cout << "Test case 1: Nhap thong tin tam giac tu nguoi dung\n";
    TamGiac tg1;
    tg1.Nhap(); // Nhập thông tin cho tam giác
    std::cout << "Thong tin tam giac tg1:\n";
    tg1.Xuat(); // Xuất thông tin tam giác

    // Test case 2: Tạo tam giác với tọa độ cố định
    std::cout << "\nTest case 2: Tao tam giac voi toa do co dinh\n";
    TamGiac tg2; // Tạo đối tượng tam giác tg2
    // Nhập tọa độ cho tam giác tg2
    tg2.Nhap();
    std::cout << "Thong tin tam giac tg2:\n";
    tg2.Xuat(); // Xuất thông tin tam giác tg2

    // Test case 3: Tịnh tiến tam giác tg2
    std::cout << "\nTest case 3: Tinh tien tam giac tg2 voi vector (2, 3)\n";
    tg2.TinhTien(2, 3); // Tịnh tiến với vector (2, 3)
    std::cout << "Thong tin tam giac tg2 sau khi tinh tien:\n";
    tg2.Xuat(); // Xuất thông tin sau khi tịnh tiến

    // Test case 4: Quay tam giác tg2 quanh điểm (0, 0) với góc 45 độ
    std::cout << "\nTest case 4: Quay tam giac tg2 quanh diem (0, 0) voi goc 45 do\n";
    Diem I(0, 0);          // Tạo điểm I tại gốc tọa độ (0, 0)
    tg2.Quay(I, M_PI / 4); // Quay với góc 45 độ (pi/4 radians)
    std::cout << "Thong tin tam giac tg2 sau khi quay:\n";
    tg2.Xuat(); // Xuất thông tin sau khi quay

    // Test case 5: Phóng to tam giác tg2 lên 2 lần và xuất lại tọa độ
    std::cout << "\nTest case 5: Phong to tam giac tg2 len 2 lan\n";
    tg2.PhongTo(2); // Phóng to lên 2 lần
    std::cout << "Thong tin tam giac tg2 sau khi phong to:\n";
    tg2.Xuat(); // Xuất thông tin sau khi phóng to

    // Test case 6: Thu nhỏ tam giác tg2 xuống 0.5 lần và xuất lại tọa độ
    std::cout << "\nTest case 6: Thu nho tam giac tg2 xuong 0.5 lan\n";
    tg2.ThuNho(0.5); // Thu nhỏ xuống 0.5 lần
    std::cout << "Thong tin tam giac tg2 sau khi thu nho:\n";
    tg2.Xuat(); // Xuất thông tin sau khi thu nhỏ
}

int main()
{
    runTestCases();
    return 0;
}
