class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        std::sort(intervals.begin(), intervals.end());
        int ans = 0;
        int currOverlap = 1;
        for (int st = 0; st < intervals.size()-1; st++) {
            //check if overlap
            if ((intervals[st+1][0] > intervals[st][0] && intervals[st+1][0] < intervals[st][1]) || 
                (intervals[st+1][0] == intervals[st][0])) {
                intervals[st+1][1] = std::min(intervals[st+1][1], intervals[st][1]);
                currOverlap++;
            } else {
                if (currOverlap > 1) {
                    ans += currOverlap -1;
                }
                currOverlap = 1;
            }
        }
        if (currOverlap > 1)
            ans += currOverlap -1;
        return ans;
    }
};