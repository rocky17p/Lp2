#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Manhattan Distance
int h(int x, int y, int gx, int gy) {
    return abs(x - gx) + abs(y - gy);
}

bool valid(int x, int y, vector<vector<int>> &grid) {
    return x >= 0 && y >= 0 &&
           x < grid.size() &&
           y < grid[0].size() &&
           grid[x][y] == 0;
}

void AStar(vector<vector<int>> &grid, int sx, int sy, int gx, int gy) {

    // Check start and goal
    if (grid[sx][sy] == 1 || grid[gx][gy] == 1) {
        cout << "Start or Goal is blocked\n";
        return;
    }

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> parent(n,vector<pair<int, int>>(m));

    priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<>> pq;

    // (f, x, y)

    cost[sx][sy] = 0;
    pq.push({h(sx, sy, gx, gy), sx, sy});

    while (!pq.empty()) {
        auto [f, x, y] = pq.top();
        pq.pop();

        // Goal reached
        if (x == gx && y == gy) {
            cout << "\n\nPath: ";

            vector<pair<int, int>> path;

            while (!(x == sx && y == sy)) {
                path.push_back({x, y});

                int px = parent[x][y].first;
                int py = parent[x][y].second;

                x = px;
                y = py;
            }

            path.push_back({sx, sy});
            reverse(path.begin(), path.end());

            for (auto p : path) {
                cout << "(" << p.first << "," << p.second << ") ";
            }

            cout << endl << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (valid(nx, ny, grid)) {
                int newCost = cost[x][y] + 1;

                if (newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    parent[nx][ny] = {x, y};

                    int hVal = h(nx, ny, gx, gy);
                    int fVal = newCost + hVal;

                    cout << "\nNode: (" << nx << "," << ny << ")";
                    cout << "\ng(n) = " << newCost;
                    cout << "\nh(n) = " << hVal;
                    cout << "\nf(n) = " << fVal << endl;

                    pq.push({fVal, nx, ny});
                }
            }
        }
    }

    cout << "No path found\n";
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };

    AStar(grid, 0, 0, 3, 2);
}
