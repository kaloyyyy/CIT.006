#include <bits/stdc++.h>
using namespace std;


void solve(vector<bool> *done, vector<string> *words, basic_string<char> &basicString) {
    auto cWord = *words;
    for (int i = 0; i < words->size(); i++) {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<string>words;
    char s[100];
    cin.getline(s, 100);

    // Pointer to point the word returned by the strtok() function.
    char * p;
    // Here, the delimiter is white space.
    p = strtok(s, ",");
    while (p != nullptr) {
        cout << p << endl;
        words.emplace_back(p);
        p = strtok(nullptr, ",");
    }
    vector<bool>done;
    solve(&done, &words, words[0]);
}