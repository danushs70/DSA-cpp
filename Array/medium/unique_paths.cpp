#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int uniquePaths(int m, int n)
{  
    if(m < 1 || n < 1)
        return 0;
    if(m==1 && n == 1)
        return 1;
    if(dp[m][n] != -1 )
        return dp[m][n];

    dp[m][n] = (uniquePaths(m-1,n) + uniquePaths(m,n-1));
    return dp[m][n];
}
int main()
{
    int m=3,n=7;
    //resize the dp matrix depend upon the input m,n
    dp.resize(m+1, vector<int>(n+1, -1));
    cout<<"no.of paths: "<<uniquePaths(m,n);
    return 0;
}