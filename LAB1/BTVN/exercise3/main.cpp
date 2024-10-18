#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Struct PhanSo
 * 
 * Mo ta: Bieu dien mot phan so voi tu so va mau so.
 */
struct PhanSo {
    int tuSo;    // Tu so
    int mauSo;   // Mau so
};

/**
 * Ham rut gon phan so
 * 
 * @param a: tu so
 * @param b: mau so
 * @return: Uoc chung lon nhat cua tu so va mau so
 */
int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

/**
 * Ham rut gon phan so ve dang toi gian
 * 
 * @param ps: phan so can rut gon
 */
void rutGonPhanSo(PhanSo &ps) {
    int uc = ucln(abs(ps.tuSo), abs(ps.mauSo));
    ps.tuSo /= uc;
    ps.mauSo /= uc;
    if (ps.mauSo < 0) {  // dam bao mau so luon duong
        ps.tuSo = -ps.tuSo;
        ps.mauSo = -ps.mauSo;
    }
}
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
 * Ham nhan hai phan so
 * 
 * Mo ta: Nhan hai phan so a va b, ket qua duoc luu vao phan so tich.
 * 
 * @param a: phan so thu nhat
 * @param b: phan so thu hai
 * @return: Phan so ket qua cua tich a * b
 */
PhanSo nhanPhanSo(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tuSo = a.tuSo * b.tuSo;
    ketQua.mauSo = a.mauSo * b.mauSo;
    rutGonPhanSo(ketQua);
    return ketQua;
}

/**
 * Ham kiem tra xem tich cua cac phan so trong tap hop co bang phan so dich khong
 * 
 * @param tich: tich cua cac phan so
 * @param dich: phan so dich
 * @return: true neu tich = dich, false neu khong
 */
bool bangNhau(PhanSo tich, PhanSo dich) {
    return (tich.tuSo * dich.mauSo == dich.tuSo * tich.mauSo);
}

/**
 * Ham de quy tim tap hop con co tich bang phan so dich
 * 
 * @param arr: mang cac phan so
 * @param dich: phan so dich
 * @param index: chi so hien tai trong mang
 * @param tapHop: tap hop con hien tai
 * @param ketQua: luu tru tap hop con nho nhat
 * @param tich: tich cua cac phan so trong tap hop
 */
void timTapHopCon(vector<PhanSo> &arr, PhanSo dich, int index, vector<PhanSo> &tapHop, vector<PhanSo> &ketQua, PhanSo tich) {
    // Neu tich bang phan so dich va tap hop nho hon ket qua hien tai
    if (bangNhau(tich, dich) && (ketQua.empty() || tapHop.size() < ketQua.size())) {
        ketQua = tapHop;
        return;
    }
    
    if (index >= arr.size()) return;  // Neu da duyet het mang

    // Tim tap hop con co tich bang phan so dich
    for (int i = index; i < arr.size(); i++) {
        tapHop.push_back(arr[i]);
        PhanSo tichMoi = nhanPhanSo(tich, arr[i]);
        timTapHopCon(arr, dich, i + 1, tapHop, ketQua, tichMoi);
        tapHop.pop_back();
    }
}

/**
 * Ham main
 * 
 * @return: 0 neu chuong trinh ket thuc thanh cong
 */
int main() {
    int n;
    cout << "Nhap so luong phan so (n): ";
    cin >> n;

    vector<PhanSo> arr(n);
    
    // Nhap cac phan so
    for (int i = 0; i < n; i++) {
        cout << "Nhap tu so va mau so cua phan so " << i + 1 << ": ";
        cin >> arr[i].tuSo >> arr[i].mauSo;
        rutGonPhanSo(arr[i]);
    }

    // Nhap phan so dich
    PhanSo dich;
    cout << "Nhap tu so va mau so cua phan so dich: ";
    cin >> dich.tuSo >> dich.mauSo;
    rutGonPhanSo(dich);

    vector<PhanSo> tapHop, ketQua;
    PhanSo tich = {1, 1};  // Tich bat dau la 1/1 (phan so don vi)

    // Tim tap hop con
    timTapHopCon(arr, dich, 0, tapHop, ketQua, tich);

    // Neu ket qua rong, khong co tap hop con nao thoa man
    if (ketQua.empty()) {
        cout << "Khong co tap hop con nao thoa man" << endl;
    } else {
        // Sap xep tap hop con theo thu tu tang dan
        sort(ketQua.begin(), ketQua.end(), soSanh);

        cout << "Tap hop con thoa man: " << endl;
        for (PhanSo ps : ketQua) {
            cout << ps.tuSo << "/" << ps.mauSo << " ";
        }
        cout << endl;
    }

    return 0;
}
