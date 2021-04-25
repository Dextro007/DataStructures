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
// topview recursive
void topViewRecurssive(Node* root, map<int, pair<int, int>> &m, int dist, int level){
    if(root == nullptr){
        return;
    }
    if(m.count(dist) == 0 ||(m[dist].second > level)){
        m[dist] = make_pair(root->data, level);
    }
    topViewRecurssive(root->left,m, dist - 1, level + 1);
    topViewRecurssive(root->right,m, dist + 1, level + 1);
}

void topView(Node * root) {
    map<int, pair<int, int>> m;
    topViewRecurssive(root, m, 0, 0);
    for(auto i : m){
        cout << i.second.first <<" ";
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
