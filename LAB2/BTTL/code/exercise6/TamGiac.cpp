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

void TamGiac::TinhTien(float angle, float length)
{
    float radian = angle * (PI / 180);

    float dx = length * cos(radian);
    float dy = length * sin(radian);

    this->A.SetHoanhDo(A.GetHoanhDo() + dx);
    this->A.SetTungDo(A.GetTungDo() + dy);

    this->B.SetHoanhDo(B.GetHoanhDo() + dx);
    this->B.SetTungDo(B.GetTungDo() + dy);

    this->C.SetHoanhDo(C.GetHoanhDo() + dx);
    this->C.SetTungDo(C.GetTungDo() + dy);
}

void TamGiac::SetPoints(float x1, float y1, float x2, float y2, float x3, float y3) {
    A.SetHoanhDo(x1);
    A.SetTungDo(y1);
    B.SetHoanhDo(x2);
    B.SetTungDo(y2);
    C.SetHoanhDo(x3);
    C.SetTungDo(y3);
}