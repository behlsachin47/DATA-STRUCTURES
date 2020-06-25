/*Array 3 Pointers
Problem Description
You are given 3 sorted arrays A, B and C. Find i, j, k such that : max(abs(A[i]
- B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized. Return the minimum
  max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])).   


  Problem Constraints
  0 <= len(A), len(B), len(c) <= 106 0 <= A[i], B[i], C[i] <= 107    


  Input Format
  First argument is an integer array A. Second argument is an integer array B.
  Third argument is an integer array C.    


  Output Format
  Return an single integer denoting the minimum max(abs(A[i] - B[j]), abs(B[j]
  - C[k]), abs(C[k] - A[i])).


    Example Input*/


int Solution::minimize(const vector<int> &A, const vector<int> &B, const
vector<int> &C) {
    int pt1 = 0;
    int pt2 = 0;
    int pt3 = 0;
    int ans = INT_MAX;
    while (pt1 < A.size() && pt2 < B.size() && pt3 < C.size()) {
        int maxElement = std::max(A[pt1], std::max(B[pt2], C[pt3]));
        int minElement = std::min(A[pt1], std::min(B[pt2], C[pt3]));
        ans = std::min(ans, maxElement-minElement);
        
        if (minElement == A[pt1]) 
            pt1++;
        else if (minElement == B[pt2])
            pt2++;
        else 
            pt3++;
    }
    
    return ans;
}

