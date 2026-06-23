#include<iostream>
using namespace std;
bool isValid(string s) {
        if(s.size() == 0)
            return true;
        string stack;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] =='{' || s[i] =='[')
                stack.push_back(s[i]);
            else if(s[i] == ')')
            {
                if(!stack.empty() && stack.back() == '(')
                    stack.pop_back();
                else
                    return false;
            }
            else if(s[i] == '}')
            {
                if(!stack.empty() &&stack.back() == '{')
                    stack.pop_back();
                else
                    return false;
            }
            else
            {
                if(!stack.empty() && stack.back() == '[')
                    stack.pop_back();
                else
                    return false;
            }
        }
        if(stack.empty())
            return true;
        return false;
    }
int main()
{
    string s = "()";
    if(isValid(s))
        cout<<"Valid"<<endl;
    else
        cout<<"Not Valid"<<endl;
}