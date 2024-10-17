#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct PhanSo {
    int tuSo;
    int mauSo;
};

PhanSo chuanHoaPhanSo(PhanSo a) {
    if (a.mauSo < 0) {
        a.tuSo = -a.tuSo;
        a.mauSo = -a.mauSo;
    }
    return a;
}

bool nhoHon(PhanSo a, PhanSo b) {
    a = chuanHoaPhanSo(a);
    b = chuanHoaPhanSo(b);
    return (a.tuSo * b.mauSo < b.tuSo * a.mauSo);
}

bool lonHon(PhanSo a, PhanSo b) {
    a = chuanHoaPhanSo(a);
    b = chuanHoaPhanSo(b);
    return (a.tuSo * b.mauSo > b.tuSo * a.mauSo);
}

void printPhanSo(const PhanSo& ps) {
    cout << ps.tuSo << "/" << ps.mauSo;
}

void printArr(const vector<PhanSo>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        printPhanSo(arr[i]);
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

void testCase(int testNumber, vector<PhanSo> arr, PhanSo expectedMin, PhanSo expectedMax) {
    cout << "Test case " << testNumber << ":\n";
    cout << "Input: ";
    printArr(arr);
    cout << "\nExpected Min: ";
    printPhanSo(expectedMin);
    cout << ", Expected Max: ";
    printPhanSo(expectedMax);
    cout << endl;

    PhanSo min = arr[0], max = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (nhoHon(arr[i], min)) {
            min = arr[i];
        }
        if (lonHon(arr[i], max)) {
            max = arr[i];
        }
    }

    cout << "Output Min: ";
    printPhanSo(min);
    cout << ", Output Max: ";
    printPhanSo(max);
    cout << endl;

    assert(min.tuSo == expectedMin.tuSo && min.mauSo == expectedMin.mauSo && "Test thất bại cho phân số nhỏ nhất");
    assert(max.tuSo == expectedMax.tuSo && max.mauSo == expectedMax.mauSo && "Test thất bại cho phân số lớn nhất");

    cout << "Test " << testNumber << " passed!\n\n";
}

int main() {
    // Test case 1: Các phân số khác nhau
    vector<PhanSo> arr1 = {{1, 2}, {3, 4}, {2, 3}};
    PhanSo expectedMin1 = {1, 2};  // Phân số nhỏ nhất là 1/2
    PhanSo expectedMax1 = {3, 4};  // Phân số lớn nhất là 3/4
    testCase(1, arr1, expectedMin1, expectedMax1);

    // Test case 2: Phân số âm
    vector<PhanSo> arr2 = {{-1, 2}, {1, 3}, {2, 5}};
    PhanSo expectedMin2 = {-1, 2};  // Phân số nhỏ nhất là -1/2
    PhanSo expectedMax2 = {2, 5};   // Phân số lớn nhất là 2/5
    testCase(2, arr2, expectedMin2, expectedMax2);

    // Test case 3: Phân số bằng nhau
    vector<PhanSo> arr3 = {{1, 3}, {1, 3}, {1, 3}};
    PhanSo expectedMin3 = {1, 3};  // Tất cả các phân số bằng nhau
    PhanSo expectedMax3 = {1, 3};
    testCase(3, arr3, expectedMin3, expectedMax3);

    // Test case 4: Phân số với tử và mẫu là số lớn
    vector<PhanSo> arr4 = {{100, 200}, {300, 400}, {500, 600}};
    PhanSo expectedMin4 = {100, 200};  // Phân số nhỏ nhất là 100/200
    PhanSo expectedMax4 = {500, 600};  // Phân số lớn nhất là 500/600
    testCase(4, arr4, expectedMin4, expectedMax4);

    // Test case 5: Phân số với tử số âm và dương
    vector<PhanSo> arr5 = {{1, 5}, {-2, 5}, {3, 5}, {-4, 5}};
    PhanSo expectedMin5 = {-4, 5};  // Phân số nhỏ nhất là -4/5
    PhanSo expectedMax5 = {3, 5};   // Phân số lớn nhất là 3/5
    testCase(5, arr5, expectedMin5, expectedMax5);

    // Test case 6: Phân số với mẫu số âm
    vector<PhanSo> arr6 = {{1, -3}, {-2, 4}, {3, -5}, {-4, 6}};
    PhanSo expectedMin6 = {-4, 6};  // Phân số nhỏ nhất là -4/6
    PhanSo expectedMax6 = {1, -3};  // Phân số lớn nhất là 1/-3
    testCase(6, arr6, expectedMin6, expectedMax6);

    // Test case 7: Một phân số duy nhất
    vector<PhanSo> arr7 = {{7, 9}};
    PhanSo expectedMin7 = {7, 9};  // Chỉ có một phân số nên nó là nhỏ nhất và lớn nhất
    PhanSo expectedMax7 = {7, 9};
    testCase(7, arr7, expectedMin7, expectedMax7);

    // Test case 8: Phân số có cùng tử số
    vector<PhanSo> arr8 = {{3, 5}, {3, 7}, {3, 8}};
    PhanSo expectedMin8 = {3, 8};  // Phân số nhỏ nhất là 3/8
    PhanSo expectedMax8 = {3, 5};  // Phân số lớn nhất là 3/5
    testCase(8, arr8, expectedMin8, expectedMax8);

    // Test case 9: Phân số có cùng mẫu số
    vector<PhanSo> arr9 = {{2, 6}, {5, 6}, {-1, 6}};
    PhanSo expectedMin9 = {-1, 6};  // Phân số nhỏ nhất là -1/6
    PhanSo expectedMax9 = {5, 6};   // Phân số lớn nhất là 5/6
    testCase(9, arr9, expectedMin9, expectedMax9);

    // Test case 10: Phân số lớn nhỏ khác nhau nhưng rút gọn giống nhau
    vector<PhanSo> arr10 = {{2, 4}, {3, 6}, {4, 8}};
    PhanSo expectedMin10 = {2, 4};  // Tất cả các phân số rút gọn đều bằng 1/2
    PhanSo expectedMax10 = {2, 4};  // Phân số lớn nhất cũng là 1/2
    testCase(10, arr10, expectedMin10, expectedMax10);

    return 0;
}
