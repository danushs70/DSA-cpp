#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void subsets(vector<int> &arr,vector<int> res,int index)
{
    if(index == arr.size())
    {
        cout<<"[ ";
        for(int e: res)
            cout<<e<<", ";
        cout<<"]"<<endl; 
        return;
    }
    res.push_back(arr[index]);
    for(int e: res)
            cout<<e<<", ";
    cout<<" push"<<endl;
    subsets(arr,res,index + 1);
    for(int e: res)
            cout<<e<<", ";
    cout<<"before pop, index:"<<index<<endl;
    res.pop_back();
    for(int e: res)
            cout<<e<<", ";
    cout<<" pop"<<endl;
    subsets(arr,res,index + 1);
}
int main()
{
    vector<int> arr = {3,1,2};
    subsets(arr,{},0);
}