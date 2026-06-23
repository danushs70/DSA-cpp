#include<iostream>
using namespace std;
bool normal_is_prime(int n)// time O(n)
{
    for(int i=2;i<=n-1;i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
bool optimal_is_prime(int n) // time O(sqrt(n))
{
    for(int i=2;i*i<=n;i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n=7;
    if(optimal_is_prime(n))
    {
        cout<<"Its a prime number"<<endl;
    }
    else{
        cout<<"its not a prime number"<<endl;
    }
    return 0;
}
