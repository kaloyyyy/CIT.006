#include <iostream>
#include <vector>
#include <algorithm>

bool isMatch(const std::vector<int>& pizza1, const std::vector<int>& pizza2) {
    // Check if any rotation of pizza1 matches pizza2
    for (int i = 0; i < pizza1.size(); ++i) {
        if (pizza1 == pizza2) {
            return true;
        }
        std::rotate(pizza1.begin(), pizza1.begin() + 1, pizza1.end());
    }
    return false;
}

int findUniquePizza(int n, const std::vector<int>& myPizza, const std::vector<std::vector<int>>& pizzas) {
    // Create all possible rotations
    std::vector<std::vector<int>> rotations;
    rotations.push_back(myPizza);
    for (int i = 1; i < n; ++i) {
        std::vector<int> tmp = myPizza;
        std::rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
        rotations.push_back(tmp);
    }

    // Check for matches with PizzaBot descriptions
    for (int i = 0; i < pizzas.size(); ++i) {
        int matches = 0;
        for (const auto& rotation : rotations) {
            if (isMatch(rotation, pizzas[i])) {
                matches++;
            }
        }
        if (matches == 1) {
            return i + 1; // Pizza found, return its index (1-based)
        }
    }

    // Should not reach here if conditions are correct
    throw std::runtime_error("Unique pizza not found!");
}

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int s, n;
        std::cin >> s >> n;

        std::vector<int> myPizza(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> myPizza[i];
        }

        std::vector<std::vector<int>> pizzas(s, std::vector<int>(n));
        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> pizzas[i][j];
            }
        }

        try {
            int uniquePizza = findUniquePizza(n, myPizza, pizzas);
            std::cout << uniquePizza << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
