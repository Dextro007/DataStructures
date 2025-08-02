#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node *root, int data)
{
    if (root == nullptr) {
        root = new Node(data);
        return root;
    }

    if (data < root->value) {
        
    }

}
