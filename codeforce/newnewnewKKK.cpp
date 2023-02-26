#include <bits/stdc++.h>
using namespace std;
long long a, n;
long long gAlt(long long seed){
    long long x = a + (seed*seed);
    long long y = (x/n);
    return x - n*(y);
}
long long gRecursive(int seed){
    long long answer = gAlt(seed);
    if (seed == answer){
        return answer;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>a;
    vector<long long>arr;
    int count = 0;
    long long end = n;
    if (a!=1) {
        for (int i = a; i <= end; i++) {
            long long x = gRecursive(i);
            if (x != -1) {
                count++;
                arr.push_back(x);
                if (count == 2) {
                    end = arr[0] + arr[1] - a;
                }
            }
            if (count > 100000) {
                break;
            }
        }
        if (count<=100000){
            cout<<count*2<<"\n";
            for (long long i : arr) {
                cout<<i<<"\n";
            }
            for (long long i : arr) {
                cout<<n-i+1<<"\n";
            }
        }else{
            cout<<"ABSOLUTELY WAY TOO MANY";
        }
    }else{
        cout<<0;
    }
}