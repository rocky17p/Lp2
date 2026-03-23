#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> visited;

    void insertEdge(string u, string v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 🔹 DFS (Recursive)
    void dfsHelper(string node) {
        visited[node] = true;
        cout << node << " ";

        for (auto &nb : adj[node]) {
            if (!visited[nb]) {
                dfsHelper(nb);
            }
        }
    }

    void dfs(string start) {
        visited.clear();
        dfsHelper(start);
        cout << endl;
    }

    // 🔹 BFS (Recursive using queue)
    void bfsHelper(queue<string>& q) {
        if (q.empty()) return;

        string node = q.front();
        q.pop();

        cout << node << " ";

        for (auto &nb : adj[node]) {
            if (!visited[nb]) {
                visited[nb] = true;
                q.push(nb);
            }
        }

        bfsHelper(q); // recursive call
    }

    void bfs(string start) {
        visited.clear();
        queue<string> q;

        visited[start] = true;
        q.push(start);

        bfsHelper(q);
        cout << endl;
    }
};

int main() {
    Graph g;

    g.insertEdge("College", "Library");
    g.insertEdge("College", "Cafeteria");
    g.insertEdge("Library", "Bookstore");
    g.insertEdge("Library", "Cafe");
    g.insertEdge("Cafeteria", "Gym");
    g.insertEdge("Gym", "Parking");
    g.insertEdge("Parking", "Library");

    cout << "DFS: ";
    g.dfs("College");

    cout << "BFS: ";
    g.bfs("College");
}
