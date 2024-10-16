#include "DaGiac.h"
#include <iostream>
#include <cmath>

DaGiac::DaGiac(int n = 3)
{
    Dinh = new Diem[n];
}

DaGiac::~DaGiac()
{
    delete[] Dinh;
}

void DaGiac::Nhap()
{
    std::cout << "Nhap so dinh (n) cua da giac: ";
    std::cin >> n;
    delete[] Dinh;
    Dinh = new Diem[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "Nhap dinh thu " << i + 1 << " cua da giac\n";
        Dinh[i].Nhap();
    }
}

void DaGiac::Xuat()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Dinh thu " << i + 1 << " cua da giac\n";
        Dinh[i].Xuat();
    } 
}


void DaGiac::TinhTien(float x, float y)
{
    for (int i = 0; i < n; i++)
    {
        Dinh[i].TinhTien(x, y);
    } 
}

void DaGiac::PhongTo(float size)
{
    for (int i = 0; i < n; i++)
    {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() * size);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() * size);
    } 
}

void DaGiac::ThuNho(float size)
{
    for (int i = 0; i < n; i++)
    {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() / size);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() / size);
    } 
}

void DaGiac::Quay(const Diem& I, double radian)
{
    for (int i = 0; i < n; i++)
    {
        Dinh[i].SetHoanhDo(I.GetHoanhDo() + (Dinh[i].GetHoanhDo() - I.GetHoanhDo()) * cos(radian) - (Dinh[i].GetTungDo() - I.GetTungDo()) * sin(radian));
        Dinh[i].SetTungDo(I.GetTungDo() + (Dinh[i].GetHoanhDo() - I.GetHoanhDo()) * sin(radian) + (Dinh[i].GetTungDo() + I.GetTungDo()) * cos(radian));
    } 
}
