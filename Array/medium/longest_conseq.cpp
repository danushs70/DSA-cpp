#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& nums)
{
    unordered_set<int> st;
    int i,n=nums.size();
    int longest=1,count=0;
    if(n == 0)
        return 0;
    for(i=0;i<n;i++)
    {
        st.insert(nums[i]);
    }
    for(int e : st)
    {
        if(st.find(e - 1) == st.end()) // start from first element of sequence, if set not contains e-1 then e is starting element
        {
            count = 1;
            int x = e;
            while(st.find(x+1) != st.end())
            {
                count++;
                x += 1; //find next element
            }
            longest = max(longest,count);
        }
    }
    return longest;
}
int long_conq_usingsort(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    int longest=1,count=0;
    int lastsmall = INT_MIN;
    int i,j,n=nums.size();
    for(i=0;i<n;i++)
    {
        if(nums[i] - 1 == lastsmall)
        {
            count++;
            lastsmall = nums[i];
        }
        if(nums[i] != lastsmall)
        {
            count = 1;
            lastsmall = nums[i];
        }
        longest = max(longest,count);
    }
    return longest;
}
int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    cout<<"Longese seq len: "<<longestConsecutive(nums)<<endl;
    cout<<"Longese seq len: "<<long_conq_usingsort(nums);

    return 0;
}