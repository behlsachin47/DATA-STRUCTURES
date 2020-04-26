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
    bool isValidBST(TreeNode* root, int& maxElem, int& minElem) {
        if (root == nullptr)
            return 1;
        bool ans = 1;
        maxElem = root->val;
        minElem = root->val;
        
        if (root->left) {
            int minElem1;
            int maxElem1;
            ans = isValidBST(root->left, maxElem1, minElem1);
            if (!ans || root->val <= maxElem1)
                return false;
            else
                minElem = minElem1;
        }
        
        if (root->right) {
            int minElem2;
            int maxElem2;
            ans = isValidBST(root->right, maxElem2, minElem2);
            
            if (!ans || root->val >= minElem2)
                return false;
            else
                maxElem = maxElem2;
        }
        
        return true;
    }
    bool isValidBST(TreeNode* root) {
       bool ans = true;
        int maxElem = INT_MIN;
        int minElem = INT_MAX;
        
       return isValidBST(root, maxElem, minElem);
    }
};




//INORDER NON REC

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
    bool isValidBST(TreeNode* root) {
        std::stack<TreeNode*> st1;
        TreeNode* pIter = nullptr;
        TreeNode* iter = root;
        
        while (iter || st1.empty() == false) {
            while (iter) {
                st1.push(iter);
                iter = iter->left;
            }
            
            //iter is nullptr
                //get the new iter
                iter = st1.top();
                st1.pop();
                if (pIter != nullptr) {
                    if (iter->val <= pIter->val)
                        return false;
                    
                }
                pIter = iter;
                iter = iter->right;
        }
        return 1;
    }
};