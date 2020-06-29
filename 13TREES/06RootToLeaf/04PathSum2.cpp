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
    
    void pathSum(TreeNode* root, int currSum, int targetSum, std::vector<int>& path, std::vector<std::vector<int>>& output) {
        if (root == nullptr)
            return;
        currSum += root->val;
        path.push_back(root->val);
        
        if (root->left == nullptr && root->right == nullptr) {
            if (currSum == targetSum) {
                output.push_back(path);
            }
        } else {
            pathSum(root->left, currSum, targetSum, path, output);
            pathSum(root->right, currSum, targetSum, path, output);
            

        }
                    path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::stack<std::pair<TreeNode*, int>> stack1;
        std::vector<int> path;
        int currSum = 0;
        std::vector<std::vector<int>> output;
        if (root == nullptr)
            return output;
        
        pathSum(root, currSum, sum, path, output);
        return output;
    }
};