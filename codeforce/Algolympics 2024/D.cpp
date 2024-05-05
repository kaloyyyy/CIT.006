#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find and print your pizza for each test case
void findMyPizza(int t, vector<vector<int>>& testCases) {
    for (int i = 0; i < t; ++i) {
        int s = testCases[i][0];
        int n = testCases[i][1];
        vector<int> myPizzaToppings(testCases[i].begin() + 2, testCases[i].begin() + 2 + n);

        // Check each pizza described by PizzaBot
        for (int j = 0; j < s; ++j) {
            vector<int> pizzaBotToppings(testCases[i].begin() + 3 + j * n, testCases[i].begin() + 3 + (j + 1) * n);

            // Check all rotations of PizzaBot's toppings
            bool matchFound = false;
            for (int k = 0; k < n; ++k) {
                rotate(pizzaBotToppings.begin(), pizzaBotToppings.begin() + k, pizzaBotToppings.end());

                // If the rotated toppings match your pizza, print the pizza number and set matchFound to true
                if (pizzaBotToppings == myPizzaToppings) {
                    cout << j + 1 << endl;
                    matchFound = true;
                    break;
                }
            }

            // If match is found, break out of the outer loop
            if (matchFound) {
                break;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> testCases;

    for (int i = 0; i < t; ++i) {
        int s, n;
        cin >> s >> n;

        vector<int> pizzaData;
        pizzaData.push_back(s);
        pizzaData.push_back(n);

        for (int j = 0; j < n; ++j) {
            int topping;
            cin >> topping;
            pizzaData.push_back(topping);
        }

        for (int j = 0; j < s; ++j) {
            for (int k = 0; k < n; ++k) {
                int topping;
                cin >> topping;
                pizzaData.push_back(topping);
            }
        }

        testCases.push_back(pizzaData);
    }

    // Find and print your pizza for each test case
    findMyPizza(t, testCases);

    return 0;
}
