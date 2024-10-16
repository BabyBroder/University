#include <string>

class ThiSinh
{
private:
    std::string Ten;
    std::string MSSV;
    int iNgay, iThang, iNam;
    float fToan, fVan, fAnh;
public:
    //Khoi tao cho chay cac testcase
    ThiSinh(std::string ht, std::string ms, int ngay, int thang, int nam, float d1, float d2, float d3);
    void Nhap();
    void Xuat() const;
    float Tong() const;
    std::string getMSSV() const;
};
