#include <iostream>
#include <vector>

/**
 * @class SubsequenceCounter
 * @brief A class to count occurrences of one sequence as a subsequence in another.
 * 
 * The SubsequenceCounter class provides functionality to count how many times
 * a vector A appears as a contiguous subsequence in another vector B. It also
 * provides the starting indices of each occurrence.
 */
class SubsequenceCounter {
private:
    std::vector<int> A;  ///< The vector representing the subsequence.
    std::vector<int> B;  ///< The vector in which to search for subsequences.

public:
    /**
     * @brief Constructor to initialize vectors A and B.
     * 
     * This constructor initializes the SubsequenceCounter with the provided 
     * vectors A and B.
     * 
     * @param a A vector representing the subsequence to be searched for.
     * @param b A vector in which to search for occurrences of the subsequence.
     */
    SubsequenceCounter(const std::vector<int>& a, const std::vector<int>& b) : A(a), B(b) {}

    /**
     * @brief Count occurrences of subsequence A in vector B.
     * 
     * This function traverses through vector B using a sliding window of size 
     * equal to A, checking for matches. It counts the occurrences of A in B 
     * and stores the starting indices of each occurrence.
     * 
     * @return A pair containing:
     *         - The count of occurrences of A in B.
     *         - A vector of starting indices where A occurs in B.
     */
    std::pair<int, std::vector<int>> countSubsequenceOccurrences() {
        int count = 0;
        std::vector<int> indices;
        int aSize = A.size();
        int bSize = B.size();

        // Traverse through array B using a sliding window of size equal to A
        for (int i = 0; i <= bSize - aSize; ++i) {
            bool isMatch = true;

            // Check if the current window in B matches array A
            for (int j = 0; j < aSize; ++j) {
                if (B[i + j] != A[j]) {
                    isMatch = false;
                    break;
                }
            }

            // If a match is found, count it and store the starting index
            if (isMatch) {
                count++;
                indices.push_back(i);
            }
        }

        return {count, indices};
    }
};

int main() {
    int aSize, bSize;
    
    // Input: sizes of arrays A and B
    std::cout << "Enter the size of array A and B: ";
    std::cin >> aSize >> bSize;

    std::vector<int> A(aSize), B(bSize);

    // Input: elements of array A
    std::cout << "Enter the elements of array A: ";
    for (int i = 0; i < aSize; ++i) {
        std::cin >> A[i];
    }

    // Input: elements of array B
    std::cout << "Enter the elements of array B: ";
    for (int i = 0; i < bSize; ++i) {
        std::cin >> B[i];
    }

    // Create a SubsequenceCounter object
    SubsequenceCounter counter(A, B);

    // Get the count and starting indices of subsequence occurrences
    auto result = counter.countSubsequenceOccurrences();

    // Output the number of times array A appears in array B
    std::cout << "Number of occurrences of A in B: " << result.first << std::endl;

    // Output the starting indices of these occurrences
    std::cout << "Starting indices: ";
    for (int index : result.second) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
