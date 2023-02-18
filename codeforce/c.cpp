#include <iostream>
using namespace std;

int main() {
    string arr;
    int T, K;
    cin >>T;
    for (int j = 0; j < T; j++) {
        cin >>K>> arr;
        int counter = 0;
        for (int i = 0; arr[i] != '\0'; i++) {
            if (arr[i] != arr[i + 1]) {
                counter++;
            }
        }
        if (arr[0] == '1') {
            cout << counter - 1 << "\n";
        } else {
            cout << counter << "\n";
        }
    }
    return 0;
}