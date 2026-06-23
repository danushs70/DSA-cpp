#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge_2_array(vector<int> &num1,int m,vector<int> &num2,int n)
{
    int i=m-1,j=0;
    while(i>= 0 and j < n)
    {
        if(num1[i] > num2[j])
        {
            int temp = num1[i];
            num1[i] = num2[j];
            num2[j] = temp;
            i--;
            j++;
        }
        else{
            break;
        }
    }
    sort(num1.begin(),num1.begin()+m);
    sort(num2.begin(),num2.begin()+n);

}
int main()
{
    vector<int> arr1 = {1,2,3,0,0,0}, arr2= {2,5,6};
    int m = arr1.size(), n = arr2.size();
    merge_2_array(arr1,3,arr2,3);
    for(int e: arr1)
        cout<<e<<", ";
    cout<<endl;
    for(int e: arr2)
        cout<<e<<", ";
    
}