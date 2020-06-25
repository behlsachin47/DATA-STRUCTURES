void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j >= i)
                break;
            swap(A[i][j], A[j][i]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::reverse(A[i].begin(), A[i].end());
    }
    
    
    return;
}

