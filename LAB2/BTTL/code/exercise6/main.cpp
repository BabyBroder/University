#include "TamGiac.cpp"

int main()
{
    float angle, length;
    TamGiac tamgiac;
    tamgiac.Nhap();   
    std::cout << "----------------------------------------------------------\n";
    tamgiac.Xuat();
    std::cout << "Nhap goc tinh tien(do) va do lon de tinh tien: ";
    std::cin >> angle >> length;
    std::cout << "----------------------------------------------------------\n";
    tamgiac.TinhTien(angle, length);
    tamgiac.Xuat();
}