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
ListNode* delete_last_N(ListNode *head,int n)
{
    ListNode *slow = head, *fast = head;
    int i,j;
    for(i=0;i<n;i++)
    {
        fast = fast->next;
    }
    //cout<<fast->val<<", ";
    //use two pointer approach fast and solw pointer
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    if(slow = head)
    {
        head = head->next;
        delete slow;
        return head;
    }
    slow->next = slow->next->next;
    return head;

}
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *temp = head;
    long long count=0;
    while(temp != nullptr)
    {
        count++;
        temp = temp -> next;
    }    
    long long pos = count - n;
    long long i=0;
    temp = head;
    ListNode *prev = head;
    while(temp != nullptr && i != pos)
    {
        i++;
        prev = temp;
        temp = temp->next;
    }
    if(prev == temp) //for delete head node 
    {
        temp = temp->next;
        delete prev;
        return temp;
    }
    prev->next = temp->next;
    delete temp;

    return head;
}
int main()
{
    ListNode e1(1);
    ListNode e2(2,&e1);
    ListNode e3(3,&e2);
    ListNode e4(4,&e3); // 4 -> 3 -> 2 -> 1 -> nullptr
    int n=2;
    delete_last_N(&e4,n);

}