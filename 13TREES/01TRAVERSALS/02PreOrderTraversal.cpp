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






//stack is used to store the right part of nodes
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stack1;
        std::vector<int> output;
        while (root || stack1.size()) {
            if (root) {
                if (root->right)
                stack1.push(root->right);
                output.push_back(root->val);
                root = root->left;
            } else {
                root = stack1.top();
                stack1.pop();
                
            }
        }
        
        return output;
    }
};