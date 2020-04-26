/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //morris
        vector<int> res;
        while(root) {
            if (root->left) {
                //find Predecsoor
                TreeNode* pre = root->left;
                while (pre->right != nullptr && pre->right != root) {
                    pre = pre->right;
                }
                
                if (pre->right == root) {
                    pre->right = nullptr;
                    res.push_back(root->val);
                    root = root->right;
                } else {
                    pre->right = root;
                    root = root->left;
                }
            } else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
        
    }
};