#include<iostream>
#include<vector>
using namespace std;
//intersection of two sorted array
vector<int> intersection(vector<int> &a1,vector<int> &a2)
{
    vector<int> inter;
    int n1=a1.size(),n2=a2.size();
    int i=0,j=0,k;
    while(i<n1 && j<n2)
    {
        if(inter.size() == 0 || inter.back()!= a1[i])
            if(a1[i] == a2[j])      //a1 ={1,2,3,4,5,6,7};
            {                       //a2 = {2,3,5,7,8,9,10,11,12,};
                inter.push_back(a1[i]);
                i += 1;
            }
            else if(a1[i]<a2[j])
                i += 1;
            else 
                j += 1;
                
    }
    return inter;
}
int main()
{
    vector<int> a1 ={1,2,3,4,5,6,7};
    vector<int> a2 = {2,3,5,7,8,9,10,11,12,};

    vector<int> result = intersection(a1,a2);
    cout<<"Intersection of a1 and a2: ";
    for(int e:result)
        cout<<e<<", ";
    
    
    return 0;
}