#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int i,int amt, vector<int> &ds,vector<vector<int>> &ans,vector<int> &coin)
{
    if(i == coin.size())
    {
        if(amt == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if(coin[i] <= amt)
    {
        ds.push_back(coin[i]);
        solve(i, amt - coin[i], ds,ans,coin);
        ds.pop_back();
    }
    solve(i+1,amt,ds,ans,coin);
}
int solve_tabulation(int i, int amt, vector<int>& coin, vector<vector<int>>& dp)
{
    if(amt == 0)
        return 1;

    if(i == coin.size())
        return 0;

    if(dp[i][amt] != -1)
        return dp[i][amt];

    int take = 0;

    if(coin[i] <= amt)
    {
        take = solve_tabulation(i, amt - coin[i], coin, dp);
    }

    int notTake = solve_tabulation(i + 1, amt, coin, dp);

    return dp[i][amt] = take + notTake;
}

int change(int amount, vector<int>& coins)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int sum = 0, n =coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    //solve_tabulation(0,amount,ds,ans,coins,dp);
    //return ans.size();
    return solve_tabulation(0,amount,coins,dp);
}
int main()
{
    vector<int> coins = {1,2,5};
    int amount = 5;
    cout<<"no.of combinations to make a target: "<<change(amount,coins)<<endl;
}