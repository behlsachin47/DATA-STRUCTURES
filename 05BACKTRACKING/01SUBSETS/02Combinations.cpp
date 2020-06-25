void solve(int n, int r, int currElem, std::vector<int>& iter,
std::vector<std::vector<int>>& output) {
    if (iter.size() == r) {
        output.push_back(iter);
        return;
    } else if (currElem > n) {
        return;
    }
    
    for (int i = currElem; i <= n; i++) {
        iter.push_back(i);
        solve(n, r, i+1, iter, output);
        iter.pop_back();
    }
    
}
vector<vector<int> > Solution::combine(int A, int B) {
    std::vector<int> iter;
    std::vector<std::vector<int>> output;
    int elem = 1;
    
    solve(A, B, elem, iter, output);
    return output;
}

