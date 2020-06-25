class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s <= 0 || nums.size() == 0)
            return 0;
        
        int ptr1 = 0;
        int ptr2 = 0;
        int answer = INT_MAX;
        int currSum = 0;
        
        while (ptr2 < nums.size()) {
            currSum += nums[ptr2];
            
            if (currSum >= s) {
                //decrease ptr2 and optimize the answer if possible
                while (currSum >= s) {
                    answer = std::min(answer, ptr2 - ptr1 + 1);
                    currSum -= nums[ptr1];
                    ptr1++;
                }
            }
            ptr2++;
        }
        if (answer == INT_MAX)
            return 0;
        return answer;
    }
};