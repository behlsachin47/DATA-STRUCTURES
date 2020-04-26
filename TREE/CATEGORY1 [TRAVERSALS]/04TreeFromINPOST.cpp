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
    TreeNode* buildTree(int st, int end, vector<int>& inorder, int st2, int end2, vector<int>& postorder, std::unordered_map<int, int>& mapValueIndex) {
        if (st > end) 
            return nullptr;
        //find the root in inorder Traversal
        int rootVal = postorder[end2];
        int rootIndexIn = mapValueIndex[rootVal];
        int leftSubTreeSize = rootIndexIn - st;
        int rightSubTreeSize = end - rootIndexIn;
        
        TreeNode* newNode = new TreeNode(rootVal);
        newNode->left = buildTree(st, rootIndexIn-1, inorder,
                                  st2, st2+ leftSubTreeSize -1, postorder, mapValueIndex);
        newNode->right = buildTree(rootIndexIn+1, end, inorder,
                                   st2+ leftSubTreeSize, end2-1, postorder, mapValueIndex);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0)
            return nullptr;
        std::unordered_map<int, int> mapValueIndex;

        for (int i = 0; i < inorder.size(); i++) {
            mapValueIndex.insert({inorder[i], i});
        }
        return buildTree(0, inorder.size()-1, inorder, 0, postorder.size()-1, postorder, mapValueIndex);
    }
};