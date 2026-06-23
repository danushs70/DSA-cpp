#include<iostream>
using namespace std;
void fact(int f,int n)
{
    //cout<<"fact "<<f<<endl;
    if(n <= 0)
    {
        cout<<"Factorial: "<<f<<endl;
        return ;
    }
    fact(f*n,n-1);
}
int factorial(int n)
{

    // Calculating factorial of number
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n = 5,f=1;
    fact(f,n);

    return 0;
}