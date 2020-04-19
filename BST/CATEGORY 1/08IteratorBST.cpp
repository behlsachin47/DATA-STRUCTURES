/*tion for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
std::stack<TreeNode*> cont;
BSTIterator::BSTIterator(TreeNode *root) {
    while (root) {
        cont.push(root);
        root = root->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if (cont.size())
        return 1;
    return 0;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int ans = -1;
    if (BSTIterator::hasNext()) {
        TreeNode* curr = cont.top();
        cont.pop();
        ans = curr->val;
        curr = curr->right;
        
        while (curr) {
            cont.push(curr);
            curr = curr->left;
        }
    }
    return ans;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

