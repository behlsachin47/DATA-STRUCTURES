class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //method1: counting sort
        if (arr1.size() <= 1)
            return arr1;
        
        std::vector<int> ans;
        
        //initialize the freq map
        std::map<int, int> freqArr;
        
        //fill the freq arr 
        for (int i = 0; i < arr1.size(); i++) {
            if (freqArr.count(arr1[i])) {
                freqArr[arr1[i]]++;
            } else {
                freqArr.insert({arr1[i], 1});
            }
        }
        
        //sort the elements as per arr
        for (int i = 0; i < arr2.size(); i++) {
            int freq = freqArr[arr2[i]];
            for (int j = 0; j < freq; j++) {
                ans.push_back(arr2[i]);
            }
            freqArr.erase(arr2[i]);
        }
        
        for (auto iter = freqArr.begin(); iter != freqArr.end(); iter++) {
            int freq = iter->second;
            int element = iter->first;
            
            for (int i = 0; i < freq; i++) {
                ans.push_back(element);
            }
        }
        
        return ans;
    }
};






//////////////////////CUSTOM COMPARATOR


std::unordered_map<int, int> mapElementPriority;

    bool compare(const int& num1, const int& num2) {
        if(mapElementPriority.count(num1) && mapElementPriority.count(num2)) {
            if (mapElementPriority[num1] < mapElementPriority[num2]) {
                return 1;
            } else {
                return 0;
            }
        } else if (mapElementPriority.count(num1)) {
            return 1;
        } else if (mapElementPriority.count(num2)) {
            return 0;
        } else {
            return num1 < num2;
        }
    }
class Solution {
public:
    
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {    
        
        int priority = 0;
        mapElementPriority = std::unordered_map<int, int> ();
        
        for (int i = 0; i < arr2.size(); i++) {
            mapElementPriority.insert({arr2[i], priority++});
        }
        
        std::sort(arr1.begin(), arr1.end(), compare);
        
        return arr1;
        
    }
};