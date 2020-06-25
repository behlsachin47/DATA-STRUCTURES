void solve(int sumLeft, int index, std::vector<int>& iter, std::vector<int>&
input, std::vector<std::vector<int>>& output) {
    if (sumLeft == 0) {
        output.push_back(iter);
        return;
    } else if (index > input.size()) {
        return;
    }
    
    
    for (int i = index; i < input.size(); i++) {
        if (sumLeft >= input[i]) {
            iter.push_back(input[i]);
            solve(sumLeft- input[i], i, iter, input, output);
            iter.pop_back();
            
        } else {
            return;
        }
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    std::sort(A.begin(), A.end());
    auto lastElemIterator = std::unique(A.begin(), A.end());
    int newSize = std::distance(A.begin(), lastElemIterator);
    A.resize(newSize);
    std::vector<int> iter;
    std::vector<std::vector<int> > output;
    solve(B, 0, iter, A, output);
    return output;
}



/* TIME COMPLEXITY ??
 * (2^(T+N)) * K (AVERAGE LENGTH OF ANS)
 * */

void solve(std::vector<int>& A, int sumLeft, int index, std::vector<int>& path,
std::vector<std::vector<int>>& output)
{
    if (sumLeft < 0) {
        return;
    } else if (sumLeft == 0) {
        output.push_back(path);
        return;
    }
    
    if (index == A.size()) {
        return;
    } 
    
    path.push_back(A[index]);
    solve(A, sumLeft-A[index], index, path, output);
    path.pop_back();
    solve(A, sumLeft, index+1, path, output);
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    std::sort(A.begin(), A.end());
    A.resize(std::distance(A.begin(), (std::unique(A.begin(), A.end()))));
    std::vector<std::vector<int>> output;
    std::vector<int> path;
    
    solve(A, B, 0, path,output);
    return output;
}



