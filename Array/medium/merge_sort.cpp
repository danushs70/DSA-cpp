#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr,int low,int mid,int high)
{
    vector<int> temp;
    int left,right,i,j;
    left = low;
    right = mid+1;
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while(left <= mid)
        temp.push_back(arr[left++]);
    while(right <= high)
        temp.push_back(arr[right++]);
    
    for(i=low; i <= high ; i++)
    {
        arr[i] = temp[i-low];
    }

}
void mergesort(vector<int> &arr,int low,int high)
{
    if(low >= high)
        return;
    int mid = low+((high - low)/2);
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main()
{
    vector<int> arr ={3,2,5,7,8,1,4,9,6};
    int n=arr.size();
    mergesort(arr,0,n-1);
    for(int e: arr)
        cout<<e<<", ";
    return 0;
}
