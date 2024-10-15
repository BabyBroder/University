#include "TamGiac.cpp"
#include <math.h>

int main()
{
    TamGiac tamgiacA;
    tamgiacA.Nhap();
    tamgiacA.Xuat();

    tamgiacA.TinhTien(2,3);
    std::cout << "\nTam giac sau khi tinh tien la\n";
    tamgiacA.Xuat();

    tamgiacA.PhongTo(2);
    std::cout << "\nTam giac sau khi phong to 2 lan la\n";
    tamgiacA.Xuat();

    tamgiacA.ThuNho(2);
    std::cout << "\nTam giac sau khi thu nho 2 lan la\n";
    tamgiacA.Xuat();

    Diem O(0, 0);
    tamgiacA.Quay(O ,M_PI);
    std::cout << "\nTam giac sau khi quay pi voi tam quay la O(0, 0) la\n";
    tamgiacA.Xuat();
}
