#include <bits/stdc++.h>
using namespace std;

string movements(vector<string> maze, string colMaze) {
}

vector<int> move(char m) {
    vector<int>a = {0, 0};
    if (m == 'N') {
        a[1] = 1;
    } else if (m == 'S') {
        a[1] = -1;
    } else if (m == 'E') {
        a[0] = 1;
    } else if (m == 'W') {
        a[0] = -1;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, r, c;
    string k;
    cin >> T;
    priority_queue<int>que;
    for (int ii = 0; ii < T; ii++) {
        int i;
        cin >> r >> c;
        cin.ignore();
        vector<string> maze;
        for (i = 0; i < r; i++) {
            getline(cin, k);
            maze.push_back(k);
            for (int j = 0; j < c; j++) {
                cout << maze[i][j]<<endl;
                if (isdigit(maze[i][j])){
                    int x = maze[i][j] - '0';
                    cout<<"prio found  "<<x<<"\n";
                    que.push(x);
                }
            }
        }

/*        for (i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }*/
    }
}