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

int main() {
    int m;
    cin >> m;

    vector<vector<int>> matrix(m, vector<int>(m));
    vector<vector<int>> originalMatrix(m, vector<int>(m));

    // Nhập dữ liệu ma trận
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            originalMatrix[i][j] = matrix[i][j]; // Lưu trạng thái ban đầu
        }
    }

    int cycleCount = 0;

    // Lặp lại Arnold's Cat Map cho đến khi ma trận trở về trạng thái ban đầu
    do {
        arnoldTransform(matrix, m);
        cycleCount++;
    } while (!isEqual(matrix, originalMatrix, m));

    // Xuất ra hệ số chu kỳ k
    cout << cycleCount << endl;

    return 0;
}
