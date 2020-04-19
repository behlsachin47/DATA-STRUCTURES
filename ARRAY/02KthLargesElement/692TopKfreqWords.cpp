typedef std::pair<std::string, int> siPair;
bool myCompare(const siPair& p1, const siPair& p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    
    return p1.second > p2.second;
}

class Solution {
public:
    void swap( std::vector<siPair>& input, int pos1, int pos2) {
        if (pos1 != pos2) {
            siPair temp = input[pos1];
            input[pos1] = input[pos2];
            input[pos2] = temp;
        }
    }
    
    void quickSelect(std::vector<siPair>& input, int st, int end, int k) {
        if (st >= end)
            return;
        
        int randomInd = rand()%(end-st+1) + st;
        swap(input, end, randomInd);
        
        int divider = st;
        for (int i = st; i < end; i++) {
            if ((input[i].second > input[end].second) || ((input[i].second == input[end].second) && (input[i].first < input[end].first))) {
                //swap
                swap(input, divider, i);
                divider++;
            } 
        }
        
        swap(input, divider, end);
        if (divider == k)
            return;
        else if (divider > k) 
            quickSelect(input, st, divider-1, k);
        else
            quickSelect(input, divider+1, end, k);
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
    
        std::unordered_map<std::string, int> mapWords;
        std::vector<std::string> res;
        std::vector<siPair> input;


        for (int i = 0; i < words.size(); i++) {
            if (mapWords.count(words[i])) {
                mapWords[words[i]]++;
            } else {
                mapWords.insert({words[i], 1});
            }
        }
        
        for (auto iter = mapWords.begin(); iter != mapWords.end(); iter++) {
            input.push_back(*iter);
        }
        
        if (k > input.size() || input.size() == 0 )
            return res;
        
        quickSelect(input, 0, input.size()-1, k-1);  
        std::sort(input.begin(), input.begin()+k, myCompare);
        for (int i = 0; i < k; i++)
            res.push_back(input[i].first);
        
        
        return res;
        
    }
};