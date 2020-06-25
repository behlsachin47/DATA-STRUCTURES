/*Problem Description
 * Given a array of integers A of size N and an integer B. Return number of
 * non-empty subsequences of A of size B having sum <= 1000.   
 *
 *
 * Problem Constraints
 * 1 <= N <= 20 1 <= A[i] <= 1000 1 <= B <= N   
 *
 *
 * Input Format
 * The first argument given is the integer array A. The second argument given
 * is the integer B.   
 *
 *
 * Output Format
 * Return number of subsequences of A of size B having sum <= 1000.
 *
 *
 * Example Input
 * Input 1:
 *     A = [1, 2, 8]
 *         B = 2
 *         Input 2:
 *             A = [5, 17, 1000, 11]
 *                 B = 4
 *                   
 *
 *
 *                   Example Output
 *                   Output 1:
 *                   3
 *                   Output 2:
 *                   0
 *                     
 *
 *
 *                     Example Explanation
 *                     Explanation 1:
 *                      {1, 2}, {1, 8}, {2, 8}
 *                       Explanation 1: 
 *                        No valid subsequence
 *
 *
 * */



///APPROACH 1: CHOOSE A CHARACTER OR NOT


void solve2(std::vector<int>& vec, int B, int index, int cLen, int cSum, int&
ans) {
    if (index == vec.size()) {
        if (cLen == B && cSum <= 1000)
            ans++;
        return;
    } else if (cLen > B) {
        return;
    } else if (vec.size() - index < B- cLen) {
        return;
    }
    solve2(vec, B, index+1, cLen, cSum, ans);
    solve2(vec, B, index+1, cLen + 1, cSum + vec[index], ans);
    
}
int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    solve2(A, B, 0, 0, 0, ans);
    return ans;
}


void solve2(std::vector<int>& vec, int B, int ind, int cLevel, int cSum, int&
ans) {
    if (cLevel > B || cSum > 1000) {
        return;
    } else if (cLevel == B) {
        if (cSum <= 1000) {
            ans++;
        }
        return;
    } else if (ind == vec.size()) {
       return;  
    }
    
    
    for (int i = ind; i < vec.size(); i++) {
        solve2(vec, B, i+1, cLevel+1, cSum + vec[i], ans);
    }
    
}
int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    solve2(A, B, 0, 0, 0, ans);
    return ans;
}

