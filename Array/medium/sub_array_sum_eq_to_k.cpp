#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>& nums, int k)
{
    unordered_map<int,int> mpp;
    int i, n = nums.size(), psum = 0;
    int count = 0;
    for(i = 0;i<n;i++)
    {
        psum += nums[i];
        if(psum == k)
            count++;
        if(psum < k)
            continue;
        
        int rem = psum - k;
        if(mpp.find(rem) != mpp.end())
        {
            count++;
        } 
        mpp[psum] = i;
    }
    return count;
}