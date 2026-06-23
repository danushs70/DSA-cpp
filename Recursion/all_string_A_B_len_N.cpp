#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print_A_B(string str,int n)
{
    if(str.size() == n)
    {
        cout<<str<<endl;
        return ; 
    }
    print_A_B(str+"A",n);
    print_A_B(str+"B",n);

}
int main()
{
    int n = 3;
    print_A_B("",n);
}