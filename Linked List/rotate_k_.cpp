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
ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr,*temp = head,*front;
    while(temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
ListNode* rotateRight(ListNode* head, int k)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode *temp = head;
    int n=0;
    while(temp != nullptr)
    {
        n++;
        temp = temp->next;
    }
    k %= n;
    if(k == 0)
        return head;
    // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode *newhead1 = reverse(head);
    // 5 -> 4 -> 3 -> 2 -> 1 -> nullptr
    ListNode *prev = newhead1, *curr = newhead1;
    while(k)
    {
        prev = curr;
        curr = curr->next;
        k--;
    }
    prev->next = nullptr;
    // 5 -> 4 -> nullptr,    3 -> 2 -> 1 -> nullptr
    ListNode *newhead2 = reverse(curr);
    // 5 -> 4 -> nullptr,    1 -> 2 -> 3 -> nullptr
    newhead1 = reverse(newhead1);
    // 4 -> 5 -> nullptr,    3 -> 2 -> 1 -> nullptr
    temp = newhead1;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newhead2;
    return newhead1;
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
    ListNode e5(5);
    ListNode e4(4,&e5);
    ListNode e3(3,&e4);
    ListNode e2(2,&e3);
    ListNode e1(1,&e2);
    cout<<"Before rotate"<<endl;
    display(&e1);
    int k=2;
    ListNode *head = rotateRight(&e1,k);
    cout<<"After reversed:"<<endl;
    display(head);
}