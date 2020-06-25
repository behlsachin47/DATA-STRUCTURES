class Solution {
public:
    
    void generateAll(int n, int currElem, std::vector<int>& iter,
std::vector<std::vector<int>>& output, int k) {
        if (n == 0 && k == 0) {
            output.push_back(iter);
            return;
        } else if (n == 0) {
            return;
        } else if (k == 0) {
            return;
        }
        
        if (currElem > 9 || n < currElem) {
            return;
        }
        
        generateAll(n, currElem+1, iter, output, k);
        iter.push_back(currElem);
        generateAll(n-currElem, currElem+1, iter, output, k-1);
        iter.pop_back();
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> output;
        std::vector<int> iter;
        generateAll (n, 1, iter, output, k);
        return output;
    }
};
