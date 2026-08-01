#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int l, int r, vector<int>& nums, vector<vector<int>> &memo);
bool predictTheWinner(vector<int>& nums)
{
        
    int n = nums.size();
    vector<vector<int>> memo;
    memo.assign(n, vector<int>(n, INT_MIN));

    return solve(0, n - 1, nums, memo) >= 0;
}

int solve(int l, int r, vector<int>& nums, vector<vector<int>> &memo)
{
    if (l == r)
        return nums[l];

    if (memo[l][r] != INT_MIN)
        return memo[l][r];

    int takeLeft = nums[l] - solve(l + 1, r, nums,memo);
    int takeRight = nums[r] - solve(l, r - 1, nums,memo);

    return memo[l][r] = max(takeLeft, takeRight);
}

int main()
{
    vector<int> nums = {1,5,233,7};

    if(predictTheWinner(nums))
        cout<<"Player 1 wins"<<endl;
    else
        cout<<"Player 2 wins"<<endl;

    return 0;
}