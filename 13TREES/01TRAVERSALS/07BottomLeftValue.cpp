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
    void findBottomLeftValueUtil(TreeNode* root, int& ansVLevel, int currVLevel, int& ans) {
        if (root == nullptr)
            return;
        
        if (ansVLevel < currVLevel ) {
            ansVLevel = currVLevel;
            
            ans = root->val;
        } 
        
        findBottomLeftValueUtil(root->left, ansVLevel, currVLevel + 1, ans);
        
        findBottomLeftValueUtil(root->right, ansVLevel,  currVLevel + 1,  ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        //lets try dfs
        if (root == nullptr)
            return -1;
        int ansVLevel = 0;
        
        int ans = root->val;
        findBottomLeftValueUtil(root->left, ansVLevel, 1,  ans);
        findBottomLeftValueUtil(root->right, ansVLevel,  1, ans);
        
        return ans;
    }
};