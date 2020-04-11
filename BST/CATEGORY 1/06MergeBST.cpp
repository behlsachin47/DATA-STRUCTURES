/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, TreeNode* B) {
    std::stack<TreeNode*> st1;
    std::stack<TreeNode*> st2;
    
    while (A) {
        st1.push(A);
        A = A->left;
    }
    while (B) {
        st2.push(B);
        B = B->left;
    }
    
    std::vector<int> res;
    
    while (!st1.empty() && !st2.empty()) {
      //  std::cout << st1.size() << "  " << st2.size() << std::endl; 
        //get the top and compare
        if (st1.top()->val > st2.top()->val) {
            res.push_back(st2.top()->val);
            //get next element of st2
            TreeNode* curr = st2.top();
            st2.pop();
            if (curr->right) {
                curr = curr->right;
                while (curr) {
                    st2.push(curr);
                    curr = curr->left;
                }
            }
        } else {
            TreeNode* curr = st1.top();
            res.push_back(curr->val);
            st1.pop();
            
            if (curr->right) {
                curr = curr->right;
                while (curr) {
                    st1.push(curr);
                    curr = curr->left;
                }
            }
        }
    }
    
    //std::cout << "done" << std::endl;
    
    while (!st2.empty()) {
        TreeNode* curr = st2.top();
        res.push_back(curr->val);
        st2.pop();
        if (curr->right) {
            curr = curr->right;
            while (curr) {
                st2.push(curr);
                curr = curr->left;
            }
        }
    }
    
    while (!st1.empty()) {
        TreeNode* curr = st1.top();
        res.push_back(curr->val);
        st1.pop();
        if (curr->right) {
            curr = curr->right;
            while (curr) {
                st1.push(curr);
                curr = curr->left;
            }
        }
    }
    
    return res;
}
