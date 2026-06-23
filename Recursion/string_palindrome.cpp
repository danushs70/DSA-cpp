#include<iostream>
using namespace std;
bool palindrome(string str, int s,int e)
{
    if(s>=e)
        return true;
    if(str[s] != str[e])
        return false;
    palindrome(str,s+1,e-1);
}
int main()
{
    string str="madam";
    string str2="hello";
    if(palindrome(str,0,str.length()-1))
        cout<<"string 1 is palindrome"<<endl;
    else
        cout<<"string 2 is not palindrome"<<endl;
    
    if(palindrome(str2,0,str2.length()-1))
        cout<<"string 2 is palindrome"<<endl;
    else
        cout<<"string 2 is not a palindrome"<<endl;

    return 0;
}