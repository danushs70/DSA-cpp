#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
    
    queue<pair<pair<int,int>,int>> qu;
    int i,j, n = grid.size(), m = grid[0].size();
    int counter = 0; // final check all orange is rotten or not 
    vector<vector<int>> vis(n, vector<int>(m,0));
    for(i = 0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(grid[i][j] == 2)
            {
                qu.push({{i,j},0});
                vis[i][j] = 2;
            }
            if(grid[i][j] == 1)
                counter++; 
        }
    }
    if(counter == 0) //no fresh orange in the matrix
        return 0;
    int tm = 0;
    int col[] = {0,1,-1,0}; // top,right,left,bottom
    int row[] = {-1,0,0,1}; // top,right,left,bottom
    while(!qu.empty())
    {
        int r = qu.front().first.first;
        int c = qu.front().first.second;
        int t = qu.front().second;
        qu.pop();
        tm = max(tm,t);
        for(i=0;i<4;i++)  // i < 4 because of top,right,left,bottom
        {
            int nrow = r + row[i], ncol = c + col[i];
            if( nrow >=0 && ncol >=0 && nrow < n 
                && ncol < m && grid[nrow][ncol] == 1 
                && vis[nrow][ncol] == 0)
                {
                    qu.push({{nrow,ncol}, t+ 1});
                    vis[nrow][ncol] = 1; //just marked as visited
                    counter--;   // if counter has remaining value then some orange is not able to visit
                }
        }
    }
    if(counter)
        return -1;
    return tm;

}
int main()
{
    vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
    cout<<"Minimum Minitus: "<<orangesRotting(grid);
}