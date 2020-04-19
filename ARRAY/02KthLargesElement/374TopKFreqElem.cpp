class Solution {
public:
    void swap(std::vector<int>& input, int pos1, int pos2) {
        int temp = input[pos1];
        input[pos1] = input[pos2];
        input[pos2] = temp;
    }
    
    bool quickSelect(std::vector<int>& input, std::unordered_map<int, int>&
map1, int st, int end, int k) {
        if (st > end)
            return false;
        else if (st == end)
            return 1;
        
        int pivot = rand()%(end-st) + st;
        swap(input, pivot, end);
        
        int divider = st;
        for (int i = st; i < end; i++) {
            if (map1[input[i]] > map1[input[end]]) {
                swap(input, i, divider);
                divider++;
            }
        }
        
        swap(input, divider, end);
        if (divider == k) {
            return true;
        } else if (divider > k) {
            return quickSelect(input, map1, st, divider-1, k);
        } else {
            return quickSelect(input, map1, divider+1, end, k);
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map1;
        std::vector<int> input;
        std::vector<int> res;
        
        if (nums.size() == 0 || k > nums.size())
            return res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (map1.count(nums[i]) == 0) {
                input.push_back(nums[i]);
                map1.insert({nums[i], 1});
            } else {
                map1[nums[i]]++;
            }
        }
        
        if (input.size() < k)
            return res;
        
        quickSelect(input, map1, 0, input.size()-1, k-1);
        
        for (int i = 0; i < k; i++) {
            res.push_back(input[i]);
        }
        return res;
    }
};
