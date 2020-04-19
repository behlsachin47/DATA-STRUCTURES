/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* createTree(vector<int>& A, int st, int end) {
    if (st > end)
        return nullptr;
    
    //find max
    int ind = st;
    for (int i = st; i <= end; i++)
        if (A[i] > A[ind])
            ind = i;
        
    TreeNode* root = new TreeNode(A[ind]);
    root->left = createTree(A, st, ind-1);
    root->right = createTree(A, ind+1, end);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    return createTree(A, 0, A.size()-1);
}

