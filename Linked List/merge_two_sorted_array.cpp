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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
        
        ListNode *dummy = new ListNode(-1); //dummy node for starting 
        ListNode *temp = dummy;
        ListNode *t1 = list1, *t2 = list2;
        while(t1 != nullptr && t2 != nullptr)
        {
            if(t1->val > t2->val)
            {
                temp->next = t2;
                t2 = t2->next;
            }
            else if(t1->val < t2->val)
            {
                temp->next = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        if(t1 != nullptr)
            temp->next = t1;
        if(t2 != nullptr)
            temp->next = t2;
        return dummy->next;
}

/*
Node* sortTwoLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}
*/