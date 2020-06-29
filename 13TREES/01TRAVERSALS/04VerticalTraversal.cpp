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

typedef std::pair<int, int> iPair;
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::vector<std::vector<int>> output;
        if (root == nullptr)
            return output;
        
        std::unordered_map<int, std::vector<iPair> > mapVerticalLevelToNodes;
        
        std::queue<std::pair<TreeNode*, int>> q;
        int currLevel = 0;
        int minVLevel = 0;
        int maxVLevel = 0;
        q.push(std::make_pair(root, 0));
        q.push(std::make_pair(nullptr,0));
        
        while(!q.empty()) {
            auto currNodeVLevel = q.front();
            q.pop();
            
            
            TreeNode* currNode = currNodeVLevel.first;
            int currVLevel = currNodeVLevel.second;
            minVLevel = std::min(currVLevel, minVLevel);
            maxVLevel = std::max(currVLevel, maxVLevel);
            
            if (currNode == nullptr) {
                if (q.empty())
                    continue;
                currLevel++;
                q.push(std::make_pair(nullptr, 0));
            } else {
                if (!mapVerticalLevelToNodes.count(currVLevel)) {
                    mapVerticalLevelToNodes.insert({currVLevel, std::vector<iPair> {}});
                }
                
                mapVerticalLevelToNodes[currVLevel].push_back(std::make_pair(currNode->val, currLevel));
                
                if (currNode->left) 
                    q.push(std::make_pair(currNode->left, currVLevel-1));
                
                if (currNode->right)
                    q.push(std::make_pair(currNode->right, currVLevel+1));
            }
        }
        
        for(int i = minVLevel; i <= maxVLevel; i++) {
            output.push_back(std::vector<int> {});
            int size = mapVerticalLevelToNodes[i].size();
            /*std::cout << i << " " << size << std::endl;
            for (int j = 0; j < size; j++) {
                std::cout << mapVerticalLevelToNodes[i][j].first << "," << mapVerticalLevelToNodes[i][j].second << "\t";
            }
            std::cout << std::endl;*/
            for (int j = 0; j < size; j++) {
                std::vector<int> temp;
                temp.push_back(mapVerticalLevelToNodes[i][j].first);
                while (j+1 < size && (mapVerticalLevelToNodes[i][j].second == mapVerticalLevelToNodes[i][j+1].second)) {
                    temp.push_back(mapVerticalLevelToNodes[i][j+1].first);
                    j++;
                } 
                
                std::sort(temp.begin(), temp.end());
                for (int k = 0; k < temp.size(); k++)
                    output[i-minVLevel].push_back(temp[k]);
            }
        }
        
        return output;
    }
};