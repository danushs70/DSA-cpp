#include<iostream>
#include<vector>
using namespace std;
bool is_sorted(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;
}
int main()
{
    vector<int> arr={1,2,4,7,8};
    
    if(is_sorted(arr))
        cout<<"Sorted"<<endl;
    else
        cout<<"Not in sorted"<<endl;
}