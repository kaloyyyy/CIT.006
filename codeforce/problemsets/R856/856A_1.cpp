#include <bits/stdc++.h>
using namespace std;

void isPalindrome(string S) {
    for (int i = 0; i < S.size() / 2; i++) {
        if (S[i] != S[S.size() - i - 1]) {
            cout << "NO\n";
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    string ans;
    vector<string>words;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        string first;
        vector<string>set(2*n-2);
        vector<char>wordcopy(n);
        bool yes = false;
        for (int j = 0; j < 2*n - 2; j++) {
            string word;
            cin >> word;
            if(j>0) {
                if (j % 2 == 0) {
                    
                }else{

                }
            }
            string prev= word;
        }
    }
}