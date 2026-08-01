#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2) // Time O(nxm), space O(nxm)
{
    int i,j, n = text1.size(), m = text2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(text1[i-1] == text2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int optimal_lcs(string text1, string text2)
{
    int i,j, n = text1.size(), m = text2.size();

    vector<int> curr(m+1,0), prev(m+1,0);
    // to find every dp[i][j] we only need current row and prev row
    // so we use only 2 array(prev and curr) reduce space O(n x m) to O(n + m)
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(text1[i-1] == text2[j-1])
            {
                curr[j] = prev[j-1]+1;
            }
            else{
                curr[j] = max(curr[j-1], prev[j]);
            }
        }
        prev = curr; // for next row curr becoms prev
        
    }
    return prev[m];
}
// its use only one array curr and store diagonal value in cross 
// space O(n), or we can make it to space O(min(n,m))
int another_optimal_lcs(string text1, string text2)
{
    int i,j, n = text1.size(), m = text2.size();

        vector<int> curr(m+1,0);
        // to find every dp[i][j] we only need current row and prev row
        // so we use only 2 array(prev and curr) reduce space O(n x m) to O(n + m) most optimize use space O(m) or O(n) to 
        for(i=1;i<=n;i++)
        {
            int cross = 0; // first col value 0
            for(j=1;j<=m;j++)
            {
                int temp = curr[j];      // old dp[i-1][j] curr dp[i-1][j-1]
                if(text1[i-1] == text2[j-1])
                {
                    curr[j] = cross + 1;
                }
                else{
                    curr[j] = max(curr[j-1], curr[j]);
                }
                cross = temp; // store a diagonal value for 
            }
            
        }
        return curr[m];
}

int main()
{
    string text1 = "abcde", text2 = "ace";
    //int ans = longestCommonSubsequence(text1,text2);
    int ans = optimal_lcs(text1,text2);
    cout<<ans<<endl;
}