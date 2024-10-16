#include "../exercise1/Diem.cpp"

class DaGiac
{
private:
    int n;
    Diem* Dinh;
public:
    DaGiac(int n);
    ~DaGiac();
    void Nhap();
    void Xuat();
    void TinhTien(float x, float y);
    void PhongTo(float size);
    void ThuNho(float size);
    void Quay(const Diem & I, double radian);
};
