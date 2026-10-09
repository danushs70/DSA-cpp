#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int largest_Area(vector<int> &heights)
{
    stack<int> st;
    int i,n=heights.size();
    int max_area = 0;
    for(i=0;i<n;i++)
    {
        while(!st.empty() && heights[st.top()] > heights[i])
        {
            int element, next_small, prev_small;
            element = st.top();
            st.pop();
            next_small = i;
            prev_small = st.empty()?-1:st.top();
            max_area = max(max_area, (heights[element] * (next_small - prev_small -1)));
            
        }
        st.push(i);
    }

    while(!st.empty())
    {
        int element, next_small, prev_small;
        element = st.top();
        st.pop();
        next_small = n;
        prev_small = st.empty()?-1:st.top();
        max_area = max(max_area, (heights[element] * (next_small - prev_small -1)));
    }
    return max_area;
}
int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    cout<<"Largest Area rect: "<<largest_Area(heights)<<endl;

}