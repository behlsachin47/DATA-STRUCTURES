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
    
    void generateLeftBoundary(TreeNode* root, std::vector<int>& leftBoundary) {
        if (root == nullptr) {
            return;
        } else if (root->left == nullptr && root->right == nullptr)
            return;
        
        leftBoundary.push_back(root->val);
        if (root->left)
            generateLeftBoundary(root->left, leftBoundary);
        else
            generateLeftBoundary(root->right, leftBoundary);
    }
    
    void generateRightBoundary(TreeNode* root, std::vector<int>& rightBoundary) {
        if (root == nullptr)
            return;
        else if (root->left == nullptr && root->right == nullptr)
            return;
        
        
        if (root->right)
            generateRightBoundary(root->right, rightBoundary);
        else
            generateRightBoundary(root->left, rightBoundary);
        
        rightBoundary.push_back(root->val);
    }
    
    
    void generateAllInOrderLeaves(TreeNode* root, std::vector<int>& leaves) {
        if (root == nullptr)
            return;
        else if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
            return;
        } else {
            generateAllInOrderLeaves(root->left, leaves);
            generateAllInOrderLeaves(root->right, leaves);
        }
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return std::vector<int> {};
        else if (root->left == nullptr && root->right == nullptr)
            return std::vector<int> {root->val};
        std::vector<int> output;
        output.push_back(root->val);
        
        generateLeftBoundary(root->left, output);
        
        generateAllInOrderLeaves(root, output);
        //std::vector<int> rightT
        generateRightBoundary(root->right, output);
        
        
        
        return output;
    }
};