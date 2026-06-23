#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool binary_search(vector<int> &nums,int k,int s,int e)
{
    if(s>e)
        return false;
    int mid = s+((e-s)/2);
    if(nums[mid] == k)
        return true;
    
    if(nums[mid] > k)
    {
        binary_search(nums,k,s,mid-1);
    }
    else
    {
        binary_search(nums,k,mid+1,e);
    }
}
int main()
{
    vector<int> nums = {1,2,3,4,5,6,8,9,10};
    int k = 7;//target is 7
    if(binary_search(nums,k,0,nums.size()-1))
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl;

    return 0;
}