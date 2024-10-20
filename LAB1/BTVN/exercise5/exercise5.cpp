#include <iostream>
#include <vector>
using namespace std;

/**
 * Marks the invalid rectangle in the validity matrix.
 *
 * @param matrix The original binary matrix.
 * @param isValid The matrix that indicates which cells are part of valid rectangles.
 * @param x The starting row of the rectangle.
 * @param y The starting column of the rectangle.
 * @param w The width of the rectangle.
 * @param h The height of the rectangle.
 */
void markInvalidRectangle(const vector<vector<int>> &matrix, vector<vector<bool>> &isValid, int x, int y, int w, int h)
{
    // Create a connected matrix to check adjacency
    vector<vector<bool>> isConnected(isValid.size(), vector<bool>(isValid[0].size(), false));
    isConnected[x][y] = true;

    // Iterate over the rectangle's area
    for (int i = x; i < x + h; ++i)
    {
        for (int j = y; j < y + w; ++j)
        {
            // Define the movements to check adjacent cells
            int arr1[4] = {0, 0, -1, 1};
            int arr2[4] = {1, -1, 0, 0};

            // Check adjacency for valid connection
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

            // If the current cell is valid and connected
            if (matrix[i][j] == 1 && isConnected[i][j])
            {
                // Mark the current cell and its neighbors as invalid
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

/**
 * Marks a valid rectangle in the validity matrix.
 *
 * @param matrix The original binary matrix.
 * @param isValid The matrix that indicates which cells are part of valid rectangles.
 * @param x The starting row of the rectangle.
 * @param y The starting column of the rectangle.
 * @param w The width of the rectangle.
 * @param h The height of the rectangle.
 */
void markValidRectangle(const vector<vector<int>> &matrix, vector<vector<bool>> &isValid, int x, int y, int w, int h)
{
    // Mark all cells in the specified rectangle as valid (part of a valid rectangle)
    for (int i = x; i < x + h; ++i)
    {
        for (int j = y; j < y + w; ++j)
        {
            isValid[i][j] = false;  // Marking as false to indicate it's been processed
        }
    }
}

/**
 * Finds all valid rectangles in a binary matrix.
 *
 * @param matrix The input binary matrix.
 * @param m The number of rows in the matrix.
 * @param n The number of columns in the matrix.
 * @return A vector containing the list of rectangles defined by their top-left corner (x, y), width (w), and height (h).
 */
vector<vector<int>> findRectangles(const vector<vector<int>> &matrix, int m, int n)
{
    vector<vector<int>> result; // Resultant list of rectangles
    vector<vector<bool>> isValid(m, vector<bool>(n, true)); // Validity matrix

    // Iterate through the matrix
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // If the current cell is 1 and valid
            if (matrix[i][j] == 1 && isValid[i][j])
            {
                bool validRectangle = true; // Flag for rectangle validity
                int x = i; // Starting x-coordinate
                int y = j; // Starting y-coordinate
                int w = 0, h = 0; // Width and height of the rectangle

                // Find the width of the rectangle
                while (y + w < n && matrix[x][y + w] == 1)
                {
                    ++w;
                }

                // Find the height of the rectangle
                while (x + h < m && matrix[x + h][y] == 1)
                {
                    ++h;
                }

                // Check if there is a valid rectangle above
                if (y - 1 >= 0) {
                    for (int a = x; a < x + h; a++) {
                        if (matrix[a][y - 1] == 1 && matrix[a][y] == 1) {
                            validRectangle = false;
                            break;
                        }
                    }
                }

                // Check if there is a valid rectangle below
                for (int a = y; a < y + w; a++) {
                    if (x + h < m) {
                        if (matrix[x + h][a] == 1 && matrix[x + h - 1][a] == 1) {
                            validRectangle = false;
                            break;
                        }
                    }
                }

                // Check if there is a valid rectangle to the right
                for (int a = x; a < x + h; a++) {
                    if (y + w < n) {
                        if (matrix[a][y + w] == 1 && matrix[a][y + w - 1] == 1) {
                            validRectangle = false;
                            break;
                        }
                    }
                }

                // Validate if the rectangle is entirely valid
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

                // Check minimum dimensions for a valid rectangle
                if (w < 2 || h < 2)
                {
                    validRectangle = false;
                }

                // If the rectangle is invalid, mark its area in the validity matrix
                if (!validRectangle)
                {
                    markInvalidRectangle(matrix, isValid, x, y, w, h);
                    continue;
                }

                // Add the rectangle to the result list
                result.push_back({y, x, w, h});
                markValidRectangle(matrix, isValid, x, y, w, h); // Mark it as processed
            }
        }
    }

    return result; // Return the list of found rectangles
}

int main()
{
    int m, n;
    cout << "Enter the size of the matrix (m n): ";
    cin >> m >> n;

    // Initialize the binary matrix
    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter the binary matrix:" << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j]; // Input the matrix values
        }
    }

    // Find all valid rectangles in the matrix
    vector<vector<int>> rectangles = findRectangles(matrix, m, n);

    // Output the list of rectangles
    cout << "List of rectangles [x, y, w, h]:" << endl;
    for (const auto &rect : rectangles)
    {
        cout << "[" << rect[0] << ", " << rect[1] << ", " << rect[2] << ", " << rect[3] << "]" << endl;
    }

    return 0;
}

// 0 0 1 0 0 0 0 0 0 1
// 0 0 1 0 1 0 0 1 1 0
// 0 0 0 0 0 0 0 1 1 0
// 1 1 1 0 0 0 0 0 1 0
// 1 1 1 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 1 1 0 0 0
// 0 0 0 0 0 1 1 0 0 0