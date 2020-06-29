/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* buildTreeUtil(std::vector<int>& vec, int st, int end) {
    if (st > end)
        return nullptr;
    
    //find the max element
    int maxIndex = st;
    for (int i = st; i <= end; i++)
        if (vec[i] > vec[maxIndex])
            maxIndex = i;
    
    TreeNode* root = new TreeNode(vec[maxIndex]);
    root->left = buildTreeUtil(vec, st, maxIndex-1);
    root->right = buildTreeUtil(vec, maxIndex+1, end);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    return buildTreeUtil(A, 0, A.size()-1);
    
}
