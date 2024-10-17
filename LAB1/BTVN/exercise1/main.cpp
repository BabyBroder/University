#include <iostream>
using namespace std;

/**
 * Struct PhanSo
 *
 * Mo ta: Bieu dien mot phan so voi tu so va mau so.
 */
struct PhanSo
{
    int tuSo;  // Tu so
    int mauSo; // Mau so
};

/**
 * Ham chuanHoaPhanSo
 *
 * Mo ta: Chuẩn hóa một phân số sao cho mẫu số luôn dương.
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
 * Ham nhoHon
 *
 * Mo ta: So sanh hai phan so a va b, tra ve true neu a < b.
 *
 * @param a: phan so thu nhat
 * @param b: phan so thu hai
 * @return: true neu a < b, false neu khong
 */
bool nhoHon(PhanSo a, PhanSo b)
{
    return (a.tuSo * b.mauSo < b.tuSo * a.mauSo);
}

/**
 * Ham lonHon
 *
 * Mo ta: So sanh hai phan so a va b, tra ve true neu a > b.
 *
 * @param a: phan so thu nhat
 * @param b: phan so thu hai
 * @return: true neu a > b, false neu khong
 */
bool lonHon(PhanSo a, PhanSo b)
{
    return (a.tuSo * b.mauSo > b.tuSo * a.mauSo);
}

/**
 * Ham main
 *
 * Mo ta: Nhap vao mot danh sach cac phan so, sau do tim phan so lon nhat va phan so nho nhat trong danh sach.
 *
 * @return: 0 neu chuong trinh ket thuc thanh cong
 */
int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    PhanSo arr[n]; // Mang luu tru cac phan so

    // Nhap du lieu cho tung phan so
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
        } while (arr[i].mauSo == 0); // Kiem tra neu mau so bang 0, yeu cau nhap lai
    }

    // Tim phan so nho nhat va lon nhat
    PhanSo min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (nhoHon(arr[i], min))
        {
            min = arr[i]; // Cap nhat phan so nho nhat
        }
        if (lonHon(arr[i], max))
        {
            max = arr[i]; // Cap nhat phan so lon nhat
        }
    }

    // Xuat ket qua
    cout << "Phan so nho nhat: " << min.tuSo << "/" << min.mauSo << endl;
    cout << "Phan so lon nhat: " << max.tuSo << "/" << max.mauSo << endl;

    return 0;
}
