#include<iostream>
#include<math.h>
using namespace std;
bool armstrong(int n)
{
    int c=n,dig=0,l,arm=0;
    while(c != 0)
    {
        c /= 10;
        dig +=1;
    }
    c=n;
    while(c != 0)
    {
        l = c % 10;
        arm += pow(l,dig);
        //cout<<"armstrong "<<arm<<endl;
        c /= 10;
    }
    
    if(n == arm)
        return true;
    return false;
}
int main()
{
    int n=371;
    //  count total digit here 3.
    // 3^3 + 7^3 + 1^3
    if(armstrong(n))
        cout<<"Its a armstrong number"<<endl;
    else
        cout<<"This is not a armstrong"<<endl;

    return 0;
}