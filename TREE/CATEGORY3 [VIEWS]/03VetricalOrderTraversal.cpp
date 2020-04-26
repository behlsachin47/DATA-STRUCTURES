typedef std::pair<std::pair<int, int>, int> dPair;
bool myCompare(const dPair& a, const dPair& b) {
    if (a.first.first < b.first.first)
        return true;
    else if (a.first.first > b.first.first)
        return false;
    else {
        if (a.first.second < b.first.second)
            return true;
        else if (a.first.second > b.first.second)
            return false;
        else 
            return a.second < b.second;
    }
}
typedef std::pair<int, TreeNode*> ipair;
vector<vector<int> > verticalTraversalUtil(TreeNode* root) {
    vector<vector<int> > result;
    vector<std::pair<std::pair<int, int>, int> > tempRes;
    if (root == nullptr)
        return result;
    int hzLevel = 0;
    
    std::queue<ipair> q;
    q.push(std::make_pair(0,root));
    q.push(std::make_pair(0,nullptr));
    
    while (!q.empty()) {
        ipair curr = q.front();
        q.pop();
    
        int vLevel = curr.first;
        TreeNode* node = curr.second;
        if (node == nullptr) {
            hzLevel++;
            if (!q.empty())
                q.push(std::make_pair(0,nullptr));
            continue;
        }
        
        tempRes.push_back(std::make_pair(std::make_pair(vLevel,hzLevel), node->val));
        
        if(node->left)
            q.push(std::make_pair(vLevel-1, node->left));
        
        if (node->right)
            q.push(std::make_pair(vLevel+1, node->right));
        

    }
    
    
    std::sort(tempRes.begin(), tempRes.end(), myCompare);
    
    int pvLevel = -1000;
    int vLevel = -1;
    int minLevel = tempRes.begin()->first.first;
    for (auto iter = tempRes.begin(); iter != tempRes.end(); iter++) {
        vLevel = iter->first.first;
        if (vLevel == pvLevel) {
            result[vLevel-minLevel].push_back(iter->second);
        } else {
            result.push_back(vector<int>{});
            result[vLevel-minLevel].push_back(iter->second);
        }
        pvLevel = vLevel;
    }

    return result;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return verticalTraversalUtil(root);        
    }
};