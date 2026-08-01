#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int V = 5;

    vector<vector<int>> adj(V);

    // Undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    
    vector<bool> vis(V, false);

    cout << "DFS Traversal: ";
    for (int i = 0; i < V; i++) {
        if (!vis[i])  // for unconnected component
        {
            dfs(i, adj, vis);
        }
    }
    cout<<endl;

    return 0;
}