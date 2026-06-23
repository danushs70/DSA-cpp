#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;
string reverse_words(string s)
{
    stringstream ss(s);
    vector<string> words;
    string result,word;

    while(ss >> word)
    {
        words.push_back(word);
    }
    reverse(words.begin(),words.end());

    for(int i=0;i<words.size();i++)
    {
        result+=words[i];
        //result.append(words[i]);
        if(i != words.size())
            result+=" ";
            //result.append(" ");
    }

    return result;

}
int main()
{
    string s="i am Steven Marc";
    string s1 = reverse_words(s);
    cout<<"reverse word: "<<s1<<endl;
    return 0;
}