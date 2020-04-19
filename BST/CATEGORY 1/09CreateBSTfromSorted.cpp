/*tion for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* createBST(const vector<int>& input, int st, int end) {
    if (st > end)
        return nullptr;
    int mid = (st+end)/2;
    TreeNode* root = new TreeNode(input[mid]);
    root->left = createBST(input, st, mid-1);
    root->right = createBST(input, mid+1, end);
    
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return createBST(A, 0, A.size()-1);
}

