typedef std::pair<int, int> iPair;
vector<int> Solution::equal(vector<int> &A) {
    std::vector<int> result;
    std::map<int, iPair> mapSumToPairs;
    
    for (int i = 0; i < A.size(); i++) {
        for (int j = i+1; j < A.size(); j++) {
            
            
            int currSum = A[i] + A[j];
            if (mapSumToPairs.count(currSum)) {
                
                    iPair temp = mapSumToPairs[currSum];
                    if (temp.second != j && temp.first != j && temp.first != i && temp.second != i) {
                        std::vector<int>tempResult = {temp.first, temp.second, i , j};
                        if (result.size() == 0) {
                            result = tempResult;
                        } else if (result > tempResult) {
                            result = tempResult;
                        }
                        
                    }
            
                //mapSumToPairs[currSum].push_back(std::make_pair(i, j));
            } else {
                mapSumToPairs.insert({currSum, std::make_pair(i, j)});
            }
        }
    }
    return result;
    
}
