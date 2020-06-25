class TimeMap {
public:
    /** Initialize your data structure here. */
    std::unordered_map<std::string, std::map<int, std::string>> mapKeyTimeStampToValue;
    TimeMap() {
        mapKeyTimeStampToValue = std::unordered_map<std::string, std::map<int, std::string>> ();
    }
    
    void set(string key, string value, int timestamp) {
        mapKeyTimeStampToValue[key][timestamp] = value;
    }
    
    
    string get(string key, int timestamp) {
        if (mapKeyTimeStampToValue.count(key) == 0)
            return std::string("");
        
        auto iter = mapKeyTimeStampToValue[key].upper_bound(timestamp);
        if (iter == mapKeyTimeStampToValue[key].begin()) {
            return std::string("");
        } else {
            auto prevIter = std::prev(iter);
            return prevIter->second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */