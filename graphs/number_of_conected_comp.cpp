#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis, int &e, int &v)
{
    vis[node] = true;
    v++;
    e += adj[node].size();
    for(int &d:adj[node])
    {
        if(!vis[d])
        {
            dfs(d,adj,vis,e,v);
        }
    }
}
int countCompleteComponents(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> adj(n);
    for(const auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<bool> vis(n,false);
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            int e = 0, v = 0;
            dfs(i,adj,vis,e,v);
            // edges counted twice because its undirected
            e = e/2;
            if( e == (v*(v-1)/2))
                answer++;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
    int n = 6;
    int no_of_connected_compentnt = countCompleteComponents(n, edges);
    cout<<" number of connected components: "<<no_of_connected_compentnt<<endl;

}