#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode *next) : val(v), next(next) {}
};
ListNode* reverseList(ListNode* head)
{
    if(head == nullptr)
        return nullptr;
    ListNode* prev = nullptr,*temp,*front;
    temp = head;
    while(temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
     
}
void display(ListNode *head)
{
    if(head == nullptr)
    {
        cout<<"No element in the List"<<endl;
        return;
    }
    ListNode* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->val<<", ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    ListNode e1(1);
    ListNode e2(2,&e1);
    ListNode e3(3,&e2);
    ListNode e4(4,&e3); // 4 -> 3 -> 2 -> 1 -> nullptr
    cout<<"Before reverse"<<endl;
    display(&e4);

    ListNode *head = reverseList(&e4);
    cout<<"After reversed:"<<endl;
    display(head);


}