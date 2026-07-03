#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    int i = 0, n = s.size();
    
    while(i < n && s[i] == ' ')
        i++;
    
    int sign = 1;
    long long num = 0;
    if(i< n && s[i] == '+' || s[i] == '-')
    {
        if(s[i] == '-')
        {
            sign = -1;
        }
        i++;
    } 
    
    while(i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        //integer overflow check
        if(num > INT_MAX/10 || (num == INT_MAX/10 && digit > 7))
        {
            if(sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        i++;
        num = num * 10 + digit;
    }
    return sign*num;
            
}

int main()
{
    string s = " -043";
    int a = myAtoi(s);
    cout<<s<<" integer value is: "<<a<<endl;
}