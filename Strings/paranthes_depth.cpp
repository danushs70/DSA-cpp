#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int depth_of_nested(string str)
{
    int n=str.size();
    int count=0,max_nested=0;
    for(char ch:str)
    {
        if(ch == '(')
        {
            count++;
            max_nested = max(max_nested,count);
        }
        else if(ch == ')')
        {
            count--;
        }
    }
    return max_nested;
}
int main()
{
    string str ="(1+(2*3)+((8)/4))+1";
    cout<<"Max Depth of paranthes: "<<depth_of_nested(str);
    return 0;
}