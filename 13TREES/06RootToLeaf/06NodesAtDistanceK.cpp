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
    bool debug = 0;
    void fillParentMap(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*>& mapParent) {
        if (root == nullptr)
            return;
        if (root->left) {
            mapParent.insert({root->left, root});
            fillParentMap(root->left, mapParent);
        }
        
        if (root->right) {
            mapParent.insert({root->right, root});
            fillParentMap(root->right, mapParent);
        }
    }
    
   
    
    
    void searchNode(TreeNode* target, int K, std::vector<int>& output, std::unordered_map<TreeNode*, TreeNode*>& mapParent, std::set<TreeNode*>& visited) {
        if (target == nullptr) 
            return;
        else if (visited.count(target))
            return;
                
        
        if (debug) {
            std::cout << "search:\n" << target->val << " " << K << std::endl; 
        }
        
        visited.insert(target);
        if (K == 0) {
            output.push_back(target->val);
            return;
        }
        
        TreeNode* parentTarget = mapParent[target];
        searchNode(parentTarget, K-1, output, mapParent, visited);
        searchNode(target->left, K-1, output, mapParent, visited);
        searchNode(target->right, K-1, output, mapParent, visited);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        //make a parent map; do an inorder traversal
        std::unordered_map<TreeNode*, TreeNode*> mapParent;
        std::set<TreeNode*> visited;
        mapParent.insert({root, nullptr});
        fillParentMap(root, mapParent);
        
        std::vector<int> output;
        //search in children
        
        searchNode(target, K, output, mapParent, visited);
        
        return output;
    }
};