/*
Prlbm : given a binary tree tell whether the tree is
        BST or not
Soln  : Do an inorder traversal store the data and check
        if the previous stored data is less than current

*/
// can make it simple by using arrays or linked list instead of prev

bool isBST(Node* root, Node* &prev){
    if(root){
        /*first look in the left of the tree*/
        if(isBST(root->left, prev) == false){
            return false;
        }
//         compare the data stored in the prev after left traversal
        if(prev!= nullptr && root->data <= prev->data){
            return false;
        }
        // this is the confusing part
        prev = root;
        return isBST(root->right, prev);
    }
    return true;
}

bool checkBST(Node* root) {
    Node *prev = nullptr;
    return isBST(root, prev);
}
