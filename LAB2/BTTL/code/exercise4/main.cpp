#include "ThiSinh.cpp"

int main() {
    int n;
    std::cout << "Nhap so luong thi sinh: ";
    std::cin >> n;

    ThiSinh* dsThiSinh = new ThiSinh[n];

    for (int i = 0; i < n; i++) {
        std::cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        dsThiSinh[i].Nhap();
    }

    std::cout << "\nThong tin cac thi sinh co tong diem lon hon 15:\n";
    for (int i = 0; i < n; i++) {
        if (dsThiSinh[i].Tong() > 15) {
            dsThiSinh[i].Xuat();
            std::cout << "Tong diem: " << dsThiSinh[i].Tong() << "\n\n";
        }
    }

    float maxTongDiem = dsThiSinh[0].Tong();
    int viTriThiSinhMax = 0;
    std::string mssvMax = "23520041"; // MSSV cue em

    for (int i = 1; i < n; i++) {
        if (dsThiSinh[i].Tong() > maxTongDiem) {
            maxTongDiem = dsThiSinh[i].Tong();
            viTriThiSinhMax = i;
        }
        if (dsThiSinh[i].getMSSV() == mssvMax) {
            maxTongDiem = dsThiSinh[i].Tong();
            viTriThiSinhMax = i;
        }
    }

    std::cout << "\nThong tin thi sinh co diem cao nhat:\n";
    dsThiSinh[viTriThiSinhMax].Xuat();
    std::cout << "Tong diem: " << maxTongDiem << "\n";

    // Giải phóng bộ nhớ động
    delete[] dsThiSinh;

    return 0;
}