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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        
        std::stack<std::pair<TreeNode*, int> > st1;
        st1.push(std::make_pair(root, 0));
        
        while (!st1.empty()) {
            auto iter = st1.top();
            st1.pop();
            TreeNode* currNode = iter.first;
            int currSum = iter.second + currNode->val;
            
            if (currNode->left == nullptr && currNode->right == nullptr) {
                //leaf node
                if (currSum == sum)
                    return 1;
            } else {
                if (currNode->left)
                    st1.push(std::make_pair(currNode->left, currSum));
                
                if (currNode->right)
                    st1.push(std::make_pair(currNode->right, currSum));
            }
        }
        return 0;
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
    
    bool hasPathSum(TreeNode* root, int currSum, int& targetSum) {
        if (root == nullptr) {
            return 0;
        }
        currSum += root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            if (currSum == targetSum) 
                return 1;
        } else {
            return hasPathSum(root->left, currSum, targetSum) || hasPathSum(root->right, currSum, targetSum);
        }
        return 0;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        int currSum = 0;
        return hasPathSum(root, currSum, sum);
    }
};