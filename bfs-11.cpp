#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_NODES = 1005;
vector<int> adj[MAX_NODES]; // Adjacency list
bool visited[MAX_NODES];    // Visited array

// BFS Function
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    cout << "Enter edges (u v format):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    // Mark all nodes as not visited
    fill(visited, visited + nodes, false);

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "BFS Traversal: ";
    bfs(start);
    cout << endl;

    return 0;
}
