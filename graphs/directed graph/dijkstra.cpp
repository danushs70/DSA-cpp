// Single source shotest path
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty())
    {
        auto [d,u] = pq.top();
        pq.pop();
        
        // skip already have a shortest path
        if(d > dist[u])
            continue;
        for(auto [v,wt] : adj[u])
        {
            if(dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
int main()
{
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    // {destination, weight}

    // 0 -> 1 (4)
    adj[0].push_back({1,4});

    // 0 -> 2 (2)
    adj[0].push_back({2,2});

    // 1 -> 2 (1)
    adj[1].push_back({2,1});

    // 1 -> 3 (5)
    adj[1].push_back({3,5});

    // 2 -> 3 (1)
    adj[2].push_back({3,1});

    // 2 -> 4 (3)
    adj[2].push_back({4,3});

    // 3 -> 4 (2)
    adj[3].push_back({4,2});

    /*   directed graph
       4
(0)--------->(1)____
 |            |     \ 
 |2           |5     \1
 v            v       \
(2)----1---->(3)--2-->(4)
  \                    ^
   \___________________|
            3
    */

    int source = 0;

    vector<int> dist = dijkstra(V, adj, source);

    cout << "Shortest distance from source " << source << ":\n";

    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << " -> " << dist[i] << endl;
    }

    return 0;
}