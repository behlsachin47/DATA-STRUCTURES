
//484 find permutation

class Solution {
public:
    vector<int> findPermutation(string s);
};

vector<int> Solution::findPermutation(string A) {
    std::vector<int> res;
    for (int i = 0; i <= A.size(); i++) {
        res.push_back(i+1);
    }
    
    
    
   
    
    int i =0;
    for (int k = 0; k < A.size(); ) {
        if (A[k] == 'I') {
          
            k++;
            i = k; 
        } else {
            while (k < A.size() && A[k] == 'D') {
                k++;
            }
            std::reverse(res.begin()+i, res.begin()+k+1);
            i = k;
        }
    }
    
    return res;
}

