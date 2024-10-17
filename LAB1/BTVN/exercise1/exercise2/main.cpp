#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Struct PhanSo
 * 
 * Mô tả: Biểu diễn một phân số với tử số và mẫu số.
 */
struct PhanSo {
    int tuSo;    // Tử số
    int mauSo;   // Mẫu số
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
 * Hàm soSanh
 *
 * Mô tả: So sánh hai phân số và xác định xem phân số thứ nhất có nhỏ hơn phân số thứ hai không.
 * Được sử dụng để sắp xếp các phân số theo thứ tự tăng dần.
 *
 * @param a: Phân số thứ nhất.
 * @param b: Phân số thứ hai.
 * @return: True nếu phân số thứ nhất nhỏ hơn phân số thứ hai, False nếu ngược lại.
 */
bool soSanh(PhanSo a, PhanSo b) {
    a = chuanHoaPhanSo(a);
    b = chuanHoaPhanSo(b);
    return (a.tuSo * b.mauSo < b.tuSo * a.mauSo);
}

/**
 * Hàm main
 * 
 * Mô tả: Nhập vào một danh sách các phân số, sau đó tìm phân số nhỏ thứ k và phân số lớn thứ k.
 * 
 * Quy trình:
 * 1. Nhập số lượng phân số (n) và số nguyên dương (k) từ người dùng.
 * 2. Nhập tử số và mẫu số cho từng phân số. Yêu cầu nhập lại nếu mẫu số bằng 0.
 * 3. Sắp xếp các phân số theo thứ tự tăng dần.
 * 4. Kiểm tra tính hợp lệ của k và xuất ra phân số nhỏ thứ k và phân số lớn thứ k.
 *
 * @return: 0 nếu chương trình kết thúc thành công.
 */
int main() {
    int n, k;
    cout << "Nhap so luong phan so (n) va so nguyen duong (k): ";
    cin >> n >> k;

    vector<PhanSo> arr(n);  // Mảng lưu trữ các phân số

    // Nhập dữ liệu cho từng phân số
    for (int i = 0; i < n; i++) {
        cout << "Nhap tu so va mau so cua phan so " << i + 1 << ": ";
        cin >> arr[i].tuSo >> arr[i].mauSo;
        while (arr[i].mauSo == 0) {
            cout << "Mau so phai khac 0. Vui long nhap lai mau so cua phan so " << i + 1 << ": ";
            cin >> arr[i].mauSo;
        }
    }

    // Sắp xếp các phân số theo thứ tự tăng dần
    sort(arr.begin(), arr.end(), soSanh);

    // Kiểm tra nếu k hợp lệ
    if (k >= 1 && k <= n) {
        // Phân số nhỏ thứ k
        cout << "Phan so nho thu " << k << ": " << arr[k - 1].tuSo << "/" << arr[k - 1].mauSo << endl;
        // Phân số lớn thứ k
        cout << "Phan so lon thu " << k << ": " << arr[n - k].tuSo << "/" << arr[n - k].mauSo << endl;
    }

    return 0;
}
