#include <iostream>
#include "ThiSinh.cpp"

// Hàm chạy test case
void runTestCase(int n, ThiSinh *dsThiSinh)
{
    std::cout << "\n------------------ Test Case ------------------\n";
    std::cout << "\nThong tin cac thi sinh co tong diem lon hon 15:\n";
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (dsThiSinh[i].Tong() > 15)
        {
            found = true;
            dsThiSinh[i].Xuat();
            std::cout << "Tong diem: " << dsThiSinh[i].Tong() << "\n\n";
        }
    }
    if (!found)
    {
        std::cout << "Khong co thi sinh nao co tong diem lon hon 15.\n";
    }

    // Xác định thí sinh có điểm cao nhất
    float maxTongDiem = dsThiSinh[0].Tong();
    int viTriThiSinhMax = 0;
    std::string mssvMax = "23520041"; // MSSV cue em

    for (int i = 1; i < n; i++)
    {
        if (dsThiSinh[i].Tong() > maxTongDiem)
        {
            maxTongDiem = dsThiSinh[i].Tong();
            viTriThiSinhMax = i;
        }
        if (dsThiSinh[i].getMSSV() == mssvMax)
        {
            maxTongDiem = dsThiSinh[i].Tong();
            viTriThiSinhMax = i;
        }
    }

    // Xuất thông tin thí sinh có điểm cao nhất
    std::cout << "\nThong tin thi sinh co diem cao nhat:\n";
    dsThiSinh[viTriThiSinhMax].Xuat();
    std::cout << "Tong diem: " << maxTongDiem << "\n";
}

int main()
{
    // Test Case 1
    std::cout << "\nTest Case 1:\n";
    ThiSinh ds1[1] = {{"Nguyễn Văn A", "23520041", 10, 10, 2000, 6.0, 5.0, 5.0}};
    runTestCase(1, ds1);

    // Test Case 2
    std::cout << "\nTest Case 2:\n";
    ThiSinh ds2[2] = {
        {"Nguyễn Văn B", "23520042", 11, 11, 2000, 8.0, 7.0, 8.0},
        {"Trần Thị C", "23520043", 12, 12, 2000, 5.0, 5.0, 5.0}};
    runTestCase(2, ds2);

    // Test Case 3
    std::cout << "\nTest Case 3:\n";
    ThiSinh ds3[3] = {
        {"Lê Văn D", "23520044", 13, 1, 2001, 9.0, 8.0, 8.0},
        {"Phạm Thị E", "23520045", 14, 2, 2001, 5.0, 6.0, 7.0},
        {"Trần Văn F", "23520041", 15, 3, 2001, 10.0, 10.0, 9.0}};
    runTestCase(3, ds3);

    // Test Case 4
    std::cout << "\nTest Case 4:\n";
    ThiSinh ds4[2] = {
        {"Võ Văn G", "23520046", 16, 4, 2001, 3.0, 4.0, 5.0},
        {"Đỗ Thị H", "23520047", 17, 5, 2001, 1.0, 1.0, 1.0}};
    runTestCase(2, ds4);

    // Test Case 5
    std::cout << "\nTest Case 5:\n";
    ThiSinh ds5[1] = {
        {"Nguyễn Thị I", "23520048", 18, 6, 2001, 5.0, 5.0, 5.0}};
    runTestCase(1, ds5);

    // Test Case 6
    std::cout << "\nTest Case 6:\n";
    ThiSinh ds6[3] = {
        {"Hứa Văn J", "23520049", 19, 7, 2001, 6.0, 6.0, 5.0},
        {"Lê Thị K", "23520041", 20, 8, 2001, 7.0, 9.0, 10.0},
        {"Trần Văn L", "23520050", 21, 9, 2001, 8.0, 8.0, 8.0}};
    runTestCase(3, ds6);

    // Test Case 7
    std::cout << "\nTest Case 7:\n";
    ThiSinh ds7[2] = {
        {"Nguyễn Văn M", "23520051", 22, 10, 2001, 2.0, 2.0, 2.0},
        {"Trần Thị N", "23520052", 23, 11, 2001, 3.0, 2.0, 1.0}};
    runTestCase(2, ds7);

    // Test Case 8
    std::cout << "\nTest Case 8:\n";
    ThiSinh ds8[2] = {
        {"Nguyễn Văn O", "23520053", 24, 12, 2001, 10.0, 10.0, 10.0},
        {"Trần Thị P", "23520054", 25, 1, 2002, 10.0, 10.0, 10.0}};
    runTestCase(2, ds8);

    // Test Case 9
    std::cout << "\nTest Case 9:\n";
    ThiSinh ds9[1] = {{"Nguyễn Văn Q", "23520055", 26, 2, 2002, -1.0, 2.0, 3.0}};
    runTestCase(1, ds9);
    // Test Case 10
    std::cout << "\nTest Case 10:\n";
    ThiSinh ds10[3] = {
        {"Trần Văn R", "23520056", 27, 3, 2002, 3.0, 4.0, 5.0},
        {"Lê Thị S", "23520057", 28, 4, 2002, 5.0, 5.0, 5.0},
        {"Võ Văn T", "23520058", 29, 5, 2002, 4.0, 4.0, 4.0}};
    runTestCase(3, ds10);

    return 0;
}