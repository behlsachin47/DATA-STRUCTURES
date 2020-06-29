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

//we can also simply compare the nodes at lower level by check ing the npde at present level.
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
    int sumEvenGrandparent(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ans = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr->left) {
                q.push(curr->left);
                if (curr->val % 2 == 0) {
                    if (curr->left->left)
                        ans += curr->left->left->val;
                    if (curr->left->right)
                        ans += curr->left->right->val;
                }
            }
            
            if (curr->right) {
                q.push(curr->right);
                if (curr->val % 2 == 0) {
                    if (curr->right->left)
                        ans += curr->right->left->val;
                    if (curr->right->right)
                        ans += curr->right->right->val;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    
    int sumEvenGrandparent(TreeNode* root) {
        //do a bfs and keeep track of parent
        if (root == nullptr)
            return 0;
        int ans = 0;
        std::unordered_map<TreeNode*, TreeNode*> mapChildToParent;
        std::queue<TreeNode*> q;
        mapChildToParent.insert({root, nullptr});
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            
            TreeNode* parent = mapChildToParent[currNode];
            if (parent) {
                TreeNode* grandParent = mapChildToParent[parent];
                if (grandParent) {
                    if (grandParent->val % 2 == 0)
                        ans += currNode->val;
                }
            }
            
            if (currNode->left) {
                mapChildToParent.insert({currNode->left, currNode});
                q.push(currNode->left);
            }
            
            if (currNode->right) {
                mapChildToParent.insert({currNode->right, currNode});
                q.push(currNode->right);
            }
        }
        
        
        
       return ans;
    }
};