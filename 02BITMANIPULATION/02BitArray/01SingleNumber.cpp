int Solution::singleNumber(const vector<int> &A) {
    long long ans = A[0];
    for(int i = 1; i < A.size(); i++)
        ans ^= A[i];
    return ans;
}

