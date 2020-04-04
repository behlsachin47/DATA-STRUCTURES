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
    void maxPathSum(TreeNode* root, int& ans, int& sumContRoot) {
        if (root == nullptr)
            return;
        
        int sumContRootLeft = 0;
        int sumContRootRight = 0;
        maxPathSum(root->left, ans, sumContRootLeft);
        maxPathSum(root->right, ans, sumContRootRight);
        
        sumContRoot = root->val + std::max(std::max(0,sumContRootLeft), sumContRootRight);
        ans = std::max(ans, std::max(sumContRoot, root->val+ sumContRootLeft + sumContRootRight));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int sumContRoot = 0;
        maxPathSum(root, ans, sumContRoot);
        return ans;
    }
};