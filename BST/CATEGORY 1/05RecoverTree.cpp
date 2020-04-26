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
    void recoverTree(TreeNode* root) {
        std::vector<TreeNode*> cont;
        std::vector<int> cont2;
        //PUTS THE PROBLEMATIC NODES WHILE DOING INORDER TRAVERSAL IN A VECTOR
        TreeNode* iter = root;
        TreeNode* pIter = nullptr;
        std::stack<TreeNode*> st1;
        
        while (!st1.empty() || iter) {
            while (iter) {
                st1.push(iter);
                iter = iter->left;
            }
            
            //iter is null
            iter = st1.top();
            st1.pop();
            if (pIter) {
                if (pIter->val > iter->val) {
                    cont.push_back(pIter);
                    cont.push_back(iter);
                    cont2.push_back(pIter->val);
                    cont2.push_back(iter->val);
                }
            }
            pIter = iter;
            iter = iter->right;
        }
        
        std::sort(cont2.begin(), cont2.end());
        for (int i = 0; i < cont.size(); i++) {
            cont[i]->val = cont2[i];
        }
        
        
    }
};




//O(1) memory

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
    
    TreeNode* findPre(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* ans = root->left;
        while (ans->right != nullptr && ans->right != root)
            ans = ans->right;
        return ans;
    }
    void recoverTree(TreeNode* root) {
        //morris inorder traversal
        //std::stack<TreeNode*> st;
        if (root == nullptr)
            return;
        TreeNode* iter = root;
        TreeNode* pIter = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        
        while (iter) {
            if (iter->left == nullptr) {
                if (pIter) {
                    if (pIter->val >= iter->val) {
                        if (first) {
                            second = iter;
                        } else {
                            first = pIter;
                            second = iter;
                        }
                    }    
                }
                pIter = iter;
                iter = iter->right;
            } else {
                TreeNode* predIter = findPre(iter);
                if (predIter->right == nullptr) {
                    predIter->right = iter; 
                    iter = iter->left;
                } else {
                    //visiting again
                    predIter->right = nullptr;
                    if (pIter) {
                      if (pIter->val >= iter->val) {
                         if (first) {
                            second = iter;
                        } else {
                            first = pIter;
                            second = iter;
                        }
                      }    
                    }
                    pIter = iter;
                    iter = iter->right;
                }
            }
            
        }
        
        int tempData = first->val;
        first->val = second->val;
        second->val = tempData;
        //std::cout <<"doeee";
        //printTree(root);
    }
};