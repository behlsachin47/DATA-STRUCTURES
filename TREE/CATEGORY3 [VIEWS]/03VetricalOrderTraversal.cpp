typedef std::pair<int, TreeNode*> ipair;
vector<vector<int> > verticalTraversalUtil(TreeNode* root) {
    vector<vector<int> > res;
    std::unordered_map<int, vector<int> >map1;
    if (root == nullptr)
        return res;
    
    std::queue<ipair> q;
    q.push(std::make_pair(0,root));
    while (!q.empty()) {
        ipair curr = q.front();
        q.pop();

        int vLevel = curr.first;
        TreeNode* node = curr.second;

        if (map1.count(vLevel) == false) {
            map1.insert({vLevel, std::vector<int>{}});
        }
        map1[vLevel].push_back(node->val);

        if(node->left)
            q.push(std::make_pair(vLevel-1, node->left));
        
        if (node->right)
            q.push(std::make_pair(vLevel+1, node->right));

    }
    int minLevel = 0;
    int maxLevel = 0;
    //iterate over map and find the min and max levels
    for (auto iter = map1.begin(); iter != map1.end(); iter++) {
        if (iter->first < minLevel)
            minLevel = iter->first;
        
        if (iter->first > maxLevel)
            maxLevel = iter->first;
    }


    for (int level = minLevel; level <= maxLevel; level++) {
        res.push_back(map1[level]);
    }

    return res;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return verticalTraversalUtil(root);        
    }
};