vector<int> Solution::solve(vector<vector<int> > &A) {
    int maxFreq = 0;
    std::unordered_map<int, int> valueFreqMap;
    std::unordered_map<int, std::stack<int> > freqValueStack;
    std::vector<int> output;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i][0] == 1) {
            int element = A[i][1];
            if (valueFreqMap.count(element)) {
                valueFreqMap[element]++;
                int freq = valueFreqMap[element];
                maxFreq = std::max(maxFreq, freq);
                
                if (freqValueStack.count(freq)) {
                    freqValueStack[freq].push(element);
                } else {
                    freqValueStack.insert({freq, std::stack<int> ()});
                    freqValueStack[freq].push(element);
                }
            } else {
                valueFreqMap.insert({element, 1});
                int freq = valueFreqMap[element];
                maxFreq = std::max(freq, maxFreq);
                
                if (freqValueStack.count(freq)) {
                    freqValueStack[freq].push(element);
                } else {
                    freqValueStack.insert({freq, std::stack<int> ()});
                    freqValueStack[freq].push(element);
                }
            }
            
            output.push_back(-1);
            
        } else {
            int element = freqValueStack[maxFreq].top();
            freqValueStack[maxFreq].pop();
            valueFreqMap[element]--;
            
            if (freqValueStack[maxFreq].size() == 0) {
                maxFreq--;
            }
            
            output.push_back(element);
        }
    }
    
    return output;
    
}
