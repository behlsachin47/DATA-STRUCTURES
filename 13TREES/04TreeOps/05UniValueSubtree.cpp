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
    bool isUnivalSubTree(TreeNode* root, int& ans) {
        if (root == nullptr)
            return 0;
        
        
        bool resLeft = isUnivalSubTree(root->left, ans);
        bool resRight = isUnivalSubTree(root->right, ans);
        
        if (root->left) {
            if (root->val != root->left->val || !resLeft)
                return 0;
        }
        
        if (root->right) {
            if (root->val != root->right->val || !resRight)
                return 0;
        }
        ans++;
        return 1;
    }
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        isUnivalSubTree(root, ans);
        return ans;
    }
};