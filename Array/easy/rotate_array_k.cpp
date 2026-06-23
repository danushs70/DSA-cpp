#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int> &arr,int k)
{
    int n=arr.size();
    k = k % n;
    if(k==0)
        return ;
    
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());

}
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    int k=3;
    rotate(arr,k);
    for(auto e:arr)
        cout<<e<<", ";
    
    return 0;
}