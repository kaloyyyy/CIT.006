#include <bits/stdc++.h>
using namespace std;
int a, n;

int mod(int x, int b) {
    int tmp = x / b;
    return x - (b * tmp);
}
int stringMod(string num, int m)
{
    int ans = 0;
    for (char i : num)
        ans = (ans * 10 + (int)i - '0') % m;

    return ans;
}
int modExp(int x, int exp, int m){
    if (exp == 0)return 1%m;
    long long u = modExp(x, exp/2, m);
    u = (u*u)%m;
    return u;
}
int g(int seed) {
    int answer = mod((modExp(seed, 2, n) + mod(a,n)), n);
    return answer;
}

int gRecursive(int seed) {
    int x = seed;
    int answer = ((x*x) + a)%n;
    if (seed == answer) {
        if(answer == g(answer) )return answer;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> a;
    vector<int> arr;
    int count = 0;
    if (a != 1) {
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
        if (count <= 100000) {
            cout << count << "\n";
            for (int i: arr) {
                cout << i << "\n";
            }
        } else {
            cout << "ABSOLUTELY WAY TOO MANY";
        }
    } else {
        cout << 0;
    }
}