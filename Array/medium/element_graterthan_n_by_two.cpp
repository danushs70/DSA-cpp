#include<iostream>
#include<vector>
#include<map>
using namespace std;
int brute_fource(vector<int> &nums)
{
    int i,j,n=nums.size();
    int count=0;
    for(i=0;i<n;i++)
    {
        count = 0;
        for(j=0;j<n;j++)
        {
            if(nums[i] == nums[j])
                count++;
        }
        if(count > (n/2))
            return nums[i];
    }
    return -1; //return -1 if no element count is grater than n/2
}
int better(vector<int> &nums)
{
    int n=nums.size();
    int i;
    map<int,int> m;
    for(i=0;i<n;i++)
    {
        m[nums[i]]++;
    }
    int high_freq=0;
    for(auto p:m)
    {
        if(p.second > (n/2))
            return p.first;
    }
    return -1;
    
}
int optimal(vector<int> &nums)
{
    int n=nums.size();
    int i,element,count=0;
    for(i=0;i<n;i++)
    {
        if(count == 0)
        {
            element = nums[i];
            count++;
        }
        else if(element == nums[i])
        {
            count++;
        }
        else 
        {
            count--;
        }
    }
    //here after count not used

    count = 0;
    for(i=0;i<n;i++)
    {
        if(nums[i] == element)
            count++;
    }
    if(count > (n/2))
        return element;
    return -1;
}
int main()
{
    vector<int> arr ={1,2,4,5,4,2,4,4,4,4,4};
    cout<<"Element grater than n/2: "<<brute_fource(arr);
    //cout<<"Element grater than n/2: "<<better(arr);
    //cout<<"Element grater than n/2: "<<optimal(arr);
    return 0;
}