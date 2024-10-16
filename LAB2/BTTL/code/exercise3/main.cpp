#include "DaGiac.cpp"

int main()
{
    DaGiac DaGiacA;
    DaGiacA.Nhap();
    DaGiacA.Xuat();

    DaGiacA.TinhTien(2,3);
    std::cout << "\nDa giac sau khi tinh tien la\n";
    DaGiacA.Xuat();

    DaGiacA.PhongTo(2);
    std::cout << "\nDa giac sau khi phong to 2 lan la\n";
    DaGiacA.Xuat();

    DaGiacA.ThuNho(2);
    std::cout << "\nDa giac sau khi thu nho 2 lan la\n";
    DaGiacA.Xuat();

    Diem O(0, 0);
    DaGiacA.Quay(O ,M_PI);
    std::cout << "\nDa giac sau khi quay pi voi tam quay la O(0, 0) la\n";
    DaGiacA.Xuat();
}