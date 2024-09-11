#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
    int x, y;
    double heuristic;
    Node* parent;

    Node(int x, int y, double heuristic, Node* parent = nullptr)
        : x(x), y(y), heuristic(heuristic), parent(parent) {}

    bool operator<(const Node& other) const {
        return this->heuristic < other.heuristic;
    }
};

double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool isValid(int x, int y, int rows, int cols, const vector<vector<int>>& grid) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0);
}

void printPath(Node* node) {
    if (node == nullptr) return;
    printPath(node->parent);
    cout << "(" << node->x << ", " << node->y << ") ";
}

void hillClimbingSearch(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    int cols = grid[0].size();

    cout << "Initial State: (" << start.first << ", " << start.second << ")" << endl;
    cout << "Goal State: (" << goal.first << ", " << goal.second << ")" << endl;

    Node* current = new Node(start.first, start.second, euclideanDistance(start.first, start.second, goal.first, goal.second));

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (true) {
        if (current->x == goal.first && current->y == goal.second) {
            cout << "Path found: ";
            printPath(current);
            cout << endl;
            return;
        }

        Node* bestNeighbor = nullptr;

        for (int i = 0; i < 4; i++) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            if (isValid(newX, newY, rows, cols, grid)) {
                double heuristic = euclideanDistance(newX, newY, goal.first, goal.second);
                Node* neighbor = new Node(newX, newY, heuristic, current);

                if (bestNeighbor == nullptr || *neighbor < *bestNeighbor) {
                    bestNeighbor = neighbor;
                }
            }
        }

        if (bestNeighbor == nullptr || bestNeighbor->heuristic >= current->heuristic) {
            cout << "Stuck at local minimum, no better neighbors found." << endl;
            return;
        }

        current = bestNeighbor;  // move to the best neighbor
    }
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    hillClimbingSearch(grid, start, goal);

    return 0;
}
