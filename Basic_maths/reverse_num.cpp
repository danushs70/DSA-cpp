#include<iostream>
using namespace std;
int main()
{
    int n=567;
    int c=n,rev=0,rem;
    while(c!=0){
        rem = c%10;
        rev = (rev * 10) + rem;
        c /=10;
       /* cout<<"rem "<<rem<<endl;
        cout<<"c "<<c<<endl;
        cout<<rev<<endl;   */
       
    }
    cout<<"Reverse :"<<rev<<endl;
}