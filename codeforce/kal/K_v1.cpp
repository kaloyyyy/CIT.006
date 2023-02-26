#include <bits/stdc++.h>
using namespace std;
long long a, n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>a;
    set<long long>arr;
    long long j = n/2;

        for (long long i = 0; i < j; i++) {
            long long value = (i * i-i);
            if (value % n == n-a){
                arr.insert(i);
                arr.insert(n - i + 1);
            }
            if (arr.size() > 100000) {
                break;
            }
            value = (j * j - j);
            if (value % n == n-a){
                arr.insert(j);
                arr.insert(n - j + 1);
            }
            if (arr.size() > 100000) {
                break;
            }
            j--;
        }
        int count = arr.size()  ;
        if (count<100000){
            cout<<arr.size()<<"\n";
            for (int i : arr) {
                cout<<i<<"\n";
            }
        }else{
            cout<<"ABSOLUTELY WAY TOO MANY";
        }

    return 0;
}