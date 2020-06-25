//////////////////////////EFFECIENT APPROACH ////////////////

class Solution {
public:
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1)
            return ;
        
        for (int i = 0; i < nums.size()-1; i++) {
            if (i % 2 == 0 && nums[i] > nums[i+1]) 
                swap(nums[i], nums[i+1]);
            else if (i % 2 != 0 && nums[i] < nums[i+1])
                swap(nums[i], nums[i+1]);
        }
    }
};















//LEXICOGRAPHICALLY SMALLEST

swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> Solution::wave(vector<int> &A) {
    std::sort(A.begin(), A.end());
    for (int i = 0; i < A.size()-1; i += 2) {
        swap(A[i], A[i+1]);
    }
    return A;
}

