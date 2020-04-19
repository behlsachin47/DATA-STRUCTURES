///////////////APPROACH1 O(nlogk) /////////////////
//////////heap based solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (n == 0 || k > n)
            return -1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);
        
        for (int i = k; i < n; i++) {
            if (pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};



/////////////////APPROACH O(n) approach/////////////
//randomized quick sort to the rescue :)
//

class Solution {
public:
    
    void swap(std::vector<int>& nums, int pos1, int pos2) {
        int temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp;
    }
    
    int quickSort(std::vector<int>& nums, int st, int end, int pos) {
        if (st > end)
            return -1;
        if (st == end) 
            return nums[st];
        
        int randomPos = (rand() % (end-st)) + st;
        swap(nums, randomPos, end);
        
        //now place the divider
        int i = st;
        int divider = st;
        for (i = st; i < end; i++) {
            if (nums[i] < nums[end]) {
                swap(nums, i, divider);
                divider++;
            } else {
                
            }
        }
        swap(nums, divider, end);
        
        if (divider == pos)
            return nums[divider];
        else if (divider > pos) {
            return quickSort(nums, st, divider-1, pos);
        } else {
            return quickSort(nums, divider+1, end, pos);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if ( n == 0 || k > n)
            return -1;
        
        int pos = n-k;
        return quickSort(nums, 0, n-1, pos);
    }
};


//////////////BINARY SEARCH THE ANSWER o(n+ LOG(range))
class Solution {
public:
    
    int findKthLargest1(std::vector<int>& nums, int minElement, int maxElement, int k) {
        //std::cout << minElement << " " << maxElement << std::endl;
        if (maxElement < minElement)
            return -1;
        else if (maxElement == minElement)
            return maxElement;
        int middleElement = minElement + (maxElement - minElement)/2;
        
        int freq1, freq2;
        freq1 = freq2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (middleElement > nums[i])
                freq1++;
            
            if (middleElement >= nums[i])
                freq2++;
        }
       // std::cout << "\t" << middleElement << " " << freq1 << " " << freq2 << std::endl;
        if (freq1 < k && k <= freq2) {
            return middleElement;
        } else if (freq1 < k ) {
            return findKthLargest1(nums, middleElement+1, maxElement, k);
        } else {
            return findKthLargest1(nums, minElement, middleElement-1, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k > n)
            return -1;
        int maxElement = nums[0];
        int minElement = nums[0];
        for (int i = 0; i < n; i++) {
            maxElement = std::max(nums[i], maxElement);
            minElement = std::min(nums[i], minElement);
        }
        
        return findKthLargest1(nums, minElement, maxElement, n-k+1);
    }
};


