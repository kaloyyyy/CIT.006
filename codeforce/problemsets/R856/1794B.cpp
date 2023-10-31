#include <bits/stdc++.h>
using namespace std;

void check(vector<int> &arr, int j) {
    if (arr[j - 1] <= arr[j]) {
        if (arr[j] % arr[j - 1] == 0) {
            arr[j - 1]++;
        }
        if (arr[j] % arr[j - 1] == 0) {
            check(arr, j);
        }
    }
    if (j > 1) {
        check(arr, j - 1);
    }
}

void printReverse(stack<int> &arr) {
    while (!arr.empty()) {
        int x = arr.top();
        arr.pop();
        printReverse(arr);
        cout << x<<" ";
    }
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        stack<int> arr;
        vector<bool> oddeven(n, false);
        int evenCount = 0, x;
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 1){
                x++;
            }
            if (j > 0) {
                while (x % arr.top() == 0) {
                    x++;
                }

            }
            arr.push(x);
        }
        printReverse(arr);
        cout << "\n";
    }
}