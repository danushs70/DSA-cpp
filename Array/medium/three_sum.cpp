#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threesum(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    int i,j, n = nums.size();
    //unordered_map<int,int> mpp;
    vector<vector<int>> ans;
    int left, right;
    for(i=0;i<n-2;i++)
    {
        left = i + 1;
        right = n - 1;
        if(i>0 && nums[i] == nums[i-1])
            continue;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
                ans.push_back({nums[i],nums[left],nums[right]});
            
                left++;
                right--;
                while(left < right && nums[left] == nums[left-1])
                {
                    left++;
                }
                while(right > left && nums[right] == nums[right+1])
                {
                    right--;
                }
            }
            else if(sum < 0)
            {
                left++;
            }
            else{
                right--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    //vector<int> nums = {-100,-70,-60,110,120,130,160};
    vector<vector<int>> ans = threesum(nums);
    for(auto es: ans)
    {
        for(int e: es)
            cout<<e<<", ";
        cout<<endl;
    }
}