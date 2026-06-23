#include<iostream>
#include<vector>
using namespace std;
int buy_and_sell(vector<int> &nums)
{
    int maxprofit=0,i,j,cost;
    int n=nums.size();
    int minimum=nums[0];
    for(i=1;i<n;i++)
    {
        cost = nums[i] - minimum;
        maxprofit = max(maxprofit,cost);

        minimum = min(minimum,nums[i]);
    }
    return maxprofit;
}

int main()
{
    vector<int> price = {7,1,5,3,6,4};//stock price at each day

    cout<<"max profit: "<<buy_and_sell(price);
    return 0;
}