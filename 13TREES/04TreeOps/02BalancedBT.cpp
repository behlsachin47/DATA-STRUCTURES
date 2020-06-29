/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) ;
};

int isBalancedUtil(TreeNode* A, int& ht) {
    if (A  == nullptr)
        return 1;
    
    int htLeft = 0;
    int htRight = 0;
    if (isBalancedUtil(A->left, htLeft) && isBalancedUtil(A->right, htRight) && (abs(htLeft - htRight) <= 1))
    {
        ht = std::max(htLeft, htRight) + 1;
        return 1;
    }
    
    return 0;
    
    
}
bool Solution::isBalanced(TreeNode* A) {
    //make a call to left St and right st
    if (A == nullptr)
        return 1;
    
    int ht = 0;
    return isBalancedUtil(A, ht);
        
    
}