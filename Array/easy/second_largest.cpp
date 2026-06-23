#include<iostream>
#include<vector>
using namespace std;
int second_lar(vector<int> &a)
{
    int n = a.size();
    int i,lar=a[0];
    int sec_lar=-1;// it return -1 if no second largest e.g a={55,55}
    for(i=0;i<n;i++)
    {
        if(a[i]>lar)
        {
            sec_lar = lar;
            lar = a[i];
        }
        else if(a[i] > sec_lar && a[i] != lar)//to handils duplicates e.g a ={45,35,45}
        {
            sec_lar = a[i];
        }
    }
    return sec_lar;
}
int main()
{
    vector<int> a = {1,2,3,56,5,78,99};

    int sec_largest = second_lar(a);
    cout<<"Second Largest element: "<<sec_largest<<endl;
    return 0;
}

