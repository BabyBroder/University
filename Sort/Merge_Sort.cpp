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

void merge(int array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void save_Array()
{
    FILE *fd = freopen("testMergeSort.out", "w", stdout);
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
    mergeSort(arr0, 0, MAX);
    auto end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 1 using Merge Sort: ";
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    mergeSort(arr1, 0, MAX);;
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 2 using Merge Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    mergeSort(arr2, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 3 using Merge Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    mergeSort(arr3, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 4 using Merge Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    mergeSort(arr4, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 5 using Merge Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    mergeSort(arr5, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 6 using Merge Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    mergeSort(arr6, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 7 using Merge Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    mergeSort(arr7, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 8 using Merge Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    mergeSort(arr8, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 9 using Merge Sort: ";
    diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    mergeSort(arr9, 0, MAX);
    end = chrono::steady_clock::now();
    std::cout << "Time of sorting array 10 using Merge Sort: ";
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