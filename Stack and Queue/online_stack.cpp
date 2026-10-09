#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind;
    StockSpanner() {
        
        ind = -1;
    }
    
    int next(int price) {
        ind += 1;
        while(!st.empty() && st.top().first <= price)
            st.pop();
        
        int ans = ind - (st.empty()?-1:st.top().second);
        st.push({price,ind});
        return ans;
    }
};
int main()
{
    StockSpanner *obj = new StockSpanner();
    cout<<"Push 100: "<<obj->next(100)<<" consiqutive days"<<endl;
    cout<<"Push 80: "<<obj->next(80)<<" consiqutive days"<<endl;
    cout<<"Push 60: "<<obj->next(60)<<" consiqutive days"<<endl;
    cout<<"Push 70: "<<obj->next(70)<<" consiqutive days"<<endl;
    cout<<"Push 60: "<<obj->next(60)<<" consiqutive days"<<endl;
    cout<<"Push 75: "<<obj->next(75)<<" consiqutive days"<<endl;
    cout<<"Push 85: "<<obj->next(85)<<" consiqutive days"<<endl;
}