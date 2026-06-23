#include<iostream>
#include<vector>
using namespace std;
void any_sorting_algorithm(vector<int> &arr)
{
    //use any sorting algorithm like-> merge sort,quick sort,insertion sort,bubble sort
}
void better_sol(vector<int> &nums)
{
    //just count how many time 0,1,2
    int c0=0,c1=0,c2=0;
    int i,n=nums.size();
    for(i=0;i<n;i++)
    {
        if(nums[i] == 0)
            c0++;
        else if(nums[i] == 1)
            c1++;
        else
            c2++;
    }
    //just overwrite a array
    int j=0;
    while(c0>0)
    {
        nums[j++]=0;
        c0 -=1;
    }
    while(c1>0)
    {
        nums[j++]=1;
        c1 -=1;
    }
    while(c2>0)
    {
        nums[j++]=2;
        c2 -= 1;
    }
}
void optimal(vector<int> &nums)
{
    int n=nums.size();
    int low,mid,high;
    low = 0;
    mid = 0;
    high = n-1;
    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[mid],nums[low]);
            mid +=1;
            low +=1;
        }
        else if(nums[mid] == 1)
        {
            mid +=1;
        }
        else //nums[mid] == 2
        {
            swap(nums[mid],nums[high]);
            high -=1;
        }
    }
}
int main()
{
    vector<int> arr = {0,1,0,2,1,0,2,1,0,1}; //array only contains 0,1,2 
    //better_sol(arr);
    optimal(arr);
    cout<<"after sorted: ";
    for(auto e:arr)
        cout<<e<<" ,";
    return 0;
}