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
ListNode* reverseKGroup(ListNode* head, int k)
{
    vector<int> li;
    ListNode *temp = head;
    while(temp != nullptr)
    {
        li.push_back(temp->val);
        temp = temp->next;
    }
    int i, n= li.size();
    for(i=0;i<n && (n-i) >= k;i+=k)
    {
        reverse(li.begin()+i,li.begin()+i+k);
    }
    temp = head;
    i = 0;
    while(temp != nullptr)
    {
        temp->val = li[i];
        i++;
        temp = temp->next;
    }
    return head;
}
ListNode *find_kth(ListNode *t,int k)
{
    while(k)
    {
        k--;
        t = t->next;
        if(t == nullptr)
            return nullptr;
    }
    return t;
}
ListNode * reverseKGroupwith_LL(ListNode *head,int k)
{
    ListNode *temp = head;
    ListNode *kth,*nextNode;
    while(temp != nullptr)
    {
        kth = find_kth(temp,k);
        if(kth == nullptr)
            break;
        nextNode = kth->next;
        kth->next = nullptr;

    }
}

int main()
{
    vector<int> list = {1,2,3,4,5};
    int i,n = list.size();
    ListNode e5(5);
    ListNode e4(4,&e5);
    ListNode e3(3,&e4);
    ListNode e2(2,&e3);
    ListNode e1(1,&e2);
    cout<<"Before reverse"<<endl;
    display(&e1);
    int k=2;
    ListNode *head = reverseKGroup(&e1,k);
    cout<<"After reverse K Group"<<endl;
    display(head);
}