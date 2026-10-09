#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty())
            st.push({value,value});
        else{
        int mini = min(value,getMin());
        st.push({value,mini});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main()
{
    MinStack* obj = new MinStack();
   obj->push(5);
   obj->pop();
   obj->push(4);
   obj->push(2);
   obj->push(8);
   cout<<"Top: "<<obj->top()<<endl;
   cout<<"Minimum: "<<obj->getMin()<<endl;

}