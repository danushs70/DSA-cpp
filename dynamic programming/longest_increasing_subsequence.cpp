#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums)
{
    int i,j, n = nums.size();
    vector<int> dp(n,1);
    int ans = 1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }  
    return ans;      
}
// binary search is optimal for this problem
int lengthofLIS_Binary_search(vector<int> &nums)
{
    int i, n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    for(i=1;i<n;i++)
    {
        if(nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
        }
        else{
            auto ind = lower_bound(temp.begin(),temp.end(),nums[i]);
            // lower_bound return iteratior, not int 
            // *ind points to the >= element
            //nums[ind] = nums[i]; 
            *ind = nums[i];
        }
    }
    return temp.size();
}
int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    //int ans = lengthOfLIS(nums);
    int ans = lengthofLIS_Binary_search(nums);
    cout<<ans<<endl;
}