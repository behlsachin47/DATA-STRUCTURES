#include <iostream>
bool checkIfMirror(Node* root1, Node* root2) {
    if (!root1 && !root2) 
        return true;
    else if (root1 == nullptr || root2 == nullptr)
        return false;
    
    if (root1->data != root2->data)
        return false;
    
    bool res1 = checkIfMirror(root1->left, root2->right);
    bool res2 = checkIfMirror(root1->right, root2->left);

    return res1 && res2;
}