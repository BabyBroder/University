#include <iostream>
using namespace std;

/**
 * Struct PhanSo
 *
 * Mô tả: Biểu diễn một phân số với tử số và mẫu số.
 */
struct PhanSo
{
    int tuSo;  // Tử số
    int mauSo; // Mẫu số
};

/**
 * Hàm chuanHoaPhanSo
 *
 * Mô tả: Chuẩn hóa một phân số sao cho mẫu số luôn dương.
 * Nếu mẫu số âm, cả tử số và mẫu số sẽ được đổi dấu để đảm bảo mẫu số là dương.
 *
 * @param a: Phân số cần chuẩn hóa.
 * @return: Phân số sau khi đã chuẩn hóa với mẫu số dương.
 */
PhanSo chuanHoaPhanSo(PhanSo a)
{
    if (a.mauSo < 0)
    {
        a.tuSo = -a.tuSo;
        a.mauSo = -a.mauSo;
    }
    return a;
}

/**
 * Hàm nhoHon
 *
 * Mô tả: So sánh hai phân số và kiểm tra xem phân số đầu tiên có nhỏ hơn phân số thứ hai không.
 *
 * @param a: Phân số thứ nhất.
 * @param b: Phân số thứ hai.
 * @return: True nếu phân số thứ nhất nhỏ hơn phân số thứ hai, False nếu ngược lại.
 */
bool nhoHon(PhanSo a, PhanSo b)
{
    a = chuanHoaPhanSo(a);
    b = chuanHoaPhanSo(b);
    return (a.tuSo * b.mauSo < b.tuSo * a.mauSo);
}

/**
 * Hàm lonHon
 *
 * Mô tả: So sánh hai phân số và kiểm tra xem phân số đầu tiên có lớn hơn phân số thứ hai không.
 *
 * @param a: Phân số thứ nhất.
 * @param b: Phân số thứ hai.
 * @return: True nếu phân số thứ nhất lớn hơn phân số thứ hai, False nếu ngược lại.
 */
bool lonHon(PhanSo a, PhanSo b)
{
    a = chuanHoaPhanSo(a);
    b = chuanHoaPhanSo(b);
    return (a.tuSo * b.mauSo > b.tuSo * a.mauSo);
}

/**
 * Hàm main
 *
 * Mô tả: Nhập vào một danh sách các phân số, sau đó tìm phân số lớn nhất và phân số nhỏ nhất trong danh sách.
 *
 * Quy trình:
 * 1. Nhập số lượng phân số từ người dùng.
 * 2. Nhập tử số và mẫu số cho từng phân số. Yêu cầu nhập lại nếu mẫu số bằng 0.
 * 3. Tìm phân số nhỏ nhất và lớn nhất bằng cách so sánh từng phân số trong mảng.
 * 4. In ra phân số nhỏ nhất và phân số lớn nhất.
 *
 * @return: 0 nếu chương trình kết thúc thành công.
 */
int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    PhanSo arr[n]; // Mảng lưu trữ các phân số

    // Nhập dữ liệu cho từng phân số
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap tu so cua phan so " << i + 1 << ": ";
        cin >> arr[i].tuSo;
        do
        {
            cout << "Nhap mau so cua phan so " << i + 1 << ": ";
            cin >> arr[i].mauSo;
            if (arr[i].mauSo == 0)
            {
                cout << "Mau so phai khac 0. Vui long nhap lai." << endl;
            }
        } while (arr[i].mauSo == 0); // Kiểm tra nếu mẫu số bằng 0, yêu cầu nhập lại
    }

    // Tìm phân số nhỏ nhất và lớn nhất
    PhanSo min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (nhoHon(arr[i], min))
        {
            min = arr[i]; // Cập nhật phân số nhỏ nhất
        }
        if (lonHon(arr[i], max))
        {
            max = arr[i]; // Cập nhật phân số lớn nhất
        }
    }

    // Xuất kết quả
    cout << "Phan so nho nhat: " << min.tuSo << "/" << min.mauSo << endl;
    cout << "Phan so lon nhat: " << max.tuSo << "/" << max.mauSo << endl;

    return 0;
}
