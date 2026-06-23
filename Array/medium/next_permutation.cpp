#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> next_permutation(vector<int> &nums)
{                                                                                                    
    
    int n=nums.size();
    int i=n-2,j,index;
    while( i>=0 && nums[i] < nums[i+1] )
    {
        i--;
    }
    if(i >=0)
    {
        j=n-1;
        while(nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums[i],nums[j]);

    }
    
    reverse(nums.begin() + i + 1, nums.end());
}
void nextpermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    //Find the first index i from the end such that nums[i] < nums[i+1]
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // If such an index exists:
    if (i >= 0) {
        //Find the first index j from the end such that nums[j] > nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        //Swap nums[i] and nums[j]
        swap(nums[i], nums[j]);
    }

    // Reverse the suffix starting at i+1
    reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
    vector<int> arr = {1,2,4,5,5,3};
    cout<<"number :";
    for(int e: arr)
        cout<<e<<", ";
    nextpermutation(arr);
    cout<<endl<<"next permutation :";
    for(int e: arr)
        cout<<e<<", ";
    
    return 0;
}