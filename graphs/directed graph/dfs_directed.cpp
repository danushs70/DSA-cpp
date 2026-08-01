#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis);
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Directed edges
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3};
    adj[3] = {4};
    adj[4] = {};

    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i])
            dfs(i, adj, vis);
    }

    return 0;
}