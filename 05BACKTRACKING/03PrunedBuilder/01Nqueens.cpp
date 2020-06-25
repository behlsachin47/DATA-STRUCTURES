class Solution {
public:
    
    bool isValid(int row, int col, std::vector<int>& colArr) {
        for (int i = 0; i < row; i++) {
            if (colArr[i] == col)
                return false;
            
            if (i + colArr[i] == row + col || i-colArr[i] == row-col)
                return false;
        }
        
        return true;
    }
    
    void solveNQueens(int row, std::vector<int>& colArr, int n,
std::vector<std::vector<std::string>>& output) {
        
        if (row == n) {
            std::vector<std::string> ans;
            for (int i = 0; i < n; i++) {
                std::string temp;
                for (int j = 0; j < n; j++) {
                    if (colArr[i] == j) {
                        temp += 'Q';
                    } else {
                        temp += '.';
                    }
                }
                ans.push_back(temp);
            }
            
            output.push_back(ans);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if(isValid(row, i, colArr)) {
                colArr[row] = i;
                solveNQueens(row+1, colArr, n, output);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> output;
        std::vector<int> colArr (n, 0);
        solveNQueens(0, colArr, n, output);
        return output;
    }
};
