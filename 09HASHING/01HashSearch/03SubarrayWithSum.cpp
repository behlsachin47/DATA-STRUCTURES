







class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::multiset<int> cumulativeSumHash;
        cumulativeSumHash.insert(0);
        int ans = 0;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            ans += cumulativeSumHash.count(currSum-k);
            
            cumulativeSumHash.insert(currSum);
        }
        return ans;
        
        
    }
};