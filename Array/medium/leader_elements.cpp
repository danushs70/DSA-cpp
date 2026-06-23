#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//leaders of array is a number when right side element is lesser than that 
vector<int> leader_element(vector<int> &nums)
{
    int n=nums.size();
    int i,j,grater = INT_MIN;
    vector<int> leaders;
    for(i=n-1;i>=0;i--)
    {
        if(nums[i] > grater)
        {
            grater = nums[i];
            leaders.push_back(nums[i]);
        }
    }
    return leaders;
}

int main()
{
    vector<int> arr = {10,22,12,0,3,6};

    vector<int> leaders = leader_element(arr);

    for(int a:leaders)
        cout<<a<<", ";

    return 0;
}