#include "DiemOxy.cpp"
#include <vector>

int main()
{
    int num;
    std::vector<int> luachon;
    Diem x;
    x.Nhap();
    std::cin >> num;
    luachon.resize(num);
    for (int i = 0; i < num; i++)
    {
        std::cin >> luachon[i];
    }
    for (int i = 0; i < num; i++)
    {
        if (luachon[i] == 1)
        {
            NhanDoi(x);
        }
        else if (luachon[i] == 2)
        {
            GanVeO(x);
        }
        else if (luachon[i] == 3)
        {
            TinhTien(x);
        }
        else{
            continue;
        }
    }
    x.Xuat();
}