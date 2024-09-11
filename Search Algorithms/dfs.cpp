#include <iostream>

using namespace std;

const int MAX_NODES = 6;
int graph[MAX_NODES][MAX_NODES] = {0};
bool visited[MAX_NODES] = {false};

void dfs(int node) {
    cout << node << " ";
    visited[node] = true;

    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][5] = graph[5][3] = 1;
    graph[4][5] = graph[5][4] = 1;

    int startNode = 0;
    dfs(startNode);

    return 0;
}
