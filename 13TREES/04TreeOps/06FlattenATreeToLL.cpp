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
    
    TreeNode* flattenUtil(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* tailLeft = flattenUtil(root->left);
        TreeNode* tailRight = flattenUtil(root->right);
        TreeNode* tempRight = root->right;
        TreeNode* tail = root;
        
        if (tailLeft) {
            tail->right = root->left;
            tail->left = nullptr;
            tail = tailLeft;
        }
        
        if(tailRight) {
            tail->right = tempRight;
            tail = tailRight;
        }
           return tail;
        
    }
    
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return ;
        
        flattenUtil(root);
        
        
        
        
    }
};