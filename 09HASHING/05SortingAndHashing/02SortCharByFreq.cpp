//////////////////////////////O(n) way :P

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        int maxFreq = 1;
        std::unordered_map<char, int> freqArr;
        std::string ans;
        ans.reserve(n);
        
        for (int i = 0; i < s.size(); i++) {
            if (freqArr.count(s[i])) {
                freqArr[s[i]]++;
                maxFreq = std::max(maxFreq, freqArr[s[i]]);
            } else {
                freqArr.insert({s[i], 1});
            }
        }
        
        
        
        std::vector<std::vector<char> > buckets(maxFreq+1, std::vector<char>{});
        for (auto iter = freqArr.begin(); iter != freqArr.end(); iter++) {
            int index = iter->second;
            char tempChar = iter->first;
            
            buckets[index].push_back(tempChar);
        }
        
        for (int i = buckets.size()-1; i >= 0; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                char charTemp = buckets[i][j];
                //push the charTemp by i freq
                ans.append(i, charTemp);
            }
        
        }
        
        return ans;
    }
    
};
////////////////////////////////////////
















std::unordered_map<char, int> charFreqMap;
bool customCompare(const char& a, const char& b)  {
    if (charFreqMap[a] > charFreqMap[b]) 
        return 1;
    else if (charFreqMap[a] < charFreqMap[b]) {
        return 0;
    } else {
        return a < b;
    }
}   

class Solution {
public:
    
    string frequencySort(string s) {
        charFreqMap = std::unordered_map<char, int> ();
        for (int i = 0; i < s.size(); i++) {
            if (charFreqMap.count(s[i])) {
                charFreqMap[s[i]]++;
            } else {
                charFreqMap.insert({s[i], 1});
            }
        }
        
        std::sort(s.begin(), s.end(), customCompare);
        
        return s;
    }
};