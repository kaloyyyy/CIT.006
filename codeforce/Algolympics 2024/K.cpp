#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int countDiamonds(int n, int m) {
    vector<set<int>> adjList(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    int totalDiamonds = 0;

    for (int i = 1; i <= n; ++i) {
        for (int a : adjList[i]) {
            for (int b : adjList[i]) {
                if (a != b) {
                    set<int> commonNeighbors;
                    set_intersection(adjList[a].begin(), adjList[a].end(),
                                     adjList[b].begin(), adjList[b].end(),
                                     inserter(commonNeighbors, commonNeighbors.end()));

                    for (int c : commonNeighbors) {
                        if (c != i) {
                            totalDiamonds = (totalDiamonds + 1) % MOD;
                        }
                    }
                }
            }
        }
    }

    return totalDiamonds / 2; // Each diamond is counted twice
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);


    int result = countDiamonds(n, m);
    cout << result << endl;

    return 0;
}
