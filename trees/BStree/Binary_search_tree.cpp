#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:

    // Insert
    Node* insert(Node* root, int key) {

        if(root == NULL)
            return new Node(key);

        if(key < root->data)
            root->left = insert(root->left, key);

        else if(key > root->data)
            root->right = insert(root->right, key);

        return root;
    }

    // Find Minimum Node
    Node* findMin(Node* root) {
        while(root->left != NULL)
            root = root->left;
        return root;
    }

    // Delete
    Node* deleteNode(Node* root, int key) {

        if(root == NULL)
            return NULL;

        if(key < root->data)
            root->left = deleteNode(root->left, key);

        else if(key > root->data)
            root->right = deleteNode(root->right, key);

        else {

            // Case 1 : No child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2 : One child (right)
            else if(root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2 : One child (left)
            else if(root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3 : Two children
            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    // Inorder Traversal
    void inorder(Node* root) {

        if(root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {

    BST tree;
    Node* root = NULL;

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);

    cout << "Before Deletion: ";
    tree.inorder(root);

    root = tree.deleteNode(root, 50);

    cout << "\nAfter Deletion: ";
    tree.inorder(root);

    return 0;
}
