#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

void topView(Node * root) {
    if(root == nullptr){
        return;
    }
    map<int, int> m;
    queue<pair<Node*, int>> q;
    Node* curr = nullptr;
    int dist = 0;
    q.push({root, 0});
    /* since we already traversing the tree level wise
    not need to take care of level. But in recursive that is alos handled*/
    while(!q.empty()){
        curr = q.front().first;
        dist = q.front().second;
        q.pop();
        /* count returns 1 if container contains
        an element whose key value is dist else 0
        */
        if(m.count(dist) == 0){
            m[dist] = curr->data;
        }
        if(curr->left != nullptr){
            q.push({curr->left, dist - 1});
        }
        if(curr->right != nullptr){
            q.push({curr->right, dist + 1});
        }
    }
    for(auto i:m){
        cout<<i.second<<" ";
    }
}

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

	myTree.topView(root);
    return 0;
}
