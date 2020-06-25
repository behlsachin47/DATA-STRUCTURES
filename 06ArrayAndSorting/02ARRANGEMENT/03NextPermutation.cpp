class Solution {
public:
    void swap(int&a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for (int i = n-1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                index = i-1;
                break;
            }
        }
        
        if (index == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        } else {
            int j;
            for (j = n-1; j > index; j--) {
                if (nums[index] < nums[j])
                    break;
            }
            swap(nums[index], nums[j]);
            std::reverse(nums.begin()+index+1, nums.end());
        }
         
    }
};
