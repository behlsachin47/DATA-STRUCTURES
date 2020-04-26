int countSubtreesWithSumXUtil(Node* root, int x, int& ans) {
    if (root == nullptr)
        return 0;
    
    int currSum = countSubtreesWithSumXUtil(root->left, x, ans) + 
                  countSubtreesWithSumXUtil(root->right, x,ans) + root->data;
    if (currSum == x)
        ans++;
    return currSum;
        
}
int countSubtreesWithSumX(Node* root, int x)
{
    if (root == nullptr)
        return 0;
    int ans = 0;
    countSubtreesWithSumXUtil(root, x, ans);
	// Code here
	return ans;
}
