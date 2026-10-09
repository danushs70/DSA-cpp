#include<iostream>
#include<bits/stdc++.h>
using namespace std;   // leetcode no 523
bool checkSubarraySum(vector<int>& nums, int k)
{
    unordered_map<int,int> mpp;
    mpp[0] = -1;
    int i,n = nums.size();
    int psum = 0;
    for(i=0;i<n;i++)
    {
        psum += nums[i];
        int rem = psum %k;
        if(mpp.find(rem) != mpp.end())
        {
            if(i - mpp[rem] >= 2)
                return true;
        }
        else
        {
            mpp[rem] = i;
        }
    }
    return false;
}
int main()
{
    vector<int> nums = {23,2,4,6,7};
    int k = 6;
    if(checkSubarraySum(nums,k))
    {
        cout<<"Sub array sum = k exits"<<endl;
    }
    else{
        cout<<"sum = k not exits"<<endl;
    }
}

/* 523.
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
 */