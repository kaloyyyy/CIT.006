#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin>>s;
    for (char c : s) {
        if (c != 'A' && c != 'O' && c != 'Y' && c != 'E' && c != 'I' && c != 'U' && c != 'a' && c != 'o' && c != 'y'
                && c != 'e' && c != 'i' && c != 'u') {
            cout << '.' << (char)tolower(c);
        }
    }
}