#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> next_grater(vector<int> &nums)
{
    stack<int> st;
    vector<int> ans(nums.size(),-1);
    int i;
    for(i=nums.size()-1;i>=0;i--)
    {
        
        while(!st.empty() && st.top() <= nums[i])
        {
            st.pop();
            
        }
        if(!st.empty())
        {
            ans[i] = st.top();
        } 
        st.push(nums[i]);

    }
    return ans;
}
int main()
{
    vector<int> nums = {1,3,4,2};
    vector<int> ans = next_grater(nums);
    for(int e: ans)
        cout<<e<<", ";

}