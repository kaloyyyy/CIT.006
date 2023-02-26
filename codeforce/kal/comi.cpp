#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q;
    scanf("%d %d %d", &n, &r, &q);

    vector<pair<string, int>> stars(n);
    for (int i = 0; i < n; i++) {
        cin >> stars[i].first >> stars[i].second;
    }

    vector<vector<pair<int, int>>> requirements(r);
    for (int i = 0; i < r; i++) {
        string res, req;
        int m;
        cin >> res >> req >> m;
        requirements[i] = {{find(stars.begin(), stars.end(), make_pair(res, 0)) - stars.begin(), m},
                           {find(stars.begin(), stars.end(), make_pair(req, 0)) - stars.begin(), 0}};
    }

    vector<int> needed_stars(q);
    for (int i = 0; i < q; i++) {
        cin >> needed_stars[i];
    }

    // perform computations

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
