#include<iostream>
#include<math.h>
using namespace std;
void normal(int n)// time complexity O(n)
{
    cout<<"normal Method O(n): ";
    for(int i=1;i<=n;i++)
    {
        // i % n is wrong, n % i is correct
        if(n % i == 0)
            cout<<i<<", ";
    }
    cout<<endl;
}
void optimal(int n)// optimal solution time complexity O(sqrt(n))
{
    cout<<"Optimal time complexity O(sqrt(n)): ";
    //for(int i=0; i*i <=n ;i++)
    //       (or)
    for(int i=1;i<=sqrt(n);i++)  
    {
        
        if(n%i == 0)
        {
            cout<<i<<", ";
            if( (n/i) != i)
                cout<<(n/i)<<", ";
        }
    }  
    cout<<endl;
}
int main()
{
    int n = 36;
    normal(n);
    optimal(n);
    return 0;
}