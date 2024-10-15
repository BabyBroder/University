#pragma once
#include <iostream>
#include "Diem.h"  // Use double quotes for local headers

// Default constructor
Diem::Diem() : iHoanh(0), iTung(0) {}

// Parameterized constructor
Diem::Diem(float Hoanh, float Tung) : iHoanh(Hoanh), iTung(Tung) {}

// Copy constructor
Diem::Diem(const Diem &others) : iHoanh(others.iHoanh), iTung(others.iTung) {}

//Input method
void Diem::Nhap()
{
    std::cout << "Hoanh do: ";
    std::cin >> iHoanh;
    std::cout << "Tung do: ";
    std::cin >> iTung;
}

// Output method
void Diem::Xuat()
{
    std::cout << "Diem co toa do la\n";
    std::cout << "Hoanh do: " << iHoanh << "\n";
    std::cout << "Tung do: " << iTung << "\n";
}

// Getters
float Diem::GetTungDo() const { return iTung; }
float Diem::GetHoanhDo() const { return iHoanh; }

// Setters
void Diem::SetTungDo(float Tung) { iTung = Tung; }
void Diem::SetHoanhDo(float Hoanh) { iHoanh = Hoanh; }  

// Translation function
void Diem::TinhTien(float x, float y)
{
    iHoanh += x;
    iTung += y;
}
