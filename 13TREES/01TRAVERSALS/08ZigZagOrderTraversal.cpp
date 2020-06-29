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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<vector<int>> output;
        if (root == nullptr)
            return output;
        std::stack<TreeNode*> stack1;
        std::stack<TreeNode*> stack2;
        stack1.push(root);
        int currLevel = 0;
        while (!stack1.empty() || !stack2.empty()) {
            if (!stack1.empty()) {
                output.push_back(std::vector<int> {});
                //push everything to stack2
                while (!stack1.empty()) {
                    //from right to left
                    TreeNode* currNode = stack1.top();
                    stack1.pop();
                    
                    output[currLevel].push_back(currNode->val);
                    
                    if (currNode->left)
                        stack2.push(currNode->left);
                    
                    if (currNode->right)
                        stack2.push(currNode->right);
                }
            } else {
                output.push_back(std::vector<int> {});
                while (!stack2.empty()) {
                    //from right to left
                    TreeNode* currNode = stack2.top();
                    stack2.pop();
                    
                    output[currLevel].push_back(currNode->val);
                    
                    if (currNode->right)
                        stack1.push(currNode->right);
                    
                    if (currNode->left)
                        stack1.push(currNode->left);
                    
                    
                }
                
            }
            currLevel ++;
        }
        
        return output;
        
    }
};