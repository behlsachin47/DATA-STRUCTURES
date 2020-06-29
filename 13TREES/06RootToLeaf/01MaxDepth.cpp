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
    
    int maxDepth(TreeNode* root, int currDepth) {
        if (root == nullptr)
            return currDepth;
        if (root->left == nullptr && root->right == nullptr)
            return currDepth;
        else {
            return std::max(maxDepth(root->left, currDepth+1), maxDepth(root->right, currDepth+1));
        }
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        //preoorder traversal stack
        std::stack<std::pair<TreeNode*, int>> st1;
        st1.push(std::make_pair(root, 1));
        int ans = 0;
        
        while (!st1.empty()) {
            auto currNodeDepth = st1.top();
            st1.pop();
            TreeNode* currNode = currNodeDepth.first;
            int depth = currNodeDepth.second;
            
            if (!currNode->left && !currNode->right) {
                ans = std::max(ans, depth);
                continue;
            }
            
            if (currNode->left) 
                st1.push(std::make_pair(currNode->left, depth+1));
            
            if (currNode->right)
                st1.push(std::make_pair(currNode->right, depth+1));
                
        }
        
        return ans;
    }
};