class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
                std::vector<std::vector<int>> res;

        if (nums.size() < 4)
            return res;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size()-3; i++) {
            if (i != 0 && nums[i] == nums[i-1])
                continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) 
                continue;
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target)
                continue;
            
            for (int j = i+1; j < nums.size()-2; j++) {
                if (j != i+1 && nums[j] == nums[j-1])
                    continue;
                int left = j+1;
                int right = n-1;
                while (left < right) {
                
                  int currSum = nums[i] + nums[j] + nums[left] + nums[right];
                  if (currSum == target) {
                      res.push_back(std::vector<int> {nums[i], nums[j], nums[left], nums[right]});
                      if (nums[left] == nums[right])
                          break;
                      while (left < right && nums[left] == nums[left+1])
                          left++;
                      
                      while (right > left && nums[right] == nums[right-1])
                          right--;
                      left++;
                      right--;
                  } else if (currSum > target) {
                      right--;
                  } else {
                      left++;
                  }
                
                }
            }
        }
        return res;
    }
};













//O(n^2 *k + S) approach
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> cumulativeSumHash;
        cumulativeSumHash.insert({0, 1});
        int ans = 0;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            if (cumulativeSumHash.count(currSum-k)) {
                ans += cumulativeSumHash[currSum-k];
            }
            
            if (cumulativeSumHash.count(currSum)) {
                cumulativeSumHash[currSum]++;
            } else {
                cumulativeSumHash.insert({currSum, 1});
            }
        }
        return ans;
        
        
    }
};





