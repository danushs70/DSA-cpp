#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &arr,int s,int e)
{
    for(int i=s;i<=e;i++)
        cout<<arr[i]<<", ";
    cout<<endl;
}
void merge(vector<int> &arr,int p,int q, int r)
{
    //print(arr,p,r);
    int nl = q - p+1;
    int nr = r-q;
    vector<int> left(nl),right(nr);
    int i,j,k;
    for(i=0;i<nl;i++)
        left[i] = arr[p+i];
    for(j=0;j<nr;j++)
        right[j] = arr[q+1 + j];

    i=0,j=0,k=p;
    while(i<nl && j<nr)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i += 1;
        }
        else
        {
            arr[k] = right[j];
            j += 1;
        }
        k += 1;
    }

    while(i < nl)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    //print(arr,p,r);
}
void mergesort(vector<int> &arr,int p,int r)
{
    if(p>=r)
        return ;
    int q = (p+r)/2;
    print(arr,p,q);
    mergesort(arr,p,q);
    print(arr,q+1,r);
    mergesort(arr,q+1,r);
    merge(arr,p,q,r);
}

int main()
{
    vector<int> arr = {2,4,1,67,8,5};
    cout<<"Before sorted: ";
    print(arr,0,arr.size()-1);
    mergesort(arr,0,arr.size()-1);
    cout<<"After sorted: ";
    print(arr,0,arr.size()-1);
    return 0;
}