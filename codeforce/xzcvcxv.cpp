#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int D, N;
    cin >> D >> N;
    int i, k;
    vector<int> arr[3];
    for (i = 0; i < N + 2; i++) {
        bool sussy = true;
        for (int j = 0; j < D; j++) {

            cin >> k;
            arr[i][j] = k;
            if (i == 1) {
                arr[1][j] = arr[0][j] - arr[1][j];
            }
            if (i > 1 && sussy) {
                if (arr[1][j] <= arr[i][j] && arr[0][j] >= arr[i][j]) {
                    sussy = true;
                } else {
                    sussy = false;

                }
            }
            if (!sussy){
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                j = D;
            }
        }

        if (i > 1) {
            if (sussy) {
                cout << "SUS\n";
            } else {
                cout << "INNOCENT\n";
            }
        }
    }
    return 0;
}