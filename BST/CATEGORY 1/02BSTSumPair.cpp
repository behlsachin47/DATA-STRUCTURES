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
    bool findTarget(TreeNode* root, int k) {
        //lets do non recursive inorder traversal
        if (root == nullptr)
            return false;
        
        TreeNode* iter = root;
        std::stack<TreeNode*> st;
        std::vector<int> list;
        while (iter || st.empty() == false) {
            while (iter) {
                st.push(iter);
                iter = iter->left;
            }
            
            if (!st.empty()) {
                TreeNode* curr = st.top();
                st.pop();
                list.push_back(curr->val);
                
                if (curr->right)
                    iter = curr->right;
            }
            
        }
        
        int i = 0;
        int j = list.size()-1;
        
        while (i < j) {
            if (list[i] + list[j] == k)
                return 1;
            else if (list[i] + list[j] > k)
                j--;
            else
                i++;
        }
        
        return 0;
    }
};