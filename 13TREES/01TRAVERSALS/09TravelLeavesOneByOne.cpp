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
 366. Find Leaves of Binary Tree
 */
class Solution {
public:
    int preOrderTraversal(TreeNode* root, std::unordered_map<int, std::vector<int>>& mapDepthNodes) {
        if (root == nullptr)
            return -1;
        int depthLeft = preOrderTraversal(root->left, mapDepthNodes);
        int depthRight = preOrderTraversal(root->right, mapDepthNodes);
        
        int depthRoot = 1 + std::max(depthLeft, depthRight);
        if (!mapDepthNodes.count(depthRoot))
            mapDepthNodes.insert({depthRoot, std::vector<int>{} });
        mapDepthNodes[depthRoot].push_back(root->val);
        
        return depthRoot;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        //depth traversal
        std::vector<std::vector<int>> output;
        std::unordered_map<int, std::vector<int>> mapDepthNodes;
        int rootDepth = preOrderTraversal(root, mapDepthNodes);
        for (int i = 0; i <= rootDepth; i++) {
            output.push_back(mapDepthNodes[i]);
        }
        return output;
    }
};