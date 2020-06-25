//juust check for adjacent words
std::unordered_map<char, int> mapCharToOrder;

bool customCompare(const std::string& first, const std::string& second) {
    int i = 0;
    int n1 = first.size();
    int n2 = second.size();
    
    for (; i < std::min(n1, n2); i++) {
        int order1 = mapCharToOrder[first[i]];
        int order2 = mapCharToOrder[second[i]];
        
        if (order1 == order2) {
            continue;
        } else if (order1 > order2) {
            return false;
        } else {
            return true;
        }
    }
    
    if (i == n1) {
        return true;
    } else {
        return false;
    }
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        mapCharToOrder = std::unordered_map<char, int> ();

        for (int i = 0; i < order.size(); i++) {
            mapCharToOrder.insert({order[i], i});
        }
        
        for (int i = 0; i < words.size()-1; i++) {
            if (customCompare(words[i], words[i+1]) == 0) {
                return 0;
            }
        }        
        return 1;
    }
};














std::unordered_map<char, int> mapCharToOrder;

bool customCompare(const std::string& first, const std::string& second) {
    int i = 0;
    int n1 = first.size();
    int n2 = second.size();
    
    for (; i < std::min(n1, n2); i++) {
        int order1 = mapCharToOrder[first[i]];
        int order2 = mapCharToOrder[second[i]];
        
        if (order1 == order2) {
            continue;
        } else if (order1 > order2) {
            return false;
        } else {
            return true;
        }
    }
    
    if (i == n1) {
        return true;
    } else {
        return false;
    }
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        mapCharToOrder = std::unordered_map<char, int> ();

        for (int i = 0; i < order.size(); i++) {
            mapCharToOrder.insert({order[i], i});
        }
        
        std::vector<std::string> temp;
        temp = words;
        
        std::sort(temp.begin(), temp.end(), customCompare);
        
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] != words[i])
                return 0;
        }
        
        return 1;
    }
};








class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int maxSize = 0;
        for (int i = 0; i < words.size(); i++) {
            maxSize = std::max(maxSize, (int)words[i].size());
        }
        
        if (maxSize == 0) {
            return 1;
        }
        
        std::vector<std::string> temp = words;
        
        
        for (int i = maxSize-1; i >= 0; i--) {
        
            std::unordered_map<char, std::vector<std::string>> buckets;
            buckets.insert({'\0', std::vector<std::string> {}});
            //sort via ith character
            
            for (int j = 0; j < words.size(); j++) {
                if (words[j].size()-1 >= i) {
                    char ch = words[j][i];
                    if (buckets.count(ch)) {
                        buckets[ch].push_back(words[j]);
                    } else {
                        buckets.insert({ch, std::vector<std::string>{} });
                        buckets[ch].push_back(words[j]);
                    }
                } else {
                    buckets['\0'].push_back(words[j]);
                }
            }
            
            int count = 0;
            //first null character
            for (int k = 0; k < buckets['\0'].size(); k++) 
                words[count++] = buckets['\0'][k];
            
            for (int j = 0; j < order.size(); j++ ) {
                char key = order[j];
                if (buckets.count(key)) {
                    for (int k = 0; k < buckets[key].size(); k++) {
                        words[count++] = buckets[key][k];            
                    }
                }
            }
        }
        
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] != words[i])
                return 0;
        }
        
        return 1;
    }
};