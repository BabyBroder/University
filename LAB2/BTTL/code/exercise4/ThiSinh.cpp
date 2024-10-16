#include "ThiSinh.h"
#include <iostream>

ThiSinh::ThiSinh(std::string ht = "", std::string ms = "", int ngay = 0, int thang = 0, int nam = 0, float d1 = 0, float d2 = 0, float d3 = 0)
    : Ten(ht), MSSV(ms), iNgay(ngay), iThang(thang), iNam(nam), fToan(d1), fVan(d2), fAnh(d3) {};

void ThiSinh::Nhap()
{
    std::cout << "Nhap ten thi sinh: ";
    std::cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập số lượng
    std::getline(std::cin, Ten);

    std::cout << "Nhap MSSV: ";
    std::cin >> MSSV;

    std::cout << "Nhap ngay sinh (dd mm yyyy): ";
    std::cin >> iNgay >> iThang >> iNam;

    std::cout << "Nhap diem Toan: ";
    std::cin >> fToan;

    std::cout << "Nhap diem Van: ";
    std::cin >> fVan;

    std::cout << "Nhap diem Anh: ";
    std::cin >> fAnh;
}

void ThiSinh::Xuat() const
{
    std::cout << "Ten: " << Ten << "\n";
    std::cout << "MSSV: " << MSSV << "\n";
    std::cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << "\n";
    std::cout << "Diem Toan: " << fToan << "\n";
    std::cout << "Diem Van: " << fVan << "\n";
    std::cout << "Diem Anh: " << fAnh << "\n";
}

float ThiSinh::Tong() const
{
    return fToan + fVan + fAnh;
}

std::string ThiSinh::getMSSV() const
{
    return MSSV;
}