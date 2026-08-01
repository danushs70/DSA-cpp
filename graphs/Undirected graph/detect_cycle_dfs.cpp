#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    for(int neighbor : adj[node])
    {
        if(!vis[neighbor])
        {
            if(dfs(neighbor,node,adj,vis))
                return true;
        }
        else if(neighbor != parent)
        {
            return true;
        }
    }
    return false;
}
bool hasCycle(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V,0);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,adj,vis))
                return true;
        }
    }
    return false;
}
int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1};
    adj[1] = {0,2,3};
    adj[2] = {1,3};
    adj[3] = {1,2,4};
    adj[4] = {3};
    /*
        0
        |
        1
       / \
      2---3
           |
           4

        it has cycle 1->2->3->1
    */
    cout << (hasCycle(V, adj) ? "Cycle Found\n" : "No Cycle\n");
}