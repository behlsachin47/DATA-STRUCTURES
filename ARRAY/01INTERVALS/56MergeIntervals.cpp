class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> out;
        if (intervals.size() == 0)
            return out;
        
        std::sort(intervals.begin(), intervals.end());
        std::vector<int> curr {intervals[0][0], intervals[0][1]};
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= curr[1]) {
                curr[1] = std::max(curr[1], intervals[i][1]); 
            } else {
                out.push_back(curr);
                curr[0] = intervals[i][0];
                curr[1] = intervals[i][1];
            }
        }
        out.push_back(curr);
        
        return out;
    }
};