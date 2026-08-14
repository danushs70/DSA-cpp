#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int knapsack( int i, int w, vector<int> &wt, vector<int> &val)
{
    // from right to left, thats why base case is i == 0
    if(i == 0)
    {
        if(wt[0] < w)
            return val[0];
        else
            return 0;
    }

    int not_take = 0 + knapsack(i-1, w, wt, val);
    int take = INT_MIN;
    if(w > wt[i])
        take = val[i] + knapsack(i-1, w - wt[i], wt, val);
    
    return max(not_take, take);
}
int knapsack_dp( int i, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    // from right to left, thats why base case is i == 0
    if(i == 0)
    {
        if(wt[0] < w)
            return val[0];
        else
            return 0;
    }
    if(dp[i][w] != -1)
    {
        return dp[i][w];
    }
    int not_take = 0 + knapsack(i-1, w, wt, val);
    int take = INT_MIN;
    if(w > wt[i])
        take = val[i] + knapsack(i-1, w - wt[i], wt, val);
    
    return dp[i][w] = max(not_take, take);
}
int main()
{
    vector<int> wt = {3,2,5};
    vector<int> val = {30, 40, 60};
    int w = 6, n = wt.size()-1;
    cout<<"maximum value :"<<knapsack(n - 1 ,w,wt,val)<<endl;

    vector<vector<int>> dp(n, vector<int>(w+1,-1));
    cout<<"maximum value :"<<knapsack_dp(n - 1 ,w,wt,val,dp)<<endl;
}