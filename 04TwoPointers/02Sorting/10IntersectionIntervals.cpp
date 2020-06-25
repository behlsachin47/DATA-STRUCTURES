class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ptr1 = 0;
        int ptr2 = 0;
        int n1 = A.size();
        int n2 = B.size();
        std::vector<std::vector<int>> output;
        
        while (ptr1 < n1 && ptr2 < n2) {
            if (A[ptr1][0] >= B[ptr2][0]) {
                if (A[ptr1][0] <= B[ptr2][1]) {
                    int st = A[ptr1][0];
                    int end;
                    if (A[ptr1][1] > B[ptr2][1]) {
                        end = B[ptr2][1];
                        ptr2++;
                    } else {
                        end = A[ptr1][1];
                        ptr1++;
                    }
                    
                    output.push_back(std::vector<int> {st, end});
                } else {
                    //ignore the smaller one
                    ptr2++;
                }
                
            } else {
                if (B[ptr2][0] <= A[ptr1][1]) {
                    int st = B[ptr2][0];
                    int end;
                    if (A[ptr1][1] > B[ptr2][1]) {
                        end = B[ptr2][1];
                        ptr2++;
                    } else {
                        end = A[ptr1][1];
                        ptr1++;
                    }
                    output.push_back(std::vector<int> {st, end});
                } else {
                    //ignore
                    ptr1++;
                }
            }
        }
        
        return output;
    }
};



//////////////////////////////////////// eligent

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ptr1 = 0;
        int ptr2 = 0;
        int n1 = A.size();
        int n2 = B.size();
        std::vector<std::vector<int>> output;
        
        while (ptr1 < n1 && ptr2 < n2) {
            int low = std::max(A[ptr1][0], B[ptr2][0]);
            int high = std::min(A[ptr1][1], B[ptr2][1]);
            
            if (low <= high) {
                output.push_back(std::vector<int> {low, high});
            }
            
            if (B[ptr2][1] > A[ptr1][1]) {
                ptr1++;
            } else {
                ptr2++;
            }
        }
        
        return output;
    }
};