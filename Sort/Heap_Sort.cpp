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

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void save_Array()
{
    FILE *fd = freopen("testHeapSort.out", "w", stdout);
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
    heapSort(arr0, MAX);
    auto end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 1 using Heap Sort: ";
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    heapSort(arr1, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 2 using Heap Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    heapSort(arr2, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 3 using Heap Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    heapSort(arr3, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 4 using Heap Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    heapSort(arr4, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 5 using Heap Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    heapSort(arr5, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 6 using Heap Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    heapSort(arr6, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 7 using Heap Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    heapSort(arr7, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 8 using Heap Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    heapSort(arr8, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 9 using Heap Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    heapSort(arr9, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 10 using Heap Sort: ";
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