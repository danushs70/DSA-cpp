#include<iostream>
using namespace std;
void rec(int sum,int n)
{
    if(n < 0)
    {
        cout<<"Sum: "<<sum<<endl;
        return ;
    }
    sum+=n;
    rec(sum,n-1);
}
int main()
{
    int n = 5;
    rec(0,n);
    return 0;
}