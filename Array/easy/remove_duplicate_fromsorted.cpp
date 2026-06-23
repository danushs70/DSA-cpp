#include<iostream>
#include<vector>
using namespace std;
int remove_dupli(vector<int> &arr)
{
    int i,j=0;  //two pointer approach
    int n=arr.size(); 
    for(i=0;i<n;i++)
    {
        if(arr[i] != arr[j])
        {
            j +=1;
            swap(arr[i],arr[j]);
        }

    }
    return j;
}
int main()
{
    vector<int> arr ={1,2,2,3,3,4,5,5,5,6,7,7,8,9,9};

    int uniq_upto = remove_dupli(arr);
    cout<<"unique upto: "<<uniq_upto<<endl;
    for(auto e:arr)
        cout<<e<<", ";
    cout<<endl;
    for(int i=0;i<=uniq_upto;i++)
        cout<<arr[i]<<", ";
    return 0;
}