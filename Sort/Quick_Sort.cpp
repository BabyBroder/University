#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <iostream>
#define MAX 1000000
using namespace std;
float arr0[MAX];
float arr1[MAX];
float arr2[MAX];
float arr3[MAX];
float arr4[MAX];
float arr5[MAX];
float arr6[MAX];
float arr7[MAX];
float arr8[MAX];
float arr9[MAX];

int partition(float a[], int low, int high) {
    double pivot = a[high];
    
    int i = low-1;
    for (int j = low; j<high; j++)
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[i+1], a[high]);
    return i+1;
}

int partition_r(float a[], int low, int high) {
    srand(time(NULL));
    int pivot = low + rand() % (high-low);
    swap(a[pivot], a[high]);
    return partition(a, low, high);
}

void quickSort(float a[], int low, int high) {
    if (low < high) {
        int pivot = partition_r(a, low, high);
        quickSort(a, low, pivot-1);
        quickSort(a, pivot+1, high);
    }
}
void save_Array()
{
    FILE *fd = freopen("testQuickSort.out", "w", stdout);
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
    quickSort(arr0, 0, MAX);
    auto end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 1 using Quick Sort: ";
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    quickSort(arr1, 0, MAX);
    ;
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 2 using Quick Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    quickSort(arr2, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 3 using Quick Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    quickSort(arr3, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 4 using Quick Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    quickSort(arr4, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 5 using Quick Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    quickSort(arr5, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 6 using Quick Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    quickSort(arr6, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 7 using Quick Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    quickSort(arr7, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 8 using Quick Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    quickSort(arr8, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 9 using Quick Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    quickSort(arr9, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 10 using Quick Sort: ";
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