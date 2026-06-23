#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include <tuple>
using namespace std;
tuple<int,int,int> maxsub(vector<int> &nums)
{
    int i,j;
    int sum=0,maxsum=0;
    int n=nums.size();
    int start =0,end =0;
    for(i=0;i<n;i++)
    {
        if(sum == 0)
        {
            start =i;
        }
        sum += nums[i];
        if(sum > maxsum)
        {
            maxsum = sum;
            end = i;
        }
        if(sum < 0)
        {
            sum = 0;
        }
    }
    return {start,end,maxsum};
}
int brute_force(vector<int> &nums)
{
    int i,j;
    int n=nums.size();
    int sum=0,maxsum=0;
    int start,end;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            sum += nums[j];
            
            maxsum=max(maxsum,sum);
        }
    }
    return maxsum;
}
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxsub_array = brute_force(nums);
    cout<<"maxsub array sum: "<<maxsub_array<<endl;
    
    //auto [start,end,sum] = maxsub(nums);
    int start, end, sum;
    tie(start, end, sum) = maxsub(nums);

    for(int i=start;i<= end;i++)
        cout<<nums[i]<<", ";
    return 0;
}