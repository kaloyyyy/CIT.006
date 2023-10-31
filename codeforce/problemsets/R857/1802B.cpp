#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, tcount = 0, side = 0;
        cin >> n;
        int one = 0, free = 0, done = 0;
        int check = 0;
        bool l1 = false, l2 = false;
        for (int j = 0; j < n; j++) {
            int x;

            cin >> x;
            if (x == 1) {
                if (free == 0) {
                    one++;
                    tcount++;
                } else {
                    free--;
                }
                side ++;
            } else if (x == 2) {
                l2 = true;
                if (side <=2){
                    check ++;
                }
                done += side;
                free = tcount - (done/2);
                if (free>0){
                    free--;
                }
                one = 0;
                side = 0;
            }
        }
        cout << tcount << "\n";
    }
}