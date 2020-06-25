/*
Two Sum, Two Sum II and 3Sum share a similarity that the sum of elements must match the target exactly. A difference is that, instead of giving just one combination of elements, we need to find all unique combinations that sum to the target.

Before jumping in, let's check existing solutions and determine the best conceivable runtime (BCR) for 3Sum:

Two Sum uses a hashmap to find complement values, and therefore achieves \mathcal{O}(N)O(N) time complexity.
Two Sum II uses the two pointers pattern and also has \mathcal{O}(N)O(N) time complexity for a sorted array. We can use this approach for any array if we sort it first, which bumps the time complexity to \mathcal{O}(n\log{n})O(nlogn).
Considering that there is one more dimension in 3Sum, it sounds reasonable to shoot for \mathcal{O}(n^2)O(n 
2
 ) time complexity as our BCR.
*/











class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++) {
            if (i != 0 && nums[i-1] == nums[i])
                continue;
            if (nums[i] + nums[i+1] + nums[i+2] > 0)
                continue;
            if (nums[i] + nums[n-2] + nums[n-1] < 0)
                continue;
            
            int sumLeft = -1*nums[i];
            int leftIndex = i+1;
            int rightIndex = n-1;
            
            while (leftIndex < rightIndex) {
                int currSum = nums[leftIndex] + nums[rightIndex];
                if (currSum == sumLeft) {
                    std::vector<int> temp {nums[i], nums[leftIndex], nums[rightIndex]};
                    result.push_back(temp);
                    
                    if (nums[leftIndex] == nums[rightIndex]) {
                        break;
                    } else {
                        while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex+1])
                            leftIndex++;
                        
                        while (rightIndex > leftIndex && nums[rightIndex] == nums[rightIndex-1]) 
                            rightIndex--;
                        
                        leftIndex++;
                        rightIndex--;
                    }
                } else if (currSum > sumLeft) {
                    rightIndex--;
                } else {
                    leftIndex++;
                }
            }
        }
        
        return result;
    }
};