#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
bool is_anagram(string a,string b)
{
    if(a.size() != b.size())
        return false;
    unordered_map<char,int> mppa;
    unordered_map<char,int> mppb;

    for(auto ch:a)
    {
        mppa[ch]++;
    }
    for(auto ch:b)
    {
        mppb[ch]++;
    }
    for(auto ch:a)
    {
        if(mppa[ch] != mppb[ch])
            return false;
    }
    return true;
}
int main()
{
    string a="cat";
    string b= "act";
    if(is_anagram(a,b))
        cout<<"Its Anagram";
    else
        cout<<"Not a Anagram";

    return 0;
}