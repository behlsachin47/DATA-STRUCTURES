int Solution::solve(vector<int> &A, vector<int> &B) {
    std::unordered_map<int, int> xAxisPoints;
    std::unordered_map<int, int> yAxisPoints;
    
    for (int i = 0; i < A.size(); i++) {
        if (xAxisPoints.count(A[i]))
            xAxisPoints[A[i]]++;
        else 
            xAxisPoints.insert({A[i], 1});
            
            
        if (yAxisPoints.count(B[i]))
            yAxisPoints[B[i]]++;
        else
            yAxisPoints.insert({B[i], 1});
    }
    
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        ans += (xAxisPoints[A[i]]-1) * (yAxisPoints[B[i]]-1);
    }
    
    return ans;
}
