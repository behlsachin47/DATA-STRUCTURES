typedef long long ll;

int Solution::maxArea(vector<int> &A) {
    int ans = 0;
    int ptr1 = 0;
    int ptr2 = A.size()-1;
    while (ptr1 < ptr2) {
        int h = std::min(A[ptr1], A[ptr2]);
        ans = std::max((ptr2-ptr1+1)*h, ans);
        if (h == A[ptr1])
            ptr1++;
        else
            ptr2--;
    }
    
    return ans;
}
 
