#include<iostream>
using namespace std;
int normal_method_1_(int a,int b)
{
    int gcd=1;
    for(int i=1;i<=min(a,b);i++)
    {
        if( a%i == 0 && b%i == 0)
            gcd=i;
    }
    return gcd;
}
// in method two, we iterate loop form min(a,b) to 1 ,reverse
//because it output excepted is higher value instead of 1 to min(a,b) 
//we did min(a,b) to 1,here we have to break because once we get first higher value its answer
int normal_method_2_(int a,int b)
{
    int gcd=1;
    //cout<<"min "<<min(a,b)<<endl;
    for(int i=min(a,b);i>1;i--)
    {
        //cout<<i<<"\%9 "<<(a%i)<<" "<<i<<"\%12 "<<(b%i)<<endl;
        if( a%i == 0 && b%i == 0)
        {
            gcd=i;
            break;
        }
    }
    return gcd;
}
//optimal method using eudidum algorithm 
// in this algorithm there is formula 
// gcd(a,b) = gcd(a-b,b) for all (a >=b)
int optimal_method(int a,int b)
{
    while(a>0 && b>0)
    {
        if(a>b)
            a %= b;
        else
            b %= a;
    }
    if(a == 0)
        return b;
    else
        return a;
}
int main()
{
    int a=9,b=12;
    cout<<"normal method 1 GCD(or)HCF: "<<normal_method_1_(a,b)<<endl;
    cout<<"normal method 2 GCD(or)HCF: "<<normal_method_2_(a,b)<<endl;
    cout<<"Optimal method GCD(or)HCF: "<<optimal_method(a,b)<<endl;

    return 0;
}