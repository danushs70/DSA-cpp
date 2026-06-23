#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longest_sub_str(const vector<string> &str)
{
    int i;
    string prefix=str[0];
    for(i=1;i<str.size();i++)
    {
        while(str[i].find(prefix) != 0)
        {
            prefix.pop_back();//remove last char str[0]

            if(prefix.empty())
                return "";
        }
    }
    return prefix;
}
int main()
{
    vector<string> str= {"flower","flow","flight"};
    cout<<"Longest Perfix: "<<longest_sub_str(str);
}