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
    
    int diameterOfBinaryTreeUtil(TreeNode* root, int& ht) {
        if (root == nullptr)
            return 0;
        int htLeft = 0;
        int htRight = 0;
        int diaLeft = diameterOfBinaryTreeUtil(root->left, htLeft);
        int diaRight = diameterOfBinaryTreeUtil(root->right, htRight);
        
        ht = std::max(htLeft, htRight) + 1;
        int dia = htLeft + htRight;
        return std::max(dia, std::max(diaLeft, diaRight));
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ht = 0;
        return diameterOfBinaryTreeUtil(root, ht);
    }
};

