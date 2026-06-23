#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longest_sub_sum(vector<int> &nums,int k)
{
    int i,j,longest=1,count=0;
    int n=nums.size();
    bool sum_k = false; // this is for if no elements sum have k
    for(i=0;i<n;i++)
    {
        int sum = 0;
        for(j=i;j<n;j++)
        {
            sum+=nums[j];
            if(sum == k)
            {
                sum_k = true;
                if((j-i+1) > longest)
                    cout<<"index "<<i<<" to "<<j<<endl;
                longest = max(longest,j-i+1);
                
            }
        }
    }
    if(sum_k)
        return longest;
    return -1;
}
int longest_better(vector<int> &nums,int k) 
{
    unordered_map<int,int> hash;
    int i,j,n=nums.size();
    int sum=0,longest=-1;
    for(i=0;i<n;i++)
    {
        sum+=nums[i];
        if(hash.find(sum) == hash.end()) // this is for zero, e.g 2,0,1 
            hash[sum] = i;

        if(sum == k)
        {
            longest = max(longest,i+1);
        }
       
        int x = sum - k;
        if(hash.find(x) != hash.end())
        {
            longest = max(longest, i - hash[x] );
        }
        
    }
    return longest;
}
int main()
{
    vector<int> nums = {-1, -1, 1, 1, 1};//{3,2,6,0,4,2,1,1,5,9,7};
    int k = 1; //k=8;
    cout<<"longest sub sum k: "<<longest_sub_sum(nums,k)<<endl;
    cout<<"longest sub sum k: "<<longest_better(nums,k);
    
    return 0;
}