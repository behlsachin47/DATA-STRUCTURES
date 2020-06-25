int Solution::minimize(const vector<int> &A, const vector<int> &B, const
vector<int> &C) {
    int i = 0;
    int j = 0;
    int k = 0;
    int ans = INT_MAX;
    while (i != A.size() && j != B.size() && k != C.size()) {
        ans = std::min(std::max(std::max(abs(A[i]-B[j]), abs(B[j]-C[k])),
abs(A[i]-C[k])), ans);
        if (A[i] >= C[k] && B[j] >= C[k]) {
            k++; 
        } else if (A[i] >= B[j] && C[k] >= B[j]) {
            j++;
        } else {
            i++;
        }
    }
    if (ans == INT_MAX)
        return 0;
    return ans;
}
