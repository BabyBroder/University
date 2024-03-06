#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <iostream>
#define MAX 1000000
using namespace std;
int arr0[MAX];
int arr1[MAX];
int arr2[MAX];
int arr3[MAX];
int arr4[MAX];
int arr5[MAX];
int arr6[MAX];
int arr7[MAX];
int arr8[MAX];
int arr9[MAX];

void save_Array()
{
    FILE *fd = freopen("testLibraryC++.out", "w", stdout);
    for (int i = 0; i < MAX; i++)
        cout << arr0[i] << " ";
    cout << "\n";
    for (int i = 0; i < MAX; i++)
        cout << arr1[i] << " ";
    cout << "\n";
    for (int i = 0; i < MAX; i++)
        cout << arr2[i] << " ";
    cout << "\n";
    for (int i = 0; i < MAX; i++)
        cout << arr3[i] << " ";
    cout << "\n";
    for (int i = 0; i < MAX; i++)
        cout << arr4[i] << " ";
    cout << "\n";
    for (int i = 0; i < MAX; i++)
        cout << arr5[i] << " ";
    cout << "\n";
    for (int i = 0; i < MAX; i++)
        cout << arr6[i] << " ";
    cout << "\n";
    for (int i = 0; i < MAX; i++)
        cout << arr7[i] << " ";
    cout << "\n";
    for (int i = 0; i < MAX; i++)
        cout << arr8[i] << " ";
    cout << "\n";
    for (int i = 0; i < MAX; i++)
        cout << arr9[i] << " ";
    cout << "\n";
    fclose(fd);
}

void get_to_array()
{
    FILE *fd = freopen("array.in", "r", stdin);
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr0[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr3[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr4[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr5[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr6[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr7[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr8[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> arr9[i];
    }
    fclose(fd);
}

void Sorting()
{
    FILE *fp = freopen("TimeExecution.out", "a+", stdout);

    auto start = chrono::steady_clock::now();
    std::sort(arr0, arr0 + MAX);
    auto end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 1 using Library in C++: ";
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    std::sort(arr1, arr1 + MAX);
    ;
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 2 using Library in C++: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    std::sort(arr2, arr2 + MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 3 using Library in C++: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    std::sort(arr3, arr3 + MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 4 using Library in C++: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    std::sort(arr4, arr4 + MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 5 using Library in C++: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    std::sort(arr5, arr5 + MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 6 using Library in C++: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    std::sort(arr6, arr6 + MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 7 using Library in C++: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    std::sort(arr7, arr7 + MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 8 using Library in C++: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    std::sort(arr8, arr8 + MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 9 using Library in C++: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    std::sort(arr9, arr9 + MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 10 using Library in C++: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    fclose(fp);
}
int main()
{
    get_to_array();
    Sorting();
    save_Array();
    return 0;
}