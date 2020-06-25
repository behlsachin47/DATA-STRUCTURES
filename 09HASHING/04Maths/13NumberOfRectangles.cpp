typedef std::pair<int, int> iPair;
int Solution::solve(vector<int> &A, vector<int> &B) {
    std::set<iPair> pointsSet;
    for (int i = 0; i < A.size(); i++) {
        iPair tempPair = std::make_pair(A[i], B[i]);
        pointsSet.insert(tempPair);
    }
    
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            if (A[j] > A[i] && B[j] > B[i]) {
                iPair tempPair1 = std::make_pair(A[j], B[i]);
                iPair tempPair2 = std::make_pair(A[i], B[j]);
                if (pointsSet.count(tempPair1) && pointsSet.count(tempPair2)) {
                    ans++;
                }
            }
        }
    }
    
    return ans;
}
