#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int i,vector<int>& arr, int target,vector<vector<int>> &ans,vector<int> temp)
{
    if(i >= arr.size())
    {
        return;
    }
    if(target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if(target >= arr[i])
    {
        temp.push_back(arr[i]);
        solve(i,arr,target - arr[i], ans,temp);
        temp.pop_back();
    }
    solve(i+1,arr,target,ans,temp);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0,candidates,target,ans,temp);
    return ans;
}
int main()
{
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates,target);
    for(vector<int> ar : ans)
    {
        for(int e: ar)
        {
            cout<<e<<", ";
        }
        cout<<endl;
    }
    return 0;
}