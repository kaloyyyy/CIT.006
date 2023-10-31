#include <bits/stdc++.h>
#include <set>
using namespace std;

void bfs(vector<int> *pVector, int start) {
    queue<int> q;
    unordered_set<int> print;
    bool visited[1000];
    bool parent[1000];
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int s = q.front();
        print.insert(s);
        q.pop();
        parent[s] = true;
        for (int j = pVector[s].size() - 1; j >= 0; j--) {
            q.push(pVector[s][j]);
            visited[pVector[s][j]] = true;
            if (parent[pVector[s][j]]) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    std::deque<int> myDeque(print.begin(), print.end());

    // Traverse the deque in reverse order
    for (auto it = myDeque.rbegin(); it != myDeque.rend(); ++it) {
        std::cout << *it << " ";
    }


    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, m, n, start, end, x, y;
    cin >> t;
    bool impossible = false;

    cin >> n >> m;
    vector<int> graph[n + 1];
    int added[500] = {0};
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        if (j == 0) {
            start = x;
            end = y;
        }
        if (y == start) {
            start = x;
        }
        if (end == start) {
            impossible = true;
        }
        if (x == end) {
            end = y;
        }
        added[y] = 1;
        added[x] = 1;
        graph[x].push_back(y);
    }
    added[0] = 1;
    for (int j = 0; j < n + 1; j++) {
        if (added[j] == 0) {
            added[j] = 1;
            if (j > start) {
                graph[j].push_back(start);
                start = j;

            } else {
                graph[start].push_back(j);
            }
        }
    }
    if (!impossible) {
        bfs(graph, start);
    } else {
        cout << "IMPOSSIBLE\n";
    }

}