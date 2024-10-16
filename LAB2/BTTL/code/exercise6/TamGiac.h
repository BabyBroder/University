#include "../exercise1/Diem.cpp"
#define PI 3.14

class TamGiac{
private:
    Diem A;
    Diem B;
    Diem C;
public:
    void Nhap();
    void Xuat();
    void TinhTien(float angle, float length);

    // phuong thuc cho chay testcase
    void SetPoints(float x1, float y1, float x2, float y2, float x3, float y3);
};