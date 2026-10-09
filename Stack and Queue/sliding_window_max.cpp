#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> max_element_each_window(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    int i,n = nums.size();
    for(i=0;i<n;i++)
    {
        if (!dq.empty() && dq.front() <= i - k) 
        {
            dq.pop_front();   //window range
        }
        while(!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        if(dq.size() >= k )
        {    
            dq.pop_front();
        }
        
        dq.push_back(i);

        if(i+1 >= k)
        {
            ans.push_back(nums[dq.front()]);
        }
        
    }
    return ans;
}
int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = max_element_each_window(nums,k);
    for(int e:ans)
        cout<<e<<", ";
    cout<<endl;
}