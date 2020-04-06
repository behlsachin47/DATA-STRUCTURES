class Solution {
public:
    void fillParentMap(TreeNode* root, TreeNode* target, 
                       std::unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (root == nullptr || root == target)
            return;
        
        if (root->left) {
            parentMap.insert({root->left, root});
            fillParentMap(root->left, target, parentMap);
        }

        if (root->right) {
            parentMap.insert({root->right, root});
            fillParentMap(root->right, target, parentMap);
        }
    }  

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        std::unordered_map<TreeNode*, TreeNode*> parentMap;
        std::unordered_set<TreeNode*> visited;
        std::vector<int> result;

        //fill the parentMap till you get the target node
        fillParentMap(root, target, parentMap);

        //NOW START BFS FROM target ; explore parent if not yet explored
        std::queue<TreeNode*> q;
        q.push(target);
        q.push(nullptr);
        visited.insert(target);
        int level = 0;

        while (!q.empty()) {
            if (level == K)
                break;
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                level++;
            }

            //explore all its children
            if (parentMap.count(curr)) {
                TreeNode* parent = parentMap[curr];
                if (visited.count(parent) == false) {
                    q.push(parent);
                    visited.insert(parent);
                }
            }

            if (curr->left && visited.count(curr->left) == false) {
                visited.insert(curr->left);
                q.push(curr->left);
            }

            if (curr->right && visited.count(curr->right) == false) {
                visited.insert(curr->right);
                q.push(curr->right);
            }
        }

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                result.push_back(curr->data);
            }
        }

        return result;
    }
};


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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        std::vector<int> res;
        dfs(root, target, res, K);
        return res;
    }
    
    int dfs(TreeNode* root, TreeNode* target, std::vector<int>& res, int K) {
        //three cases":
        //if target == root; explore both right and left subtrees for distance k
        if (root == nullptr)
            return -1;
        else if (root == target) {
            addST(root, 0, K, res);
            return 0;
        } else {
            int L = dfs(root->left, target, res, K);
            int R = dfs(root->right, target, res, K);
            if (L != -1) {
                if (L+1 == K) {
                    res.push_back(root->val);
                } else {
                    addST(root->right, L+2, K, res);
                }
                return L+1;
            } else if (R != -1) {
                if (R+1 == K) {
                    res.push_back(root->val);
                } else {
                    addST(root->left, R+2, K, res);
                } 
                return R+1;
            } else {
                return -1;
            }
        }
    }
    
    void addST(TreeNode* root, int currDist, int targetDist, std::vector<int>& res) {
        if (currDist > targetDist || root == nullptr)
            return;
        else if (currDist == targetDist) {
            res.push_back(root->val);
            return;
        } else {
            addST(root->left, currDist+1, targetDist, res);
            addST(root->right, currDist+1, targetDist, res);
        }
    }
};