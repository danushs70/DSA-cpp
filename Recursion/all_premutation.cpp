#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void prem(vector<int> &nums,vector<int> &curr,vector<vector<int>> 
    &ans, vector<bool> &taken); //inside class no need of this decleration

void perms(int index,vector<int> &nums,vector<vector<int>> &ans); //inside class no need of this decleration

vector<vector<int>> permute(vector<int>& nums)
{
    vector<bool> taken(nums.size(),false);
    vector<vector<int>> ans;
    vector<int> curr;
    //prem(nums,curr,ans,taken);
    perms(0,nums,ans);
    return ans;
}
void print_array(vector<int> &nums)
{
    for(int e:nums)
        cout<<e<<", ";
    cout<<endl;
}
void prem(vector<int> &nums,vector<int> &curr,vector<vector<int>> 
    &ans, vector<bool> &taken)
{
    if(curr.size() == nums.size())
    {
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(taken[i]) 
            continue;

        curr.push_back(nums[i]);
        taken[i] = true;
        prem(nums,curr,ans,taken);

        curr.pop_back();
        taken[i] = false;
    }
}
void perms(int index,vector<int> &nums,vector<vector<int>> &ans)
{
    if(index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i=index; i< nums.size();i++)
    {
        swap(nums[index],nums[i]);      //print_array(nums);
        perms(index+1,nums,ans);
        swap(nums[index],nums[i]);      //print_array(nums);
        
    }
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    cout<<"All premutatin:"<<endl;
    for(vector<int> row : ans)
    {
        cout<<"[";
        for(int e:row)
        {
            cout<<e<<", ";
        }
        cout<<"]"<<endl;
    }
}