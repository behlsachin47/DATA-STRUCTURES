/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef std::pair<TreeNode*, TreeNode*> nodePair;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return 1;
        else if (root->left == nullptr && root->right == nullptr)
            return 1;
        else if (root->left == nullptr || root->right == nullptr)
            return 0;
        else {
            std::queue<nodePair> q;
            q.push(std::make_pair(root->left, root->right));
                   
            while (!q.empty()) {
                auto currPairs = q.front();
                q.pop();
                if (currPairs.first->val != currPairs.second->val)
                    return false;
                else {
                    //equal values
                    if(currPairs.first->right != nullptr && currPairs.second->left != nullptr) {
                        q.push(std::make_pair(currPairs.first->right,currPairs.second->left));
                    } else if (!(currPairs.first->right == nullptr && currPairs.second->left == nullptr)) {
                        return 0;
                    }
                    
                    
                    if(currPairs.first->left != nullptr && currPairs.second->right != nullptr) {
                        q.push(std::make_pair(currPairs.first->left,currPairs.second->right));
                    } else if (!(currPairs.first->left == nullptr && currPairs.second->right == nullptr)) {
                        return 0;
                    }
                    
                }
            }
            return 1;
        }
    }
};