#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char in;
    string out;
    cin>>out;
    int arr[51];
    int j = 0;
    for (int i = 0; i < out.size(); i+=2) {
        arr[j] = out[i] - '0';
        j++;
    }
    sort(arr, arr+j);
    for (int i = 0; i < j; i++) {
        cout << arr[i];
        if (i < j-1) {
            cout << "+";
        }
    }
}