#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k, oneCnt = 0, twoCnt = 0, threeCnt=0;
    cin>>n;
    vector<int>arr;
    map<int, int>mapArr;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        arr.push_back(k);
        if (k==1)oneCnt++;
        if (k==2)twoCnt++;
        if(k==3)threeCnt++;
    }
    for (auto x:arr) {
        cout<<x<<" ";
    }
    cout<<"done\n";
}