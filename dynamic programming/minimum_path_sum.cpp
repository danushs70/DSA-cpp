#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
{
    int n = grid.size(), m = grid[0].size();
    if(i >= n || j >= m)
        return INT_MAX;

    if(i == n-1 && j == m-1)
        return grid[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int down  =  solve(i+1,j,grid,dp);
    int right =  solve(i,j+1,grid,dp);

    return dp[i][j] = grid[i][j] + min(down, right);
}
int solve_tabulation(vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    int n = grid.size(), m = grid[0].size();
    int i,j;
    dp[0][0] = grid[0][0];
    for(j=1;j<m;j++)
    {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for(i=1;i<n;i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}
int minPathSum(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans = INT_MAX;
    //return solve(0,0,grid,dp);
    return solve_tabulation(grid,dp);
}
int main()
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<"min path for top left to bottem right: "<<minPathSum(grid)<<endl;
}