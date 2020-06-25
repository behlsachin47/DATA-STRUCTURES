//JUST SMALLER CHARACTER
class Solution {
public:
    void print(std::vector<int>& vec) {
        for (int i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
    }
    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length())
            return std::vector<int> {};
        std::vector<int>mapP (26, 0);
        std::vector<int>mapS (26, 0);
        std::vector<int> ansVec;

        for (int i = 0; i < p.size(); i++) {
            mapP[p[i]-'a']++;
        }
        
        for (int j = 0; j < p.size(); j++) {
            mapS[s[j]-'a']++;
        }
        
        if (mapP == mapS)
            ansVec.push_back(0);
        
        for (int i = p.size(); i < s.size(); i++) {
            mapS[s[i-p.size()]-'a']--;
            mapS[s[i]-'a']++;
            //print(mapP);
            //print(mapS);
            //std::cout << i << std::endl;
            if (mapP == mapS)
                ansVec.push_back(i-p.size()+1);
        }
        return ansVec;
    }
};












class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::unordered_map<char, int> mapCharFreq;
        for (int i = 0; i < p.size(); i++) {
            if (mapCharFreq.count(p[i])) {
                mapCharFreq[p[i]]++;
            } else {
                mapCharFreq.insert({p[i], 1});
            }
        }
        std::unordered_map<char, int> iterCharFreqMap;
        std::vector<int> ansVec;
        int currSt = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (mapCharFreq.count(s[i]) == 0) {
                iterCharFreqMap = std::unordered_map<char, int>();
                currSt = i+1;
                continue;
            }
            
            //s[i] is present in string p
            if (iterCharFreqMap.count(s[i])) {
                //overshoot the freq of s[i] in p
                if (iterCharFreqMap[s[i]] == mapCharFreq[s[i]]) {
                    //adjust currSt
                    for (; s[currSt] != s[i]; currSt++) {
                        iterCharFreqMap[s[currSt]]--;
                        
                        //if (iterCharFreqMap[s[currSt]] == 0)
                            //iterCharFreqMap.erase(s[currSt]);
                    }
                    currSt++;
                    continue;
                } else {
                    iterCharFreqMap[s[i]]++;
                }
            } else {
                iterCharFreqMap[s[i]] = 1;
            }
            
            //check if length matches
            if (i-currSt+1 == p.length()) {
                ansVec.push_back(currSt);
                iterCharFreqMap[s[currSt]]--;
               // if (iterCharFreqMap[s[currSt]] == 0)
                  //  iterCharFreqMap.erase(s[currSt]);
                
                currSt++;
            }
            
        }
        return ansVec;
    }
};