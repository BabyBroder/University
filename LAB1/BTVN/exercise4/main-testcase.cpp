#include <iostream>
#include <vector>
using namespace std;

// Hàm kiểm tra nếu hai ma trận bằng nhau
bool isEqual(const vector<vector<int>>& A, const vector<vector<int>>& B, int m) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

// Hàm áp dụng Arnold's Cat Map
void arnoldTransform(vector<vector<int>>& matrix, int m) {
    vector<vector<int>> temp(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int newX = (2 * i + j) % m;
            int newY = (i + j) % m;
            temp[newX][newY] = matrix[i][j];
        }
    }
    matrix = temp; // Cập nhật ma trận sau phép biến đổi
}

// Hàm chạy test case
void runTestCase(int caseNumber, int m, const vector<vector<int>>& initialMatrix) {
    cout << "Test case " << caseNumber << " with m = " << m << ":" << endl;
    cout << "Initial Matrix:" << endl;
    for (const auto& row : initialMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> matrix = initialMatrix; // Khởi tạo ma trận từ dữ liệu ban đầu
    vector<vector<int>> originalMatrix = initialMatrix; // Lưu trạng thái ban đầu

    int cycleCount = 0;

    // Lặp lại Arnold's Cat Map cho đến khi ma trận trở về trạng thái ban đầu
    do {
        arnoldTransform(matrix, m);
        cycleCount++;
    } while (!isEqual(matrix, originalMatrix, m));

    // Xuất ra hệ số chu kỳ k
    cout << "Cycle count = " << cycleCount << endl;
    cout << "------------------------------------" << endl; // Ngăn cách giữa các test case
}

int main() {
    // Các test case
    vector<pair<int, vector<vector<int>>>> testCases = {
        {2, {{1, 2}, {3, 4}}},                      // Test case 1
        {3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}},     // Test case 2
        {4, {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}}, // Test case 3
        {1, {{1}}},                                  // Test case 4
        {5, {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}}}, // Test case 5
        {3, {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}}}, // Test case 6
        {4, {{1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}}}, // Test case 7
        {2, {{5, 6}, {7, 8}}},                       // Test case 8
        {3, {{3, 6, 9}, {12, 15, 18}, {21, 24, 27}}}, // Test case 9
        {2, {{-1, -2}, {-3, -4}}}                   // Test case 10
    };

    for (int i = 0; i < testCases.size(); i++) {
        runTestCase(i + 1, testCases[i].first, testCases[i].second);
    }

    return 0;
}
