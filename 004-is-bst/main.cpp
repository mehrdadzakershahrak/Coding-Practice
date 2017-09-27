/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
bool checkBST(Node* root, int min, int max) {
    if (root == nullptr){
        return true;
    }
    bool Left = checkBST(root->left,min,root->data);
    bool Right = checkBST(root->right,root->data, max);
    if (!Right || !Left) {
        return false;
    }
    if (root->left != nullptr) {
        if (root->left->data >= root->data) {
            return false;
        }
    }
    if (root->data <= min || root->data >= max) {
        return false;
    }
    if (root->right != nullptr) {
        if (root->right->data <= root->data) {
            return false;
        }
    }
    return true;
}

bool checkBST(Node* root) {
    return checkBST(root, -100000,+100000);
}

