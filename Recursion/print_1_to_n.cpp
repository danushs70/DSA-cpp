#include<iostream>
using namespace std;
void rec(int i,int n)
{
    if(i > n)
        return ;
    cout<<i<<" ";
    rec(i+1,n);
}
int main()
{
    int n = 10;
    rec(1,n);
    return 0;
}