#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    map<string, vector<string>> adj;
    map<string, bool> visited;

    // Add edge in undirected graph
    void addEdge(string u, string v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Recursive
    void DFS(string node) {
        visited[node] = true;
        cout << "Visited: " << node << endl;

        for (string neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFS(neighbor);
            }
        }
    }

    // BFS Recursive using Queue
    void BFS(queue<string>& q) {
        if (q.empty()) return;

        string node = q.front();
        q.pop();

        cout << "Visited: " << node << endl;

        for (string neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }

        BFS(q); // recursive call
    }
};

int main() {
    Graph g;

    // Application: Social Media Friend Network
    // Nodes = People
    // Edges = Mutual Friend Connections

    g.addEdge("Rishi", "Aman");
    g.addEdge("Rishi", "Priya");
    g.addEdge("Aman", "Kunal");
    g.addEdge("Priya", "Neha");
    g.addEdge("Kunal", "Neha");   // creates graph cycle
    g.addEdge("Neha", "Simran");

    cout << "===== Social Media Friend Network =====\n";

    cout << "\nPurpose:\n";
    cout << "To explore friend connections using DFS and BFS traversal.\n";

    // DFS Traversal
    g.visited.clear();
    cout << "\nDFS Traversal (Deep Friend Exploration):\n";
    g.DFS("Rishi");

    // BFS Traversal
    g.visited.clear();
    queue<string> q;
    q.push("Rishi");
    g.visited["Rishi"] = true;

    cout << "\nBFS Traversal (Nearest Friends First):\n";
    g.BFS(q);

    return 0;
}
