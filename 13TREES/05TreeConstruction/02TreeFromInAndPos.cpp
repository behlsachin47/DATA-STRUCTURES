/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* buildTreeUtil(std::vector<int>& A, int lowA, int highA, std::vector<int>& B,
int lowB, int highB, std::unordered_map<int, int>& mapValueToIndex) {
    if (lowA > highA) {
        return nullptr;
    }
    
    //search for root node in the vector A
    int rootVal = B[highB];
    int rootIndexInorder = mapValueToIndex[rootVal];
    int leftSTlen = rootIndexInorder - lowA;
    int rightSTlen = highA - rootIndexInorder;
    
    TreeNode* newNode = new TreeNode(rootVal);
    newNode->left = buildTreeUtil(A, lowA, rootIndexInorder-1, B, lowB, lowB + leftSTlen -1, mapValueToIndex);
    newNode->right = buildTreeUtil(A, rootIndexInorder+1, highA,  B,lowB + leftSTlen, highB - 1, mapValueToIndex);
    return newNode;
    
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    //A (inorder) : left root right
    //B (postorder) : left right root
    //make a hashmap of inorder traversal so that we can find the root index in O(1)
    
    std::unordered_map<int, int> mapValueToIndex;
    for (int i = 0; i < A.size(); i++) {
        mapValueToIndex.insert({A[i], i});
    }
    return buildTreeUtil(A, 0, A.size()-1, B, 0, B.size()-1, mapValueToIndex);
}
