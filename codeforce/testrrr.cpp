#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int D, N;
    std::cin >> D >> N;

    std::vector<std::vector<int>> arr(N + 2, std::vector<int>(D));

    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < D; j++) {
            int k;
            std::cin >> k;
            arr[i][j] = k;
            if (i == 1) {
                arr[1][j] = arr[0][j] - arr[1][j];
            }
            if (i > 1 && arr[1][j] <= arr[i][j] && arr[0][j] >= arr[i][j]) {
                std::cout << "SUS\n";
            } else if (i > 1) {
                std::cout << "INNOCENT\n";
            }
        }
    }

    return 0;
}