#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
    vector<int> ref(nums.size(),0);
    int i,n=nums.size();
    for(i=0;i<n;i++)
    {
        ref[nums[i]]++;
    }
    for(i=0;i<n;i++)
    {
        if(ref[i] > 1)
            return i;
    } 
    return -1;

    /* Another method 
    sort(nums.begin(),nums.end());
        int rep=-1,i,n = nums.size();
        for(i=0;i<n-1;i++)
            if(nums[i] == nums[i+1])
                return nums[i];
        
        return rep;
    */
}
int main()
{
    vector<int> nums = {1,3,4,2,2};
    cout<<"duplicate number: "<<findDuplicate(nums);
    //return 0;
}

/* leetcode q.no 287 
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
*/