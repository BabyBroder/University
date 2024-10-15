#pragma once
class Diem
{
private:
    float iHoanh;
    float iTung;
public:
    Diem();                              // Default constructor
    Diem(float Hoanh, float Tung);        // Parameterized constructor
    Diem(const Diem &others);             // Copy constructor
    void Nhap();                          // Input the coordinates
    void Xuat();                          // Output the coordinates
    float GetTungDo() const;                    // Get the y-coordinate (Tung do)
    float GetHoanhDo() const;                   // Get the x-coordinate (Hoanh do)
    void SetTungDo(float Tung);           // Set the y-coordinate
    void SetHoanhDo(float Hoanh);         // Set the x-coordinate (corrected typo)
    void TinhTien(float x, float y);      // Translate the point by (x, y)
};
