#include <bits/stdc++.h>
using namespace std;
int a, n;
int gAlt(int seed){
    int x = a + (seed*seed);
    return x - n*(x/n);
}
int g(int seed){
    int x = n-seed;
    return ((x*x)%n + a%n)%n;
}
int gMath(int seed){
    int x = n-seed+1;
    return x;
}
int gRecursive(int seed){
    int x = n-seed;
    int answer = ((x*x) + a)%n;
    if (seed == answer){
        cout<<"answer "<<answer<<"  ";
        cout<<"seed "<<seed<<endl;
        cout<<"diff: "<<x+1<<"   ";
        cout<<gMath(seed)<<endl;
        return answer;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>a;
    vector<int>arr;
    int count = 0;
    if (a!=1) {
        for (int i = 0; i < n; i++) {
            int x = gRecursive(i);
            if (x != -1) {
                count++;
                arr.push_back(x);
            }
            if (count > 100000) {
                break;
            }
        }
        if (count<=100000){
            cout<<count<<"\n";
            for (int i : arr) {
                cout<<i<<"\n";
            }
        }else{
            cout<<"ABSOLUTELY WAY TOO MANY";
        }
    }else{
        cout<<0;
    }
}