/*
Soln:
      1. Traverse the tree
      2. See if the node left and right both are nullptr
      3. if yes then add it to the total summ
*/

int sumOfLeafNodes(Node *r ){
     int summ = 0;
     if(r == nullptr){
         return 0;
     }
     else if( r->left == nullptr && r->right == nullptr){
         return r->data;
     }
     summ += sumOfLeafNodes(r->left);
     summ += sumOfLeafNodes(r->right);
     return summ;
}
