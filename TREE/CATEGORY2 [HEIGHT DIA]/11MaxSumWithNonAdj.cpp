//This function returns the maximum sum of non-adjacent nodes.
int getMaxSum(Node* root, int& excludeSum) {
    if (root == nullptr)
        return 0;

    int excSumL = 0;
    int excSumR = 0;
    
    int ans1 = getMaxSum(root->left, excSumL);
    int ans2 = getMaxSum(root->right, excSumR);
    
    excludeSum = ans1+ ans2;
    int ans = 0;
    ans = std::max(ans, root->data + excSumL + excSumR);
    ans = std::max(ans, excludeSum);
    return ans;
    
}
//This function returns the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root) 
{
    int excSum = 0;
    return getMaxSum(root, excSum);
    // Add your code here
}