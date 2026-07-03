#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string longest_palindrom(string s)
{
    int i, n = s.size();
    if(n == 0)
        return "";
    int maxlen = 0, start;
    for(i=0;i<n;i++)
    {
        int left,right;

        // for odd length palindrome
        left = i;
        right = i;
        while(left >=0 && right < n && s[left] == s[right])
        {
            if(right - left + 1 > maxlen)
            {
                start = left;
                maxlen = right - left + 1;
            }
            left--;
            right++;
        }

        //for even length palindrome
        left = i;
        right = i+1;
        while(left >=0 && right < n && s[left] == s[right])
        {
            if(right - left + 1 > maxlen)
            {
                start = left;
                maxlen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxlen);
}
int main()
{
    string s = "babad";
    cout<<"Longest palindrome: "<<longest_palindrom(s)<<endl;
}