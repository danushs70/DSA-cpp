#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:

    class Node{
    public:
        int key, val;
        Node *next;
        Node *prev;
        Node(int _key,int _val)
        {
            key = _key;
            val = _val;
        }
    };
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    int cpp;
    unordered_map<int,Node*> m;

    void addnode(Node *newnode)
    {
        Node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(Node *newnode)
    {
        Node* delprev = newnode->prev;
        Node* delnext = newnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    LRUCache(int capacity) {
        cpp = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) != m.end())
        {
            Node *resnode = m[key];
            int res = resnode->val;
            deletenode(resnode);
            addnode(resnode);
            m.erase(key);  //erase old addr hash
            m[key] = head->next; //add new addr in hash
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            Node *exitsingnode = m[key];
            m.erase(key);
            deletenode(exitsingnode);
        }
        if(m.size() == cpp)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new Node(key,value));
        m[key] = head->next;
    }
};

int main()
{
    LRUCache LRU(2);
    vector<int> result;
    LRU.put(1,1);
    LRU.put(2,2);
    result.push_back(LRU.get(1));
    LRU.put(3,3);
    result.push_back(LRU.get(2));
    LRU.put(4,4);
    result.push_back(LRU.get(1));
    result.push_back(LRU.get(3));
    result.push_back(LRU.get(4));

    for(int e: result)
    {
        cout<<e<<", ";
    }

}