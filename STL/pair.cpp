#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    //pair it store the value in pair format
    pair<int,int> p ={1 , 2}; 

    //to access 1 in p
    cout<<p.first<<endl;
    //to access 2 in p
    cout<<p.second<<endl;

    cout<<"nested pair"<<endl;

    pair<int,pair<int,int>> np[] = { {1, {2,5}} , {2,{3,4}} };

    //to access nested pair
    cout<<np[0].first<<" "<<np[0].second.first<<" "<<np[0].second.second<<endl;

    pair<int, string> p1 = {1, "Apple"};
    
    // Elements are accessed using (.) operator
    cout << p1.first << " " << p1.second << endl;

    cout<<endl<<"other example"<<endl;
    pair<int, string> p3 = {1, "abcd"};

    // Update first and second value of pair
    p3.first = 2;
    p3.second = "its new";
    cout << p3.first << " " << p3.second<<endl;
    
    
    return 0;
}
