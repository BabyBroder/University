#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct PhanSo
{
    int tuSo;
    int mauSo;
};

PhanSo chuanHoaPhanSo(PhanSo a)
{
    if (a.mauSo < 0)
    {
        a.tuSo = -a.tuSo;
        a.mauSo = -a.mauSo;
    }
    return a;
}

bool soSanh(PhanSo a, PhanSo b)
{
    a = chuanHoaPhanSo(a);
    b = chuanHoaPhanSo(b);
    return (a.tuSo * b.mauSo < b.tuSo * a.mauSo);
}

void testCase(int testNumber, int n, int k, vector<PhanSo> arr, PhanSo expectedSmall, PhanSo expectedLarge)
{
    sort(arr.begin(), arr.end(), soSanh);

    PhanSo small = arr[k - 1];
    PhanSo large = arr[n - k];

    cout << "Test case " << testNumber << " with n = " << n << ", k = " << k << ":\n";
    cout << "Sorted fractions:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i].tuSo << "/" << arr[i].mauSo << (i < n - 1 ? ", " : "");
    }
    cout << "\nExpected Small: " << expectedSmall.tuSo << "/" << expectedSmall.mauSo
         << ", Got: " << small.tuSo << "/" << small.mauSo << "\n";
    cout << "Expected Large: " << expectedLarge.tuSo << "/" << expectedLarge.mauSo
         << ", Got: " << large.tuSo << "/" << large.mauSo << "\n";
    cout << "------------------------------\n";
}

int main()
{
    testCase(1, 4, 2, {{1, 2}, {3, 4}, {1, 3}, {2, 5}}, {1, 3}, {3, 4});
    testCase(2, 3, 1, {{3, 5}, {2, 4}, {1, 2}}, {1, 2}, {3, 5});
    testCase(3, 4, 3, {{1, 3}, {2, 6}, {3, 1}, {0, 1}}, {3, 1}, {0, 1});
    testCase(4, 3, 2, {{4, 5}, {2, 3}, {1, 2}}, {2, 3}, {4, 5});
    testCase(5, 5, 1, {{-1, 1}, {1, -1}, {0, 1}, {1, 2}, {2, 3}}, {0, 1}, {1, 2});
    testCase(6, 5, 3, {{2, 1}, {3, 1}, {1, 1}, {4, 2}, {3, 2}}, {3, 1}, {3, 1});
    testCase(7, 4, 4, {{3, 2}, {4, 1}, {2, 3}, {1, 1}}, {4, 1}, {1, 1});
    testCase(8, 3, 3, {{5, 6}, {1, 1}, {2, 3}}, {5, 6}, {1, 1});
    testCase(9, 6, 2, {{-1, 3}, {3, 4}, {4, 5}, {2, 7}, {0, 2}, {1, 1}}, {0, 2}, {4, 5});
    testCase(10, 4, 1, {{2, 5}, {1, 2}, {1, 3}, {3, 1}}, {1, 3}, {3, 1});
    testCase(11, 5, 2, {{1, 3}, {2, 5}, {3, 4}, {1, 2}, {0, 1}}, {1, 2}, {2, 5});
    testCase(12, 4, 1, {{1, 2}, {1, 3}, {2, 3}, {3, 4}}, {1, 3}, {3, 4});
    testCase(13, 6, 3, {{-2, 3}, {4, 5}, {3, 2}, {1, 1}, {0, 1}, {2, 7}}, {1, 1}, {4, 5});
    testCase(14, 5, 4, {{-1, 2}, {2, 1}, {1, 3}, {0, 1}, {5, 3}}, {5, 3}, {0, 1});
    testCase(15, 3, 1, {{-5, 6}, {1, 2}, {3, 5}}, {3, 5}, {-5, 6});
    testCase(16, 4, 2, {{2, 5}, {1, 4}, {3, 6}, {0, 1}}, {1, 4}, {3, 6});
    testCase(17, 5, 5, {{1, 2}, {2, 3}, {3, 1}, {1, 1}, {5, 4}}, {5, 4}, {1, 1});
    testCase(18, 2, 1, {{1, 2}, {1, 3}}, {1, 3}, {1, 2});
    testCase(19, 7, 4, {{1, 1}, {2, 3}, {5, 6}, {3, 4}, {0, 1}, {1, 2}, {2, 5}}, {1, 2}, {3, 4});
    testCase(20, 4, 3, {{2, 7}, {1, 1}, {3, 5}, {4, 1}}, {2, 7}, {4, 1});

    return 0;
}
