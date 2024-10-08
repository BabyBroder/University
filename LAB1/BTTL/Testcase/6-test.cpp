#include <iostream>
#include <vector>
#include <utility>

// Function to count occurrences of subsequence A in array B
std::pair<int, std::vector<int>> countSubsequenceOccurrences(const std::vector<int> &A, const std::vector<int> &B)
{
    int count = 0;
    std::vector<int> indices;
    int aSize = A.size();
    int bSize = B.size();

    // Traverse through array B using a sliding window of size equal to A
    for (int i = 0; i <= bSize - aSize; ++i)
    {
        bool isMatch = true;

        // Check if the current window in B matches array A
        for (int j = 0; j < aSize; ++j)
        {
            if (B[i + j] != A[j])
            {
                isMatch = false;
                break;
            }
        }

        // If a match is found, count it and store the starting index
        if (isMatch)
        {
            count++;
            indices.push_back(i);
        }
    }

    return {count, indices};
}

// Helper function to run test cases
void runTestCase(const std::vector<int> &A, const std::vector<int> &B, int expectedCount, const std::vector<int> &expectedIndices)
{
    auto result = countSubsequenceOccurrences(A, B);

    // Output the result of the test case
    std::cout << "A: {";
    for (int a : A)
        std::cout << a << " ";
    std::cout << "} B: {";
    for (int b : B)
        std::cout << b << " ";
    std::cout << "} -> Expected: " << expectedCount << " times at indices {";
    for (int idx : expectedIndices)
        std::cout << idx << " ";
    std::cout << "}, Got: " << result.first << " times at indices {";
    for (int idx : result.second)
        std::cout << idx << " ";
    std::cout << "}\n";
}

int main()
{
    std::vector<std::pair<std::vector<int>, std::vector<int>>> testCases = {
        {{1, 2}, {1, 2, 3, 4, 1, 2}},
        {{1, 2, 3}, {1, 2, 3, 4, 1, 2, 3, 5}},
        {{2, 3}, {1, 2, 3, 2, 3, 4}},
        {{1}, {1, 1, 1, 1}},
        {{1, 3}, {1, 2, 3, 4, 1, 2, 3}},
        {{4, 5}, {4, 5, 6, 4, 5, 7}},
        {{3, 4, 5}, {1, 2, 3, 4, 5}},
        {{1, 2, 3}, {1, 2, 4, 5, 1, 2, 3, 6}},
        {{2, 2}, {2, 2, 2, 2}},
        {{5, 6}, {1, 2, 3, 4, 5, 6}},
        {{1, 2}, {3, 4, 1, 2, 1, 2}},
        {{2, 3}, {1, 2, 2, 3, 4, 5}},
        {{9, 9, 9}, {9, 9, 9, 9, 9, 9}},
        {{4, 4}, {4, 4, 4, 4, 4}},
        {{7, 8}, {5, 6, 7, 8, 9, 7, 8}},
        {{2}, {1, 2, 3, 4}},
        {{3}, {3, 3, 3, 3}},
        {{2, 3, 4}, {2, 3, 4, 5, 6, 2, 3, 4}},
        {{5}, {1, 2, 5, 5, 5}},
        {{6, 7}, {6, 6, 7, 8, 6, 7}}};

    std::vector<int> expectedCounts = {2, 2, 2, 4, 2, 2, 1, 1, 3, 1, 2, 1, 4, 4, 2, 1, 4, 2, 3, 2};
    std::vector<std::vector<int>> expectedIndices = {
        {0, 4}, {0, 4}, {1, 3}, {0, 1, 2, 3}, {0, 4}, {0, 3}, {2}, {5}, {0, 1, 2}, {4}, {2, 4}, {2}, {0, 1, 2, 3}, {0, 1, 2, 3}, {2, 5}, {1}, {0, 1, 2, 3}, {0, 5}, {2, 3, 4}, {1, 4}};

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        runTestCase(testCases[i].first, testCases[i].second, expectedCounts[i], expectedIndices[i]);
    }

    return 0;
}
