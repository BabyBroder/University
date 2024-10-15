#include "TamGiac.h"
#include <iostream>
#include <cmath>

void TamGiac::Nhap()
{
    float x, y;
    std::cout << "Nhap toa do dinh A\n";
    std::cin >> x >> y;
    this->A = Diem(x, y);

    std::cout << "Nhap toa do dinh B\n";
    std::cin >> x >> y;
    this->B = Diem(x, y);

    std::cout << "Nhap toa do dinh C\n";
    std::cin >> x >> y;
    this->C = Diem(x, y);
}

void TamGiac::Xuat()
{
    std::cout << "Voi dinh A\n";
    this->A.Xuat();
    std::cout << "Voi dinh B\n";
    this->B.Xuat();
    std::cout << "Voi dinh C\n";
    this->C.Xuat();
}

void TamGiac::TinhTien(float x, float y)
{
    this->A.TinhTien(x, y);
    this->B.TinhTien(x, y);
    this->C.TinhTien(x, y);
}

void TamGiac::PhongTo(float size)
{
    this->A.SetHoanhDo(A.GetHoanhDo() * size);
    this->A.SetTungDo(A.GetTungDo() * size);

    this->B.SetHoanhDo(B.GetHoanhDo() * size);
    this->B.SetTungDo(B.GetTungDo() * size);

    this->C.SetHoanhDo(C.GetHoanhDo() * size);
    this->C.SetTungDo(C.GetTungDo() * size);
}

void TamGiac::ThuNho(float size)
{
    this->A.SetHoanhDo(A.GetHoanhDo() / size);
    this->A.SetTungDo(A.GetTungDo() / size);

    this->B.SetHoanhDo(B.GetHoanhDo() / size);
    this->B.SetTungDo(B.GetTungDo() / size);

    this->C.SetHoanhDo(C.GetHoanhDo() / size);
    this->C.SetTungDo(C.GetTungDo() / size);
}

void TamGiac::Quay(const Diem& I, double radian)
{
    this->A.SetHoanhDo(I.GetHoanhDo() + (A.GetHoanhDo() - I.GetHoanhDo()) * cos(radian) - (A.GetTungDo() - I.GetTungDo()) * sin(radian));
    this->A.SetTungDo(I.GetTungDo() + (A.GetHoanhDo() - I.GetHoanhDo()) * sin(radian) + (A.GetTungDo() + I.GetTungDo()) * cos(radian));

    this->B.SetHoanhDo(I.GetHoanhDo() + (B.GetHoanhDo() - I.GetHoanhDo()) * cos(radian) - (B.GetTungDo() - I.GetTungDo()) * sin(radian));
    this->B.SetTungDo(I.GetTungDo() + (B.GetHoanhDo() - I.GetHoanhDo()) * sin(radian) + (B.GetTungDo() + I.GetTungDo()) * cos(radian));

    this->C.SetHoanhDo(I.GetHoanhDo() + (C.GetHoanhDo() - I.GetHoanhDo()) * cos(radian) - (C.GetTungDo() - I.GetTungDo()) * sin(radian));
    this->C.SetTungDo(I.GetTungDo() + (C.GetHoanhDo() - I.GetHoanhDo()) * sin(radian) + (C.GetTungDo() + I.GetTungDo()) * cos(radian));
}
