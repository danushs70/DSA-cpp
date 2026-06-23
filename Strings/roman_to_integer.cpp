#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
        unordered_map<char, int> val = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50},
            {'C',100}, {'D',500}, {'M',1000}
        };

        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && val[s[i]] < val[s[i + 1]]) {
                //If current value < next value → subtract
                
                result -= val[s[i]];
            } else {
                //else → add
                result += val[s[i]];
            }
        }
        return result;
    }