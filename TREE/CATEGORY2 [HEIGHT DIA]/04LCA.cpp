TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* node1, TreeNode* node2, 
          bool& node1_found, bool& node2_found) {
    
    if (root == nullptr)
        return nullptr;
    bool node1_found_left = 0;
    bool node1_found_right = 0;
    bool node2_found_left = 0;
    bool node2_found_right = 0;
    
    TreeNode* smallRes1 = lowestCommonAncestor1(root->left, node1, node2, node1_found_left, node2_found_left);
    if (smallRes1)
        return smallRes1;
    
    TreeNode* smallRes2 = lowestCommonAncestor1(root->right, node1, node2, node1_found_right, node2_found_right);
    if (smallRes2)
        return smallRes2;
    
    
    if (root == node1)
        node1_found = true;
    
    if (root == node2)
        node2_found = true;

    node1_found |= (node1_found_left | node1_found_right);
    node2_found |= (node2_found_left | node2_found_right);
    if (node1_found && node2_found)
        return root;
    return nullptr;
              
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool node1_found = 0;
        bool node2_found = 0;
        
        return lowestCommonAncestor1(root, p, q, node1_found, node2_found);
        
    }
};


///     CODE2 : Assuming node1 and node2 are either both present or
///             one of them is present

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* smallRes1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* smallRes2 = lowestCommonAncestor(root->right, p, q);
        if (smallRes1 && smallRes2)
            return root;
        else 
            return smallRes1 ? smallRes1 : smallRes2;
        
    }
};