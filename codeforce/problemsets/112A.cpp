#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (tolower(a[i])>tolower(b[i])){
            cout<<1;
            return 0;
        }else if(tolower(a[i])<tolower(b[i])){
            cout<<-1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}