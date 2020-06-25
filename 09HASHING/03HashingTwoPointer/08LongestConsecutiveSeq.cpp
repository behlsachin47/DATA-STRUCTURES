class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        std::unordered_set<int> numberAns;
        for (int i = 0; i < nums.size(); i++) {
            numberAns.insert({nums[i]});
        }
        int ans = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (numberAns.count(nums[i]-1)) 
                continue;
            else {
                //consider number nums[i] as start
                int currNum = nums[i];
                int freq = 1;
                
                while (numberAns.count(currNum)) {
                    currNum++;
                    freq++;
                }
                ans = std::max(ans, freq-1);
                
            }
        }
        return ans;
    }
};