#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    priority_queue<int> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        for(int e:nums)
            pq.push(e);
        this->k = k;
    }
    
    int add(int val) {
        pq.push(val);
        stack<int> st;
        int temp = k-1;
        while(temp)
        {
            st.push(pq.top());
            pq.pop();
            temp--;
        }
        int ans = pq.top();
        while(!st.empty())
        {            
            pq.push(st.top());
            st.pop();
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kth(3, nums );
    cout<<"push 3: "<<kth.add(3)<<endl;
    cout<<"push 5: "<<kth.add(5)<<endl;
    cout<<"push 10: "<<kth.add(10)<<endl;
    cout<<"push 9: "<<kth.add(9)<<endl;
    cout<<"push 4: "<<kth.add(4)<<endl;
}