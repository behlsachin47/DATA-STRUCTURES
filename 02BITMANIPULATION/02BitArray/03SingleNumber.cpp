//all numbers except two numbers appear twice
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorValue = 0;
        for (int i = 0; i < nums.size(); i++)
            xorValue ^= nums[i];
        
        int diffBitIndex = log2((xorValue & (xorValue-1)) ^ xorValue);
        
        int mask = (1 << diffBitIndex);
        std::vector<int> result {0,0};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & mask) {
                result[1] ^= nums[i];
            } else {
                result[0] ^= nums[i];
            }
        }
        
        return result;
    }
};
