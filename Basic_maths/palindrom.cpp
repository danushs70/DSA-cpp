#include<iostream>
using namespace std;
bool check_palin(int n)
{
    int c=n,rev=0,rem;
    while(c != 0)
    {
        rem = c % 10;
        rev = (rev * 10) + rem;
        c /= 10;
        //cout<<"rev "<<rev<<endl;
    }
    if(n == rev)
        {
            return true;
        } 
    return false;

}
int main(){
    int n= 76867;
    if(check_palin(n))
    {
        cout<<"Its a palindrome"<<endl;
    }
    else
    {
        cout<<"Its not a palindrome"<<endl;
    }
    return 0;
}