#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> four_sum(vector<int> &nums,int target)
{
    
}
int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = four_sum(nums,target);
    for(vector<int> arr : res)
    {
        for(int e : arr)
            cout<<e<<", ";
        cout<<endl;
    }
}