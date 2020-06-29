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
    vector<int> largestValues(TreeNode* root) {
        std::vector<int> output;
        if (root == nullptr)
            return output;
        
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        output.push_back(INT_MIN);
        int currLevel = 0;
        
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            
            if (currNode == nullptr) {
                if (q.empty())
                    continue;
                
                q.push(nullptr);
                output.push_back(INT_MIN);
                currLevel++;
            } else {
                if (output[currLevel] < currNode->val)
                    output[currLevel] = currNode->val;
                
                if (currNode->left)
                    q.push(currNode->left);
                
                if (currNode->right)
                    q.push(currNode->right);
            }
        }
        
        return output;
    }
};