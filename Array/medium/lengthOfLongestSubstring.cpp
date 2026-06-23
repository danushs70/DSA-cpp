#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int i,j,n=s.size();
    int max_len=1;
    for(i=0;i<n;i++)
    {
        int  hash[256] = {0};
        for(j=i;j<n;j++)
        {
           if(hash[s[j]] == 1)
            break;

            hash[s[j]] = 1;
            max_len = max(max_len , j-i+1);
        }
    }
    return max_len;
}
int lengthOf_sub_str_optimal(string s)
{
    int hash[256] = {0};
    for(int i=0;i<256;i++)
        hash[i] = -1;

    int n=s.size();
    int l=0,r=0,maxlen=1; //two pointer aproach
    while(r<n)
    {
        if(hash[s[r]] != -1)
        {
            l = max(hash[s[r]] + 1 , l);
        }
        int len = r-l+1;
        maxlen = max(maxlen , len);

        hash[s[r]] = r;
        r++; //
    }
    return maxlen;
    
}
int main()
{
    string s = "abcabcbb";
    cout<<"longest sub string without repeating char: "<<lengthOfLongestSubstring(s)<<endl;
    cout<<"longest sub string without repeating char: "<<lengthOf_sub_str_optimal(s);

    return 0;
}