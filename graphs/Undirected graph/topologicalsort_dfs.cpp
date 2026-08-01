#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> topo_dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &vispath)
{
    
}
int main()
{
    int V = 6;
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(5);

    vector<bool> vis(V,false);
    
    //vector<int> ans = topo_dfs(adj,vis,vispath);

    for (int x : ans)
        cout << x << " ";
    cout << endl;
}