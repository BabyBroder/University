#include <iostream>
#include <vector>
using namespace std;

struct PhanSo {
    int tuSo;
    int mauSo;
};

int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

void rutGonPhanSo(PhanSo &ps) {
    int uc = ucln(abs(ps.tuSo), abs(ps.mauSo));
    ps.tuSo /= uc;
    ps.mauSo /= uc;
    if (ps.mauSo < 0) {
        ps.tuSo = -ps.tuSo;
        ps.mauSo = -ps.mauSo;
    }
}

PhanSo chuanHoaPhanSo(PhanSo a) {
    if (a.mauSo < 0) {
        a.tuSo = -a.tuSo;
        a.mauSo = -a.mauSo;
    }
    return a;
}

bool soSanh(PhanSo a, PhanSo b) {
    a = chuanHoaPhanSo(a);
    b = chuanHoaPhanSo(b);
    return (a.tuSo * b.mauSo < b.tuSo * a.mauSo);
}

PhanSo nhanPhanSo(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tuSo = a.tuSo * b.tuSo;
    ketQua.mauSo = a.mauSo * b.mauSo;
    rutGonPhanSo(ketQua);
    return ketQua;
}

bool bangNhau(PhanSo a, PhanSo b) {
    rutGonPhanSo(a);
    rutGonPhanSo(b);
    return (a.tuSo == b.tuSo && a.mauSo == b.mauSo);
}

void timTapHopCon(vector<PhanSo> &arr, PhanSo dich, int index, vector<PhanSo> &tapHop, vector<PhanSo> &ketQua, PhanSo tich) {
    if (bangNhau(tich, dich) && (ketQua.empty() || tapHop.size() < ketQua.size())) {
        ketQua = tapHop;
        return;
    }
    if (index >= arr.size()) return;
    for (int i = index; i < arr.size(); i++) {
        tapHop.push_back(arr[i]);
        PhanSo tichMoi = nhanPhanSo(tich, arr[i]);
        timTapHopCon(arr, dich, i + 1, tapHop, ketQua, tichMoi);
        tapHop.pop_back();
    }
}

void runTestCases() {
    vector<vector<PhanSo>> testCases = {
        { {1, 2}, {3, 4}, {2, 1}, {5, 1} },
        { {1, 3}, {2, 3}, {3, 3}, {4, 3} },
        { {2, 3}, {3, 5}, {4, 7}, {1, 2} },
        { {1, 4}, {1, 4}, {1, 4} },
        { {1, 1}, {1, 2}, {1, 3}, {1, 4} },
        { {1, 2}, {2, 3}, {3, 4}, {4, 5} },
        { {1, 2}, {3, 6}, {5, 10}, {2, 4} },
        { {3, 4}, {2, 3}, {4, 5}, {6, 7} },
        { {1, 1}, {2, 2}, {3, 3}, {4, 4} },
        { {1, 2}, {3, 4}, {5, 6}, {7, 8} },
        { {2, 1}, {1, 2}, {1, 1} },
        { {3, 1}, {2, 2}, {1, 3}, {1, 4} },
        { {1, 2}, {2, 1}, {3, 3}, {4, 5} },
        { {4, 1}, {1, 4}, {1, 1}, {2, 2} },
        { {1, 3}, {2, 5}, {1, 2}, {3, 4} },
        { {5, 2}, {1, 3}, {3, 4}, {4, 5} },
        { {2, 3}, {3, 2}, {1, 1}, {4, 4} },
        { {1, 5}, {2, 3}, {3, 1}, {1, 2} },
        { {1, 1}, {2, 2}, {2, 3}, {1, 3} },
        { {3, 5}, {5, 3}, {2, 4}, {1, 2} },
        { {6, 1}, {4, 2}, {2, 3}, {1, 3} }
    };
    
    vector<PhanSo> targets = {
        { 15, 8 },
        { 12, 3 },
        { 8, 15 },
        { 1, 4 },
        { 13, 12 },
        { 1, 3 },
        { 1, 2 },
        { 72, 35 },
        { 1, 4 },
        { 21, 32 },
        { 1, 1 },
        { 2, 2 },
        { 9, 8 },
        { 8, 1 },
        { 9, 5 },
        { 5, 6 },
        { 4, 15 },
        { 1, 6 },
        { 1, 1 },
        { 3, 10 },
        { 3, 15 }
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Test case " << i + 1 << ":\n";
        vector<PhanSo> arr = testCases[i];
        PhanSo dich = targets[i];

        cout << "Phan so nhap vao: ";
        for (PhanSo ps : arr) {
            cout << ps.tuSo << "/" << ps.mauSo << " ";
        }
        cout << "\nPhan so dich: " << dich.tuSo << "/" << dich.mauSo << endl;

        vector<PhanSo> tapHop, ketQua;
        PhanSo tich = { 1, 1 };
        timTapHopCon(arr, dich, 0, tapHop, ketQua, tich);
        if (!ketQua.empty()) {
            cout << "Tap hop con nho nhat co tich bang phan so dich: ";
            for (PhanSo ps : ketQua) {
                cout << ps.tuSo << "/" << ps.mauSo << " ";
            }
            cout << endl;
        } else {
            cout << "Khong co tap hop con nao thoa man." << endl;
        }
        cout << endl; // Ngắt dòng giữa các test case
    }
}

int main() {
    runTestCases();
    return 0;
}
