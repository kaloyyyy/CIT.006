#include <iostream>
using namespace std;

int main() {
    int arr[9];
    cout << "enter 10 ints\n";
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
        cin >> arr[i];
    }
    return 0;
}