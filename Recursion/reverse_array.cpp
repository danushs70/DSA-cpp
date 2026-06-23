#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int> &arr,int s,int e)
{
    if(s>=e)
        return ;
    swap(arr[s],arr[e]);
    reverse(arr, s+1 , e-1);
}
int main()
{
    vector<int> arr = {1,2,3,4,5};

    cout<<"Array before reverse: "<<endl;
    for(auto a:arr)
        cout<<a<<", ";
    cout<<endl;

    reverse(arr,0,arr.size()-1);

    cout<<"Array after reversed: "<<endl;
    for(int a:arr)
        cout<<a<<", ";

    return 0;
}