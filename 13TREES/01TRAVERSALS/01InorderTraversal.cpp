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
    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stack1;
        
        std::vector<int> output;
        while (root || stack1.size()) {
            if (root) {
                stack1.push(root);
                root = root->left;
            } else {
                TreeNode* temp = stack1.top();
                stack1.pop();
                
                output.push_back(temp->val);
                root = temp->right;
            }
        }
        
        return output;
        
    }
};