/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //RIGHT SIDE VIEW
        std::vector<int> output;
        if(root == nullptr)
            return output;
        
        int currLevel = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if (currNode == nullptr) {
                if (q.empty())
                    continue;
                
                q.push(nullptr);
            } else {
                //output[currLevel] = currNode->val;
                if(q.front() == nullptr)
                    output.push_back(currNode->val);
                
                if (currNode->left)
                    q.push(currNode->left);
                if (currNode->right)
                    q.push(currNode->right);
            }
        }
        
        return output;
    }
};