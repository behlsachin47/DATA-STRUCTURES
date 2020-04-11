/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef struct TreeNode Node;
int findLargest(Node* root) {
    if (root == nullptr)
        return -1;
    if (root->right)
        return findLargest(root->right);
    else
        return root->val;
}

int findSmallest(Node* root) {
    if (root == nullptr)
        return -1;
    
    if (root->left) 
        return findSmallest(root->left);
    else
        return root->val;
    
}



class Solution {
public:
    
Node *deleteNode(Node *root,  int x)
{
    // your code goes here
    if (root == nullptr)
        return nullptr;
    else if (root->val == x) {
        if (!root->right && !root->left) {
            delete root;
            return nullptr;
        } else if (root->left) {
            int leftLargest = findLargest(root->left);
            root->left = deleteNode(root->left, leftLargest);
            root->val = leftLargest;
            return root;
        } else if (root->right) {
            int rightSmallest = findSmallest(root->right);
            root->right = deleteNode(root->right, rightSmallest);
            root->val = rightSmallest;
            return root;
        }
    } else if (root->val > x) {
        root->left = deleteNode(root->left, x);
        return root;
    } else {
        root->right = deleteNode(root->right, x);
        return root;
    }
    return nullptr;
}

};
