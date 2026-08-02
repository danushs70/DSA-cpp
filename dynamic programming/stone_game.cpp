#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// 877 Stone Game alice always wins, simply return true is answer
int solve(int i, int j, vector<int>& piles, vector<vector<int>> &dp);

bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0, n-1, piles, dp);
    }
int solve(int i, int j, vector<int>& piles, vector<vector<int>> &dp)
{
    if(i == j)
        return piles[i];
        
    if(dp[i][j] != -1)
        return dp[i][j];

    int takeleft =  piles[i] - solve(i+1,j,piles,dp);
    int takeright = piles[j] - solve(i, j-1, piles, dp);

    return dp[i][j] = max(takeleft, takeright);
}

int main()
{
    vector<int> piles = {5,3,4,5};
    if(stoneGame(piles))
        cout<<"Alice wins"<<endl;
    else 
        cout<<"Bob wins"<<endl;
}
