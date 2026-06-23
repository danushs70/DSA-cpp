#include<iostream>
#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
       double res=1;
       long long n1=n;
       if(n<0)
            n1 *= -1;
        while(n1 > 0)
        {
            if(n1 % 2 == 0)
            {
                x *= x;
                n1 /= 2;
            }
            else
            {
                res *= x;
                n1 -= 1;
            }
        }
        if(n<0)
            return (1/res);
        return res;
    }

int main()
{
    double x = 2.0;
    int n = 10;

    // Calculate x raised to n
    double result = myPow(x, n);

    // Print the result
    cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}
/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/