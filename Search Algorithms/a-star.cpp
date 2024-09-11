#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
    int x, y;
    double cost, heuristic;
    Node* parent;

    Node(int x, int y, double cost, double heuristic, Node* parent = nullptr)
        : x(x), y(y), cost(cost), heuristic(heuristic), parent(parent) {}

    double totalCost() const {
        return cost + heuristic;
    }

    bool operator>(const Node& other) const {
        return this->totalCost() > other.totalCost();
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

void aStarSearch(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Print the initial and goal states
    cout << "Initial State: (" << start.first << ", " << start.second << ")" << endl;
    cout << "Goal State: (" << goal.first << ", " << goal.second << ")" << endl;

    priority_queue<Node, vector<Node>, greater<Node>> openList;
    vector<vector<bool>> closedList(rows, vector<bool>(cols, false));

    Node* startNode = new Node(start.first, start.second, 0, euclideanDistance(start.first, start.second, goal.first, goal.second));
    openList.push(*startNode);

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        if (closedList[current.x][current.y]) continue;
        closedList[current.x][current.y] = true;

        if (current.x == goal.first && current.y == goal.second) {
            cout << "Path found: ";
            printPath(&current);
            cout << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, rows, cols, grid) && !closedList[newX][newY]) {
                double newCost = current.cost + 1; // Assuming uniform cost for each move
                double heuristic = euclideanDistance(newX, newY, goal.first, goal.second);
                Node* neighbor = new Node(newX, newY, newCost, heuristic, new Node(current));

                openList.push(*neighbor);
            }
        }
    }

    cout << "No path found." << endl;
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

    aStarSearch(grid, start, goal);

    return 0;
}
