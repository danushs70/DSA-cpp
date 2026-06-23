#include<iostream>
using namespace std;
int main(){
    int digit=67845;
    int count=0;
    while(digit != 0){
        digit /=10;
        count +=1;
        
    }
    cout<<"Count :"<<count;
}