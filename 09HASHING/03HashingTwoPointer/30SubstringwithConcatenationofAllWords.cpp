class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::unordered_map<std::string, int> mapWordsFreq;
        std::vector<int> prefixHashValue (s.size(), 0);
        int hashValueAllwords = 0;
        std::vector<int> output;
        for (int i = 0; i < words.size(); i++) {
            if (mapWordsFreq.count(words[i])) {
                mapWordsFreq[words[i]]++;
            } else {
                mapWordsFreq.insert({words[i], 1});
            }
            
            for (int j = 0; j < words[i].size(); j++) {
                hashValueAllwords ^= words[i][j];
            }
        }
        
        int n = s.size();
        int k = words.size();
        if (n == 0 || k == 0)
            return output;
        int m = words[0].size();
        prefixHashValue[0] = s[0];
        for (int i = 1; i < s.size(); i++) {
            prefixHashValue[i] = prefixHashValue[i-1]^s[i];
        }
        
        if (n < m*k)
            return output;
        
        for (int st = 0; st <= n-m*k; st++ ) {
            int end = st + m*k;
            //push these words to a map
            //std::cout << st << " " << end << " " << n-m << std::endl;
            
            //check hasvalues from st to end and compare
            int stringHash = prefixHashValue[end-1];
            if (st != 0) {
                stringHash ^= prefixHashValue[st-1];
            }
            
            if (stringHash != hashValueAllwords)
                continue;
            std::unordered_map<std::string, int> iterMap;
            int count = 0;
            for (int i = st; i < end; i += m) {
                std::string temp = s.substr(i, m);
                //std::cout << temp << " " ; 
                if (mapWordsFreq.count(temp) == 0) {
                    break;
                }
                if (iterMap[temp] == mapWordsFreq[temp]) {
                    break;
                } else if (iterMap.count(temp)) {
                    iterMap[temp]++;
                    count++;
                } else {
                    iterMap.insert({temp, 1});
                    count++;
                }
            }
            //std::cout << count << std::endl;
            if (count == k) {
                output.push_back(st);
               
            }
        }
        return output;
    }
};