typedef long long ll;
class Solution {
public:
    int binarySearchGreater(std::vector<int>& nums, int st, int end, ll element) {
        if (st > end)
            return -1;
        int mid = st + (end-st)/2;
        if (nums[mid] > element) {
            int ans1 = binarySearchGreater(nums, st, mid-1, element);
            if (ans1 == -1)
                return mid;
            else
                return ans1;
        } else {
            return binarySearchGreater(nums, mid+1, end, element);
        }
    }
    
    
    
    void merge(std::vector<int>& nums, int st, int end) {
        int mid = st + (end-st)/2;
        std::vector<int> temp (end - st + 1, 0);
        int ind1 = st;
        int ind2 = mid+1;
        int ind = 0;
        int ans = 0;
        while (ind1 <= mid && ind2 <= end) {
            if (nums[ind1] < nums[ind2]) {
                temp[ind++] = nums[ind1++];
            } else {
                temp[ind++] = nums[ind2++];
            }
        }
        
        while (ind1 <= mid) {
            temp[ind++] = nums[ind1++];
        }
        
        while (ind2 <= end) {
            temp[ind++] = nums[ind2++];
        }
        
        
        for (int i = st, j = 0; i <= end; i++, j++) {
            nums[i] = temp[j];
        }
        
    }
    int mergeSort(std::vector<int>& nums, int st, int end) {
        if (st >= end)
            return 0;
        int mid = st + (end-st)/2;
        int ans = 0;
        ans += mergeSort(nums, st, mid);
        ans += mergeSort(nums, mid+1, end);
        //count pairs from the two subproblems
        int i = st;
        int j = mid+1;
        
        while (i <= mid) {
            while (j <= end && (2LL*nums[j]) < nums[i])
                j++;
            
            ans += j - mid -1;
            
            i++;
        }
        merge(nums, st, end);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        //merge and count
        int ans =  mergeSort(nums, 0, nums.size()-1);
        
        return ans;
    }
};