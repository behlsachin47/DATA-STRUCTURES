/* Matrix search:
 *  Matrix is sorted row wise as well as the last element of row is less than
 *  first element of next row.
 *  
 * */


/* Can we solve it in log (m) + log(n) time ??
 *
 * */


int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    
    int low = 0; int high = n-1;
    int rowAns = -1;
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (A[mid][0] <= B) {
            rowAns = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    
    low = 0; high = m-1;
    while (low <= high) {
        int mid = low + (high-low)/2;
        if(A[rowAns][mid] == B) {
            return 1;
        } else if (A[rowAns][mid] > B) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return 0;
}

