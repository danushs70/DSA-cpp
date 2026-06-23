#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int>& stones)
{
        priority_queue<int> pq;
        for(int e:stones)
            pq.push(e);
        if(stones.size() == 1)
            return stones[0];
        while(pq.size() >= 2)
        {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if(s1 == s2)
                continue;
            pq.push(s1-s2);
        }
        if(pq.size() == 0)
            return 0;
        return pq.top();
}

int main()
{
    vector<int> stones = {2,7,4,1,8,1};
    cout<<"remaing weight: "<<lastStoneWeight(stones);
}