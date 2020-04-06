/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildTreeU(vector<int>& preOrder, int st1, int end1, 
                    vector<int>& inOrder, int st2, int end2,
                    std::unordered_map<int, int>& mapInOrder) {
    if (st1 > end1)
        return nullptr;
    TreeNode* root = new TreeNode(preOrder[st1]);
    int rootIndexIn = mapInOrder[root->val];
    int leftSTInSize = rootIndexIn-st2;

    root->left = buildTreeU(preOrder, st1+1, st1+leftSTInSize,
                           inOrder, st2, rootIndexIn-1, mapInOrder);
    
    root->right = buildTreeU(preOrder, st1+leftSTInSize+1, end1,
                            inOrder, rootIndexIn+1, end2, mapInOrder);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    std::unordered_map<int, int> mapInOrder;
    for (int i = 0; i < B.size(); i++)
        mapInOrder.insert({B[i], i});
    
    return buildTreeU(A, 0, A.size()-1, B, 0, B.size()-1, mapInOrder);
}
