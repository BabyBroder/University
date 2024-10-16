#include <vector>
#include <tuple>
#include "TamGiac.cpp"

void runTestCase(const std::vector<std::tuple<std::vector<float>, float, float>>& testCases) {
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [points, angle, length] = testCases[i];

        TamGiac tamgiac;
        tamgiac.SetPoints(points[0], points[1], points[2], points[3], points[4], points[5]);

        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "Toa do ban dau:\n";
        tamgiac.Xuat();

        tamgiac.TinhTien(angle, length);

        std::cout << "Toa do sau khi tinh tien:\n";
        tamgiac.Xuat();
        std::cout << "----------------------------------------------------------\n";
    }
}

int main() {
    std::vector<std::tuple<std::vector<float>, float, float>> testCases = {
        { {0, 0, 1, 0, 0, 1}, 45, 4 },  // Test Case 1
        { {1, 1, 3, 1, 1, 4}, 90, 2 }, // Test Case 2
        { {2, 2, 5, 2, 2, 6}, 180, 3 }, // Test Case 3
        { {3, 3, 4, 4, 3, 5}, 30, 5 },  // Test Case 4
        { {0, 0, 0, 1, 1, 1}, 60, 1 },  // Test Case 5
        { {0, 0, -1, 0, 0, -1}, 90, 3 }, // Test Case 6
        { {1, 0, 2, 1, 0, 2}, 45, 10 },  // Test Case 7
        { {0, 0, 3, 3, 0, 3}, 0, 1 },   // Test Case 8
        { {1, 1, 2, 2, 3, 3}, 180, 2 },  // Test Case 9
        { {4, 4, 5, 5, 6, 6}, 90, 4 },   // Test Case 10
    };

    runTestCase(testCases);
    return 0;
}
