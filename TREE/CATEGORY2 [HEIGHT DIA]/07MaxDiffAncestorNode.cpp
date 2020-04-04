/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cmath>
class Solution {
public:
    void maxAncestorDiff(TreeNode* root, int& maxChildVal, int& minChildVal, int& ans) {
        if(root == nullptr)
            return;
        int maxChildValLeft = INT_MIN;
        int minChildValRight = INT_MAX;
        int maxChildValRight = INT_MIN;
        int minChildValLeft = INT_MAX;
        
        maxAncestorDiff(root->left, maxChildValLeft, minChildValLeft, ans);
        maxAncestorDiff(root->right, maxChildValRight, minChildValRight, ans);
        
        minChildVal = std::min(minChildValRight, minChildValLeft);
        maxChildVal = std::max(maxChildValRight, maxChildValLeft);
        
        if (minChildVal != INT_MAX)
            ans = std::max(ans, abs(root->val-minChildVal));
        if (maxChildVal != INT_MIN)
            ans = std::max(ans, abs(root->val-maxChildVal));
        
        minChildVal = std::min(minChildVal, root->val);
        maxChildVal = std::max(maxChildVal, root->val);
        
        /*std::cout << "ROOT: " << root->val << std::endl;
        std::cout << minChildVal << " " << maxChildVal << std::endl << std::endl; */
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }
        int maxChildVal = INT_MIN;
        int minChildVal = INT_MAX;
        int ans = INT_MIN;
        maxAncestorDiff(root, maxChildVal, minChildVal, ans);
        return ans;
    }
};