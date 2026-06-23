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
ListNode *detectCycle(ListNode *head) //optimal 
{
        
    ListNode *slow = head, *fast=head;
    if(head == nullptr)
        return nullptr;
    int cycle = 0;
    while(fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            cycle = 1;
            break;
        }
    }
    if(!cycle)
        return nullptr;
        
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
ListNode *detectCycle_brute(ListNode *head) //use set or hash map
{
    unordered_set<ListNode*> visited;
    ListNode *temp = head;
    while(temp != nullptr )
    {
        if(visited.find(temp) != visited.end())
        {
            return temp;
        }
        visited.insert(temp);
        temp = temp->next;
    }
    return nullptr;
}
int main()
{
    ListNode e5(5);
    ListNode e4(4,&e5);
    ListNode e3(3,&e4);
    ListNode e2(2,&e3);
    ListNode e1(1,&e2);
    e5.next = &e3;
    /*     1 -> 2 -> 3 -> 4 -> 5 ---/
                    ^               |
                    |               |
                    |_______________|    
            it has a cycle "5" next is "3"                             
    */
    
    ListNode *cycle_start = detectCycle_brute(&e1);

    if(cycle_start == nullptr)
        cout<<"dont have a cycle :-1"<<endl;
    else{
        cout<<"Cycle at node :"<<cycle_start->val<<endl;
    }


}

/* q.no 142 

Given the head of a linked list, return the node where the cycle begins. 
If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list 
that can be reached again by continuously following the next pointer. Internally, 
pos is used to denote the index of the node that tail's next pointer is 
connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not 
passed as a parameter.
Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to 
the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects 
to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

*/