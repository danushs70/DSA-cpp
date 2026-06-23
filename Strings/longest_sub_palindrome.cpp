#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {

        // 🔵 Odd length palindrome
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }

        // 🟢 Even length palindrome
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;

    cout << longestPalindrome(s);
    return 0;
}

/*
#include<iostream>
using namespace std;
void longest_sub_palindrome(const string s)
{
    int i,start,maxlen=0;
    string stack="";
    int n = s.size();
    for(i=0;i<n;i++)
    {
        
    }
}
int main()
{
    string s="abcfcbdab";
    longest_sub_palindrome(s);
    return 0;
}
    */