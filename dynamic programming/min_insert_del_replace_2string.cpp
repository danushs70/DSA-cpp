#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int i,int j, string &word1,string &word2, vector<vector<int>> &dp)// memorization
{
    if(i==0)
        return j;
    if(j==0)
        return i;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(word1[i-1] == word2[j-1])  // if word1[i-1] == word2[j-1] then no operation need, just move i-1, j-1
        return dp[i][j] = solve(i-1, j-1, word1, word2, dp);
    
    //if word1[i-1] != word2[j-1] then we have 3 operations, insert (i remain same , j-1 ),
    // delete (i-1, j remains), replace (i-1,j-1)
    int insert = 1 + solve(i,j-1,word1,word2,dp);  // insert is 1 operation thats why we add 1 + solve
    int del = 1 + solve(i-1, j, word1, word2, dp);
    int replace = 1 + solve(i-1, j-1, word1, word2, dp);
    
    return dp[i][j] = min({insert,del,replace});

}
int solve_tabulation(int n,int m, string &word1,string &word2, vector<vector<int>> &dp)
{
    int i,j;
    for(i=0;i<=n;i++)
        dp[i][0] = i;
    for(j=0;j<=m;j++)
        dp[0][j] = j;
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else{                   // insert, delete,     replace
                    dp[i][j] = 1+ min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
        }
    }
    return dp[n][m];
}
int minDistance(string word1, string word2)
{
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //return solve(n, m, word1, word2, dp);
    return solve_tabulation(n, m, word1, word2, dp);
}
int main()
{
    string word1 = "horse", word2 = "ros";
    //string word1 = "intention", word2 = "execution";
    cout<<"Minimum operation to conver w1 to w2: "<<minDistance(word1,word2)<<endl;
}