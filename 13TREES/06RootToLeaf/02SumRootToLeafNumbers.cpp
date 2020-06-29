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
    
    void sumNumbersUtil(TreeNode* root, int currNumber, int& ans) {
        if (root == nullptr)
            return;
        currNumber = currNumber*10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            ans += currNumber;
        } else {
            if (root->left)
            sumNumbersUtil(root->left, currNumber, ans);
            if (root->right)
            sumNumbersUtil(root->right, currNumber, ans);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int currNumber = 0;
        sumNumbersUtil(root, currNumber, ans);
        return ans;
    }
};