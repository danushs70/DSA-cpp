#include <iostream>
#include <vector>
using namespace std;
//Single sourct shortest path
struct Edge {
    int u, v, w;
};

void bellmanFord(int V, vector<Edge>& edges, int src) {
    const int INF = 1e9;
    vector<int> dist(V, INF);

    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (auto edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Graph contains a Negative Weight Cycle\n";
            return;
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    cout<<"Node\t:distance form source "<<src<<endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\t : INF\n";
        else
            cout << i << "\t : " << dist[i] << "\n";
    }
}

int main() {
    int V = 7;
    vector<Edge> edges = {
    {0,1,6},
    {0,2,5},
    {0,3,5},
    {1,4,-1},
    {2,1,-2},
    {2,4,1},
    {3,2,-2},
    {3,5,-1},
    {4,6,3},
    {5,6,3}    };

    
    int source = 0;

    bellmanFord(V, edges, source);

    return 0;
}