/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr)
            return 0;
        
        int ans = 0;
        if (root->val >= L && root->val <= R) {
            
            ans += root->val;
            ans += rangeSumBST(root->left, L, R);
            ans += rangeSumBST(root->right, L, R);
            
        } else if (root->val < L) {
            
            ans += rangeSumBST(root->right, L, R);
            
        } else if (root->val > R) {
            
            ans += rangeSumBST(root->left, L, R);
        }
        
        return ans;
    }
};