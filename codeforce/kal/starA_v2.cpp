// BFS algorithm in C++

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex) {
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    while (!queue.empty()) {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, m, n, start;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        Graph g(n);
        int added[50000] ={0};
        int x, y;
        for (int j = 0; j < m; j++) {
            cin >> x >> y;
            if(i == 0)  start = n;
            if(y == start){
                start = x;
            }
            added[y] = 1;
            added[x] = 1;
            g.addEdge(x, y);
        }
        for (int j = 0; j < n+1; j++) {
            if (added[j]==0){
                if(j>start){
                    g.addEdge(j, start);
                    start = j;
                }else{
                    g.addEdge(start, j);
                }
            }
        }
        g.BFS(start);
    }
}