#include<iostream>
#include<vector>
using namespace std;
void move_zero(vector<int> &arr)
{
    int n=arr.size();
    int i,j=0;
    for(i=0;i<n;i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i],arr[j]);
            j += 1;
        }
    }
    while(j<n)
    {
        arr[j]=0;
        j++;
    }
}
int main()
{
    vector<int> arr = {1,0,0,2,3,0,4,3,0};
    move_zero(arr);
    for(int e:arr)
        cout<<e<<", ";
    
    return 0;
}