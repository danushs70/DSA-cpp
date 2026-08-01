#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool bfs(int start,vector<vector<int>> &adj,vector<int> &vis)
{
    queue<pair<int,int>> qu;
    qu.push({start,-1});
    while(!qu.empty())
    {
        int node = qu.front().first;
        int parent = qu.front().second;
        qu.pop();
        for(int neighbor : adj[node])
        {
            if(!vis[neighbor])
            {
                vis[neighbor] = 1;
                qu.push({neighbor,node});
            }
            else if (parent != neighbor)
            {
                return true;
            }
        }
    }
    return false;

}
bool hasCycle(int V,vector<vector<int>> &adj)
{
    vector<int> vis(V,0);
    for(int i=0;i<V;i++)
    {
        if(bfs(i,adj,vis))
        {
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