#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int shortestPath(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] == 1 && dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (dist[end] == INF) {
        return -1; 
    }

    return dist[end];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    int shortest = shortestPath(graph, start - 1, end - 1);
    cout << shortest << endl;

    return 0;
}