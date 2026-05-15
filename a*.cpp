#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Manhattan Distance
int h(int x, int y, int gx, int gy) { return abs(x - gx) + abs(y - gy); }

bool valid(int x, int y, vector<vector<int>> &g) {
  return x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] == 0;
}

void AStar(vector<vector<int>> &grid, pair<int, int> s, pair<int, int> g) {
  if (grid[s.first][s.second] == 1 || grid[g.first][g.second] == 1) {
    cout << "Start or Goal is blocked\n";
    return;
  }
  int n = grid.size(), m = grid[0].size();

  vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      pq;
  // (f, x, y)

  cost[s.first][s.second] = 0;
  pq.push({h(s.first, s.second, g.first, g.second), s.first, s.second});

  while (!pq.empty()) {
    auto [f, x, y] = pq.top();
    pq.pop();

    if (make_pair(x, y) == g) {
      cout << "\n\n Path: ";
      vector<pair<int, int>> path;

      while (!(x == s.first && y == s.second)) {
        path.push_back({x, y});

        int px = parent[x][y].first;
        int py = parent[x][y].second;

        x = px;
        y = py;
      }
      path.push_back(s);
      reverse(path.begin(), path.end());

      for (auto p : path)
        cout << "(" << p.first << "," << p.second << ") ";

      cout << endl << endl;

      return;
    }

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];

      if (valid(nx, ny, grid)) {
        int newCost = cost[x][y] + 1;

        if (newCost < cost[nx][ny]) {
          cost[nx][ny] = newCost;
          parent[nx][ny] = {x, y};

          int hVal = h(nx, ny, g.first, g.second);
          int fVal = newCost + hVal;

          cout << "\n Node: (" << nx << "," << ny << ") ";
          cout << "\n g(n)=" << newCost << " ";
          cout << "\n h(n)=" << hVal << " ";
          cout << "\n f(n)=" << fVal << endl;

          pq.push({fVal, nx, ny});
        }
      }
    }
  }

  cout << "No path found\n";
}

int main() {
  vector<vector<int>> grid = {
    {1, 0, 0, 0}, 
    {0, 1, 1, 0}, 
    {0, 1, 0, 0}, 
    {0, 0, 0, 0}};

  AStar(grid, {0, 0}, {3, 2});
}
