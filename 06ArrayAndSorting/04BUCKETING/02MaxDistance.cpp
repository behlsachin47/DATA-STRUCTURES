typedef std::pair<int, int> iPair;
int Solution::maximumGap(const vector<int> &A) {
    if (A.size() == 0)
        return -1;
        
    std::vector<iPair> dp;
    for (int i = 0; i < A.size(); i++) {
        dp.push_back(std::make_pair(A[i], i));
    }
    
    std::sort(dp.begin(), dp.end());
    
    int ans = 0;
    int lowestIndex = dp[0].second;
    for (int i = 1; i < dp.size(); i++) {
        if (dp[i].second > lowestIndex) {
            ans = std::max(ans, dp[i].second-lowestIndex);
        } else {
            lowestIndex = dp[i].second;
        }
    }
    return ans;
}

