#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int> v;

    //v.push_back(element_to_push)  add element at the end
    v.push_back(1);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(45);
    // v.emplace_back(element_to_push) similar to push_back() but little diff
    v.emplace_back(50);

    //for each loop
    //auto in STL automatically detect the data type 
    for(auto e : v){
        cout<<e<<" ";
    }
    cout<<endl;

    cout<<"insert function in vector"<<endl;
    
    //{1, 20, 30, 40, 45, 50}
    // v.insert(position , element)
    v.insert(v.begin()+2,25);  //insert element 25 at index 2
    //{1, 20, 25, 30, 40, 45, 50}

    //{1, 20, 25, 30, 40, 45, 50}
    // v.insert(position , elements{e1, e2,....})
    v.insert(v.begin()+1 , { 2, 3 });
    //{1, 2, 3, 20, 25, 30, 40, 45, 50}

    // Inserting value 5, 3 times at index 3
    v.insert(v.begin() + 3, 3, 5);

    //list is similar to vector , in list push_front,pop_front will be there
    list<int> l{4, 5};
    l.push_front(3);//push 3 at front
    l.pop_back();//pop 5
    // Inserting all elements of list to vector
    v.insert(v.begin() + 3, l.begin(), l.end());

    //vector<int> v2 = {21, 21};
    vector<int> v2( 2, 21);
    
     // Inserting all elements in v2 to v
    v.insert(v.begin() + 8 , v2.begin(), v2.end());


    for(auto e : v){
        cout<<e<<" ";
    }
    cout<<endl;
    cout<<"End value v.end() points to after the last element not last element:"<<endl;

    cout<<*(v.end()-1)<<endl;

}
