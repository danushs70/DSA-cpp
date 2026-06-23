#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string sorting_by_high_frequncy(string str)
{
    unordered_map<char,int> freq;
    for(auto ch:str)
    {
        freq[ch]++;
    }

    priority_queue<pair<int,char>> pq;
    for(auto &p : freq)
    {
        pq.push({p.second,p.first});
    }

    string result;
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
    
        result.append(top.first,top.second);
    
    }

    return result;
}
int main()
{
    string str = "tree";
    cout<<"String: "<<str<<endl;
    cout<<"After sort by freqency: "<<sorting_by_high_frequncy(str);
    return 0;
}