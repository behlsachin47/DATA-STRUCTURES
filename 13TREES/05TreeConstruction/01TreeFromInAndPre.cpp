/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* buildTreeUtil(std::vector<int>& A, int PreOrderLow, int PreOrderHigh, 
std::vector<int>& B, int InOrderLow, int InOrderHigh, std::unordered_map<int, int>& mapValueToIndex) {
    if (PreOrderHigh < PreOrderLow)
        return nullptr;
    
    int rootVal = A[PreOrderLow];
    int rootIndexInOrder = mapValueToIndex[rootVal];
    TreeNode* rootNode = new TreeNode(rootVal);
    
    int leftSTLen = rootIndexInOrder - InOrderLow;
    int rightSTLen = InOrderHigh - rootIndexInOrder;
    
    rootNode->left = buildTreeUtil(A, PreOrderLow + 1, PreOrderLow + leftSTLen, B, InOrderLow, rootIndexInOrder -1, mapValueToIndex);
    rootNode->right = buildTreeUtil(A, PreOrderLow + leftSTLen + 1, PreOrderHigh, B, rootIndexInOrder + 1, InOrderHigh, mapValueToIndex);
    return rootNode;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if (n == 0)
        return nullptr;
    //lets make a hash out of inorder traversal so that we can find the rootIndex in O(1) time
    std::unordered_map<int, int> mapValueToIndex;
    for (int i = 0; i < B.size(); i++) {
        mapValueToIndex.insert({B[i], i});
    }
    
    return buildTreeUtil(A, 0, n-1, B, 0, n-1, mapValueToIndex);
}
