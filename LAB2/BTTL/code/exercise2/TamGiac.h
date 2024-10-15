#include "../exercise1/Diem.cpp"

class TamGiac{
private:
    Diem A;
    Diem B;
    Diem C;
public:
    void Nhap();
    void Xuat();
    void TinhTien(float x, float y);
    void PhongTo(float size);
    void ThuNho(float size);
    void Quay(const Diem & I, double radian);
};
