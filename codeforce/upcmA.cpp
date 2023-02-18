#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int D, N, k;
    cin >> D >> N;
    bool sussy;
    vector<int> arr[2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < D; j++) {
            cin >> k;
            if (i == 1) {
                arr[i].push_back(arr[0][j] - k);
            } else {
                arr[i].push_back(k);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        sussy = true;
        for (int j = 0; j < D; j++) {
            cin >> k;
            if (arr[1][j] > k || arr[0][j] < k) {
                sussy = false;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INNOCENT\n";
                j = D;
            }
        }
        if (sussy) { cout << "SUS\n"; }
    }
}
