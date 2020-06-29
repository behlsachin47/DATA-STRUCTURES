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
   
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            TreeNode* temp = currNode->left;
            currNode->left = currNode->right;
            currNode->right = temp;
            
            if (currNode->left)
                q.push(currNode->left);
            
            if (currNode->right)
                q.push(currNode->right);
        }
        return root;
        
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
    void invertTreeUtil(TreeNode* root) {
        if (root == nullptr)
            return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTreeUtil(root->left);
        invertTreeUtil(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTreeUtil(root);
        return root;
        
    }
};