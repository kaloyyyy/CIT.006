#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;

    int upper_count = count_if(s.begin(), s.end(), ::isupper);
    int lower_count = count_if(s.begin(), s.end(), ::islower);

    if (upper_count > lower_count) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    } else {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }

    cout << s << "\n";
}