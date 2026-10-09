#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int no_of_inverse_pair(vector<int> arr)//means arr[i] > arr[j] and i < j 
{
    stack<int> st;
    int n = arr.size();
    for(int i = n-1;i>=0; i++)
    {
        while(!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }
        
    }
}
int main()
{
    vector<int> arr = {5,3,2,1,4};
    cout<<"no.of inverse pair"<<no_of_inverse_pair(arr)<<endl;

}