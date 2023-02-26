#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> chars; // stores unique characters in the equation
int digit[26]; // stores digit assigned to each character

bool is_valid(int a, int b, int res, char op) {
    if (op == '+') {
        return (a + b == res);
    } else if (op == '-') {
        return (a - b == res);
    } else if (op == '*') {
        return (a * b == res);
    } else {
        return (a / b == res);
    }
}

bool solve(int idx, int used, int a, int b, int res, char op) {
    if (idx == chars.size()) {
        return is_valid(a, b, res, op);
    }

    char c = chars[idx];

    for (int i = 0; i <= 9; i++) {
        if ((used & (1 << i)) == 0) {
            digit[c - 'A'] = i;
            if (solve(idx + 1, used | (1 << i), a, b, res, op)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int C;
        string equation;
        cin >> C >> equation;

        // extract unique characters in the equation
        chars.clear();
        for (char c : equation) {
            if (c >= 'A' && c <= 'Z' && find(chars.begin(), chars.end(), c) == chars.end()) {
                chars.push_back(c);
            }
        }
        sort(chars.begin(), chars.end());

        // solve the equation
        int a = 0, b = 0, res = 0;
        char op = '\0';

        int i = 0;
        while (equation[i] >= 'A' && equation[i] <= 'Z') {
            a = a * 10 + digit[equation[i] - 'A'];
            i++;
        }

        op = equation[i];
        i++;

        while (equation[i] >= 'A' && equation[i] <= 'Z') {
            b = b * 10 + digit[equation[i] - 'A'];
            i++;
        }

        i++; // skip '='

        while (i < equation.length() && equation[i] >= 'A' && equation[i] <= 'Z') {
            res = res * 10 + digit[equation[i] - 'A'];
            i++;
        }

        solve(0, 0, a, b, res, op);

        // output the results
        for (char c : chars) {
            cout << c << " " << digit[c - 'A'] << endl;
        }
    }

    return 0;
}
