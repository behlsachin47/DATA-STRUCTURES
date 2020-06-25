class Solution {
public:
    
    int merge(std::vector<int>& A, int low, int high) {
        if (low == high)
            return 0;
        
        int mid = low + (high - low)/2;
        int index1 = low;
        int index2 = mid+1;
        int index = 0;
        std::vector<int> temp(high-low+1, 0);
        int ans = 0;
        
        while (index1 <= mid && index2 <= high) {
            if (A[index1] <= A[index2]) {
                temp[index++] = A[index1++];
            } else {
                ans += mid - index1 + 1;
                temp[index++] = A[index2++];
            }
        }
        
        while (index1 <= mid) {
            temp[index++] = A[index1++];
        }
        
        while (index2 <= high) {
            temp[index++] = A[index2++];
        }
        
        
        //copy these elements to A
        for (int i = low, j = 0; i <= high; i++, j++) {
            A[i] = temp[j];
        }
        
        return ans;
    }
    
    int countGlobalInversions(std::vector<int>& A, int low, int high) {
        if (low >= high) {
            return 0;
        }
        
        int mid = low + (high-low)/2;
        int ans = 0;
        ans += countGlobalInversions(A, low, mid);
        ans += countGlobalInversions(A, mid+1, high);
        
        //merge step
        ans += merge(A, low, high);
        return ans;
    }
    
    int countLocalInversions(std::vector<int>& A) {
        
        int ans = 0;
        for (int i = 0; i < A.size()-1; i++) {
            if (A[i] > A[i+1])
                ans++;
        }
        
        return ans;
    }
    
    bool isIdealPermutation(vector<int>& A) {
        //count inversions by merge sort
        int localInversions = countLocalInversions(A);
        int globalInversions = countGlobalInversions(A, 0, A.size()-1);
        
        //std::cout << globalInversions << " " << localInversions << std::endl;
        return globalInversions == localInversions;
    }
};