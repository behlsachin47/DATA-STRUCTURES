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
    
    int pathSumUtil(TreeNode* root, int currSum, std::unordered_map<int, int>& prefixSumMap, int K) {
        if (root == nullptr)
            return 0;
        int ans = 0;
        currSum += root->val;
        int sumToFind = currSum - K;
        
        if (prefixSumMap.count(sumToFind)) {
            ans += prefixSumMap[sumToFind];
        }
        
        if (prefixSumMap.count(currSum)) {
            prefixSumMap[currSum]++;
        } else {
            prefixSumMap.insert({currSum, 1});
        }
        
        ans += pathSumUtil(root->left, currSum, prefixSumMap, K);
        ans += pathSumUtil(root->right, currSum, prefixSumMap, K);
        
        prefixSumMap[currSum]--;
        //if (pre)
        return ans;
    }
    
    int calculateSubarraySumEqToK(std::vector<int>& vec, int K) {
        std::unordered_map<int, int> mapPrefixSumToIndex;
        mapPrefixSumToIndex.insert({0,1});
        int ans = 0;
        for (int i = 0; i < vec.size(); i++) {
            int sumToFind = vec[i]-K;
            if (mapPrefixSumToIndex.count(sumToFind))
                ans+= mapPrefixSumToIndex[sumToFind];
            
            if (mapPrefixSumToIndex.count(vec[i]))
                mapPrefixSumToIndex[vec[i]]++;
            else
                mapPrefixSumToIndex.insert({vec[i], 1});
        }
        return ans;
    }
    
    int pathSum(TreeNode* root, int sum) {
        //find all prefix sum array from root to leaf;
        //dfs
        int ans = 0;
        std::unordered_map<int, int> prefixSumToMap;
        prefixSumToMap.insert({0, 1});
        
        return pathSumUtil(root, 0, prefixSumToMap, sum);
        
        
    }
};





class Solution {
public:
    
    void exploreEnds(TreeNode* currNode, int currSum, int targetSum, int& ans) {
        if (currNode == nullptr)
            return;
        
        currSum += currNode->val;
        if (currSum == targetSum)
            ans++;
        
        exploreEnds(currNode->left, currSum, targetSum, ans);
        exploreEnds(currNode->right, currSum, targetSum, ans);
        
    }
    int pathSum(TreeNode* root, int sum) {
        //chhose a start point by level order traversal ?
        if (root == nullptr)
            return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            TreeNode* startNode = q.front();
            q.pop();
            exploreEnds(startNode, 0, sum, ans);
            
            if (startNode->left) {
                q.push(startNode->left);
            }
            
            if (startNode->right) {
                q.push(startNode->right);
            }
        }
        return ans;
    }
};