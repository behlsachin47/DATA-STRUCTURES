//ITERATIVE

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return 1;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();
            
            
            if (node1 == nullptr && node2 == nullptr)
                continue;
            else if (node1 == nullptr || node2 == nullptr)
                return 0;
            
            if (node1->val != node2->val)
                return 0;
            else {
                q.push(node1->left);
                q.push(node2->right);
                q.push(node2->left);
                q.push(node1->right);
            }
            
            
            
            
        }
        
        return 1;
    }
};










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
    
    bool isSymmetricUtil(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return 1;
        else if (!root1 || !root2)
            return 0;
        
        if (root1->val != root2->val)
            return 0;
        
        return isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return 1;
        return isSymmetricUtil(root->left, root->right);
    }
};