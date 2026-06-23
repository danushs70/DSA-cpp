#include<iostream>
using namespace std;
int main()
{
    int i=3;
    string s="dsubsdkfsubdsfsub";
    string sub="sub";
    cout<<s.find(sub)<<" "<<s.find(sub,i);
    
    
    return 0;
}