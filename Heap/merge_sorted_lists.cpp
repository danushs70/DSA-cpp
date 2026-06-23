#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
 ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int i,n = lists.size();
    if(n == 0)
        return nullptr;
    ListNode *head,*prev = nullptr;
    for(i=0;i<n;i++)
    {
        //  [[],[1]] to handil this
        if(lists[i] != nullptr)
        {
            head = lists[i];
            break;
        }  
    }
    for(i=0;i<n;i++)
    {
        ListNode *temp = lists[i];
        if(temp == nullptr)
            continue;
        if(prev != nullptr)
            prev->next = temp;
        while(temp != nullptr)
        {
            pq.push(temp->val);
            prev = temp;
            temp = temp->next;
        }
    }
    ListNode *temp = head;
    while(!pq.empty())
    {
        int val = pq.top();
        pq.pop();
        temp->val = val;
        temp = temp->next;
    }
    return head;

}

int main()
{
    vector<ListNode*> three_lists;
    //lists = [[1,4,5],[1,3,4],[2,6]]
    ListNode *e3 = new ListNode(5);
    ListNode *e2 = new ListNode(4,e3);
    ListNode *h1 = new ListNode(1,e2);

    three_lists.push_back(h1);

    ListNode *e23 = new ListNode(4);
    ListNode *e22 = new ListNode(3,e23);
    ListNode *h2 = new ListNode(1,e22);

    three_lists.push_back(h2);

    
    ListNode *e32 = new ListNode(6);
    ListNode *h3 = new ListNode(2,e32);

    three_lists.push_back(h3);
    //ListNode *empty = nullptr; // this line is for testcases
    //vector<ListNode*> test = {empty};
    //ListNode *final_merge_list = mergeKLists(test);
    ListNode *final_merge_list = mergeKLists(three_lists);
    display(final_merge_list);
}