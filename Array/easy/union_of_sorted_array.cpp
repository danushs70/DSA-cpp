/*while(i<n1)
    {
        if(inter.size() == 0 || inter.back() != a1[i])
        {
            inter.push_back(a[i]);
            i += 1;
        }
    }
    while(j<n2)
    {
        if(inter.size() == 0 || inter.back() != a2[j])
        {
            inter.push_back(a2[j]);
            j += 1;
        }
    }*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> union_of_two_array(vector<int> &a, vector<int> &b)
{
        int i=0,j=0,n1=a.size(),n2=b.size();
        vector<int> arr;
        while(i<n1 && j<n2)
        {
            if(a[i] == b[j])
            {
                arr.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i] < b[j])
            {
                arr.push_back(a[i]);
                i++;
            }
            else
            {
                arr.push_back(b[j]);
                j++;
            }
        }
        while(i<n1)
        {
            arr.push_back(a[i]);
            i++;
        }
                //cout<<"j "<<j<<" n2 "<<n2<<endl;
        while(j<n2)
        {
            arr.push_back(b[j]);
            j++;
        }
        return arr;
}
int main()
{
    vector<int> num1 = {1,2,3,5,7,8}, num2 = {3,4,5,8,9,10};
    vector<int> union_array= union_of_two_array(num1,num2);
    cout<<"Union of the two array: ";
    for(int e: union_array)
    {
        cout<<e<<", ";
    }
    cout<<endl;
}