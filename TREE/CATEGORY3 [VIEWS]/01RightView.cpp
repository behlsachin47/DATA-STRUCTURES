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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        TreeNode* lastNode = nullptr;
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr) {
                if (!q.empty()) {
                    q.push(nullptr);
                }
                result.push_back(lastNode->val);
                continue;
            }
            
            if (curr->left) 
                q.push(curr->left);
            
            if (curr->right)
                q.push(curr->right);
            
            lastNode = curr;
        }
        return result;
    }
};


///////////////////////////////////////////////////////////////
/////////////without queueu; recursive approach

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void rightSideViewU(TreeNode* root, int level, vector<int>& res) {
    if (root == nullptr)
        return;
    
    if (res.size() == level)
        res.push_back(root->val);
    rightSideViewU(root->right, level+1, res);
    rightSideViewU(root->left, level+1, res);
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightSideViewU(root, 0, res);
        return res;
    }
};