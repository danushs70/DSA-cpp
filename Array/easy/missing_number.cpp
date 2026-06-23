#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int find_missing(vector<int> &nums)
{
    int n=nums.size()+1;
    int sum = (n*(n-1)/2);
    cout<<"sum:"<<sum<<endl;
    int i,s1=0;
    for(i=0;i<n-1;i++)
    {
        s1 += nums[i];
    }
    cout<<"s1:"<<s1<<endl;
    int r=sum-s1;
    /*

    */
    return r;
}
//optimal solution
int missingNumber(vector<int>& nums)
{
    int n = nums.size();
    int xor1 = 0, xor2 = 0;

    for(int i = 0; i <= n; i++)
        xor1 ^= i;

    for(int x : nums)
        xor2 ^= x;

    return xor1 ^ xor2;
}

int main()
{
    vector<int> nums = {3,0,1};
    int missing=find_missing(nums);
    
    cout<<"missing number: "<<missing;
    return 0;
}