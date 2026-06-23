#include<iostream>
#include<string>
using namespace std;
// this program return the longest odd sub string 
//e.g  srt="52" output-> "5", str="2406" output->"" ,
// str="2412" output-> 241 , str="5301" output-> "5301"

string longest_odd(string &str)
{
    int i;
    for(i=str.size()-1;i>=0;i--)
    {
        if((str[i] - '0') % 2 == 1)
            return str.substr(0,i+1);
    }
    return "";
}
int main()
{
    string str="2412";
    cout<<longest_odd(str);
    return 0;
}