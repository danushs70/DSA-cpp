#include<iostream>
#include<vector>
#include<bits/stdc++.h>
//#include <algorithm>
//btter method
using namespace std;
int maxsub(vector<int> &arr,int k)
{
    int i,j,n= arr.size();
    map<long long,int> m ;
    int len=0,maxlen=0,sum=0;
    for(i=0;i<n;i++)
    {
        sum += arr[i];
        if(sum == k)
        {
            maxlen = max(maxlen,i+1);
        }
        
        int rem = sum - k;
        if(m.find(rem) != m.end())
        {
            len = i- m[rem];
            maxlen = max(maxlen , len);
        }
        if(m.find(sum) == m.end())
        {
            m[sum] = i;
        }

    }
    return maxlen;
}
/*
    optimal solution, but only for postive non-zero numbers,
    for negative and zero,positive mixed array only better solution no optimal

    for positive only
    int maxsub(vector<int> &arr,int num)
    {
        int right=0,left=0;  //two pointer
        int n=arr.size();
        int sum=a[0],maxlen=0,len=0;
        while(right < n)
        {
            while(left <= right && sum > k)
            {
                sum -= a[left];
                left++;
            }
            if(sum == k)
            {
                len = right - left +1;
                maxlen = max(maxlen,len);
            }
            right++;
            if(right < n)
                sum += a[right]
        }
        return maxlen;
    }
*/
int main()
{
    vector<int> arr ={1,2,0,6,2,4,1,1,0,4,3,5,};
    int i,j,k,s=7;// s is a sub array sum,which sub array sum is = s and max length 
    int sum=0,len=0,st,end;
    int n=arr.size();
    //burteforuce method
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=0;
            for(k=i;k<=j;k++)
            {
                sum += arr[k];
            }
            if(sum == s)
            {
                //len = max(len,(j-i)+1); or
                if(len < (j-i)+1)
                {
                    len = (j-i)+1;
                    st=i;
                    end=j;

                }
            }
        }
    }
    cout<<"max len of subarray sum  S: "<<len<<endl<<"starting index: "<<st<<", end index:"<<end<<endl;
    
    cout<<"Max len better solution: "<<maxsub(arr,s);

    return 0;
}