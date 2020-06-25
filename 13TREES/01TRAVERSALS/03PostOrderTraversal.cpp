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



//we can also do a preorder traversal and reverse the output

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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> output;
        if (root == nullptr)
            return output;
        std::stack<TreeNode*> stack1;
        stack1.push(root);
        
        while (!stack1.empty()) {
            TreeNode* currNode = stack1.top();
            stack1.pop();
            
            output.push_back(currNode->val);
            
            if (currNode->left)
                stack1.push(currNode->left);
            
            if (currNode->right)
                stack1.push(currNode->right);
        }
        std::reverse(output.begin(), output.end());
        return output;
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stack1;
        std::vector<int> output;
        
        while (root || stack1.size()) {
            if (root) {
                stack1.push(root);
                stack1.push(root);
                root = root->left;
            } else {
                TreeNode* temp = stack1.top();
                stack1.pop();
                if (stack1.empty() || stack1.top() != temp) {
                    //already explored right half 
                    output.push_back(temp->val);
                } else {
                    //go right
                    root = temp->right;
                }
                    
            }
        }
        
        return output;
    }
};