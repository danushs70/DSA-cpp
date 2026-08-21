#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string kth_permutation(int n,int k)
{
    int fact = 1,i;
    vector<int> nums;
    for(i=1;i<n;i++) // find factroial of n-1
    {
        nums.push_back(i);
        fact = fact * i;
    }
    nums.push_back(n);
    string ans = "";
    k = k - 1; // we start from 0th permutation 
    while(true)
    {
        ans = ans + to_string(nums[k/fact]);
        nums.erase(nums.begin() + (k/fact));
        if(nums.size() == 0)
            break;
        k = k % fact;
        fact = fact/nums.size();
    }
    return ans;
}
int main()
{
    int n = 4; // 1,2,3,4
    int k = 16;
    string a = kth_permutation(n,k);
    cout<<a<<endl;
}