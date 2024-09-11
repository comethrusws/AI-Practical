#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int nodes = 6;
    vector<vector<int>> graph(nodes);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    int startNode = 0;
    bfs(startNode, graph);

    return 0;
}
