#include<iostream>
#include<vector>
using namespace std;
int con_1(vector<int> &nums)
{
    int i,j=0,max=0;
    for(int a : nums)
    {
        if(a == 1)
        {
            j += 1;
            if(j > max )
                max = j;
        }
        else
        {
            j=0;
        }
    }
    return max;
}
int main()
{
    vector<int> nums ={1,1,0,1,0,1,0,1,1,1,1,0,0,0};

    int n = con_1(nums);
    cout<<"no.of consecutive 1's: "<<n;
}