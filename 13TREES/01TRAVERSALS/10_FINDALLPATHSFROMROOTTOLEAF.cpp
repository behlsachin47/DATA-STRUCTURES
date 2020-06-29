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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> output;
        if (root == nullptr)
            return output;
        
        std::stack<TreeNode*> recStack;
        std::stack<std::string> pathStack;
        recStack.push(root);
        pathStack.push(std::to_string(root->val));
        
        while (!recStack.empty()) {
            TreeNode* currNode = recStack.top();
            recStack.pop();
            std::string path = pathStack.top();
            pathStack.pop();
            
            
            if (currNode->left == nullptr && currNode->right == nullptr) {
                //add this path to the output;
                output.push_back(path);
                
                    
            } else {
                
                if (currNode->right) {
                    recStack.push(currNode->right);
                    std::string rightPath = path + "->" + std::to_string(currNode->right->val);
                    pathStack.push(rightPath);
                }
                
                
                if (currNode->left) {
                    recStack.push(currNode->left);
                    std::string leftPath = path + "->" + std::to_string(currNode->left->val);
                    pathStack.push(leftPath);
                }
                
            }
            
        }
        
        return output;
        
    }
};