ass Solution {
public:
    int maximumGap(vector<int>& nums) ;
};

int Solution::maximumGap( vector<int> &A) {
    if (A.size() <= 1)
        return 0;
    double minGap = (*std::max_element(A.begin(), A.end())
- *std::min_element(A.begin(),A.end()))/(1.0 *(A.size()-1));
      
    if (minGap == 0.0 || A.size() == 2)
        return minGap;
    int minElement = *std::min_element(A.begin(), A.end());
    
    std::vector<int> bucketMax (A.size()-1, INT_MIN);
    std::vector<int> bucketMin (A.size()-1, INT_MAX);
    
    for (int i = 0; i < A.size(); i++) {
        int bucketNum = (A[i]-minElement)/minGap;
        if (bucketNum == A.size()-1) {
            bucketNum--;
        }
        
        bucketMin[bucketNum] = std::min(bucketMin[bucketNum], A[i]);
        bucketMax[bucketNum] = std::max(bucketMax[bucketNum], A[i]);
    }
    
    
    int ans = minGap;
    for (int i = 0; i < A.size()-2; ) {
        if (bucketMax[i] == INT_MIN) {
            i++;
        } else {
            int j = i+1;
            while (j < A.size()-1) {
                if (bucketMin[j] == INT_MAX) 
                    j++;
                else {
                    ans = std::max(ans, bucketMin[j]-bucketMax[i]);
                    break;
                }
            }
            i = j;
        }
        
    }
    
    return ans;
    
}

