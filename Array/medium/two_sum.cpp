#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int two_sum(vector<int> &arr,int k)//time complixity O(n)+O(n log n)
{
    sort(arr.begin(),arr.end());
    int left=0,right=arr.size()-1;
    int sum=0;
    while(left < right )
    {
        sum = arr[left] + arr[right];
        if(sum == k)
        {
            cout<<"left,right "<<left<<" "<<right;
            return left,right;
        }
        else if(sum < k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return NULL,NULL;
}
pair<int,int> two_sum_o(vector<int> &arr,int k) //time O(n) , space O(n)
{
   int i,j,n=arr.size(),ele;
   unordered_map<int,int> hash;
    for(i=0;i<n;i++)
    {
        ele = k - arr[i];
        if(hash.find(ele) != hash.end())
        {
            return {hash[ele],i};
        }
        hash[arr[i]] = i;
    }
    return {-1,-1};
}
int main()
{
    vector<int> arr = {1,2,1,4,8,3,};
    int k=7;
    pair<int,int> elements = two_sum_o(arr,k);
    cout<<"indexs of two sum: "<<elements.first<<" "<<elements.second;
    return 0;
}