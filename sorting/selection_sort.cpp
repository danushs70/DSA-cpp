#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a = {29, 7, 6, 12, 2 };
    int i,j,min;
    cout<<"before shoted: ";
    for(int e : a)
        cout<<e<<", ";
    cout<<endl;
    for(i=0;i<a.size()-1;i++)
    {
        min = i;
        for(j=i+1;j<a.size();j++)
        {
            if(a[min] > a[j])
                min = j;
        }
        swap(a[min],a[i]);
    }
    cout<<"After shorted: ";
    for(int e : a)
        cout<<e<<", ";
}