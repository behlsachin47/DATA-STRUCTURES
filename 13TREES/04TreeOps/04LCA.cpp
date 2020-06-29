/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool search(TreeNode* root, int val) {
    if (root == nullptr)
        return 0;
    else 
        return ((root->val == val) || search(root->left, val) || search(root->right, val)); 
}

int lcaUtil(TreeNode* root, int valA, int valB) {
    if (root == nullptr)
        return -1;
    else if (root->val == valA || root->val == valB)
        return root->val;
    else {
        int lcaLeft = lcaUtil(root->left, valA, valB);
        int lcaRight = lcaUtil(root->right, valA, valB);
        if (lcaLeft != -1 && lcaRight != -1)
            return root->val;
        else if (lcaLeft == -1 && lcaRight == -1)
            return -1;
        else if (lcaLeft == -1)
            return lcaRight;
        else 
            return lcaLeft;
    }
}
int Solution::lca(TreeNode* A, int B, int C) {
    //check if A and B exist in the tree
    if(!search(A, B) || !search(A, C))
        return -1;
    
    return lcaUtil(A, B, C);
}

