#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//this code in longest_common_sub_seq.cpp
int longest_recursion_dp_m(string &s, string &t,int i,int j, vector<vector<int>> &dp)
{
   
    if(i < 0 || j < 0)
        return 0;
    //check dp must be second, because firsr handle negative index like -1 above if condition
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(s[i] == t[j])
        return dp[i][j] = 1 + longest_recursion_dp_m(s,t,i-1,j-1,dp);
    
    return dp[i][j] = max(longest_recursion_dp_m(s,t,i-1,j,dp),longest_recursion_dp_m(s,t,i,j-1,dp));
}
// to identify minimum insertion of any chat to make a sting palindrome
// answer = find the longest sub seq palindrome, subtract it form 'n' (length of 's'), 
// reverse a word and find sub sequence, that is longest sub seq palindrom
// e.g; s = leetcode ,  t = edocteel this is reverse of t
// longest sub seq palindrom of 's' is eee,ete,ece,eoe,... but max length is 3
// then  n - 3   = 8 - 3 = 5, ans is 5
int min_char_add_to_make_palindrom(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    int ans = n - longest_recursion_dp_m(s,t,n-1, n-1,dp);
    
    return ans;
}
   
int main()
{
    string s ="leetcode";
    cout<<"min char to make a palindrom: "<<min_char_add_to_make_palindrom(s)<<endl;
}