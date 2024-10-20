#include <iostream>
#include <vector>
using namespace std;

void markInvalidRectangle(const vector<vector<int>> &matrix, vector<vector<bool>> &isValid, int x, int y, int w, int h)
{
    vector<vector<bool>> isConnected(isValid.size(), vector<bool>(isValid[0].size(), false));
    isConnected[x][y] = true;

    for (int i = x; i < x + h; ++i)
    {
        for (int j = y; j < y + w; ++j)
        {
            int arr1[4] = {0, 0, -1, 1};
            int arr2[4] = {1, -1, 0, 0};

            for(int z = 0; z < 4; z++){
                int a = i + arr1[z];
                int b = j + arr2[z];
                if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[0].size() && a >= x && a < x + h && b >= y && b < y + w)
                {
                    if (matrix[a][b] == 1 && isConnected[a][b])
                    {
                        isConnected[i][j] = true;
                        break;
                    }
                }
            }

            if (matrix[i][j] == 1 && isConnected[i][j])
            {
                //Cac phan tu trong hinh chu nhat khong hop le danh dau la false
                isValid[i][j] = false;

                for (int k = 0; k < 4; k++)
                {

                    int a = i + arr1[k];
                    int b = j + arr2[k];
                    if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[0].size())
                    {
                        isValid[a][b] = false;
                    }
                }
            }
        }
    }
}

void markValidRectangle(const vector<vector<int>> &matrix, vector<vector<bool>> &isValid, int x, int y, int w, int h)
{
    for (int i = x; i < x + h; ++i)
    {
        for (int j = y; j < y + w; ++j)
        {
            isValid[i][j] = false;
        }
    }
}

vector<vector<int>> findRectangles(const vector<vector<int>> &matrix, int m, int n)
{
    vector<vector<int>> result;
    vector<vector<bool>> isValid(m, vector<bool>(n, true));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // Neu phan tu hien tai la 1 va hop le
            if (matrix[i][j] == 1 && isValid[i][j])
            {
                bool validRectangle = true;
                int x = i;
                int y = j;
                int w = 0, h = 0;

                // Tim chieu rong cua hinh chu nhat
                while (y + w < n && matrix[x][y + w] == 1)
                {
                    ++w;
                }

                // Tim chieu cao cua hinh chu nhat
                while (x + h < m && matrix[x + h][y] == 1)
                {
                    ++h;
                }

                if(y - 1 > 0){
                    for(int a = x; a < x + h; a++){
                        if(matrix[a][y - 1] == 1 && matrix[a][y] == 1){
                            validRectangle = false;
                            break;
                        }
                    }
                }

                for(int a = y; a < y + w; a++){
                    if(x + h < m){
                        if(matrix[x + h][a] == 1 && matrix[x + h - 1][a] == 1){
                            validRectangle = false;
                            break;
                        }
                    }
                }

                for(int a = x; a < x + h; a++){
                    if(y + w < n){
                        if(matrix[a][y + w] == 1 && matrix[a][y + w - 1] == 1){
                            validRectangle = false;
                            break;
                        }
                    }
                }

                // Kiem tra hinh chu nhat co hop le khong
                for (int a = x; a < x + h; a++)
                {
                    for (int b = y; b < y + w; b++)
                    {
                        if (matrix[a][b] == 0 || !isValid[a][b])
                        {
                            validRectangle = false;
                            break;
                        }
                    }
                }

                if(w < 2 || h < 2){
                    validRectangle = false;
                }

                if(!validRectangle){
                    markInvalidRectangle(matrix, isValid, x, y, w, h);
                    continue;
                }

                // Them hinh chu nhat vao ket qua
                result.push_back({y, x, w, h});
                markValidRectangle(matrix, isValid, x, y, w, h);
            }
        }
    }

    return result;
}


// Hàm chạy các test case
void runTestCases() {
    vector<vector<vector<int>>> testCases = {
        // Test case 1
        {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        // Test case 2
        {
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 1, 1},
            {0, 0, 1, 1}
        },
        // Test case 3
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        // Test case 4
        {
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1}
        },
        // Test case 5
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        // Test case 6
        {
            {1, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 1},
            {0, 0, 0, 1}
        },
        // Test case 7
        {
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 0, 1},
            {1, 0, 0, 0}
        },
        // Test case 8
        {
            {1, 1, 1, 0},
            {1, 0, 1, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 1}
        },
        // Test case 9
        {
            {1, 0, 0, 1},
            {1, 1, 0, 1},
            {0, 1, 1, 1},
            {1, 1, 1, 1}
        },
        // Test case 10
        {
            {1, 1, 1, 1, 1},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1}
        }
    };

    // Chạy từng test case và in kết quả
    for (int t = 0; t < testCases.size(); ++t) {
        vector<vector<int>> matrix = testCases[t];
        int m = matrix.size();
        int n = matrix[0].size();

        cout << "Test case " << t + 1 << ":" << endl;
        cout << "Input matrix:" << endl;
        for (const auto &row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        vector<vector<int>> rectangles = findRectangles(matrix, m, n);

        cout << "List of rectangles [x, y, w, h]:" << endl;
        for (const auto &rect : rectangles) {
            cout << "[" << rect[0] << ", " << rect[1] << ", " << rect[2] << ", " << rect[3] << "]" << endl;
        }
        cout << "---------------------------------" << endl;
    }
}

int main() {
    runTestCases();  // Chạy tất cả các test case
    return 0;
}
