#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr ={1,2,0,1,4,1,0,4,3,5,};
    int i,j,k=3;// here k is window size
    int sum=0,max=0;
    int n=arr.size();
    //burteforuce method
    for(i=0;i<n-2;i++)
    {
        j=i;
        sum =0;
        while((j-i)<k)
        {
            sum +=arr[j];
            j +=1;
        }
        if(sum>max)
            max = sum;
    }
    cout<<"max: "<<max;
    return 0;
}