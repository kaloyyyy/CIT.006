#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string n;
    int count;
    cin>>count;
    cin>>n;
     count = 0;
    char prev;
    for (int i = 0; i < n.size(); i++) {
        if (prev == n[i]){
            count++;
        }
        prev = n[i];
    }
    cout<<count;
}