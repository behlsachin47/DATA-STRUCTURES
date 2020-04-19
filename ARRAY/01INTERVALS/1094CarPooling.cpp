bool myCompare(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    return vec1[1] < vec2[1];
}

bool myCompare1(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    return vec1[2] > vec2[2];
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if (trips.size() == 0)
            return 1;
        
        std::sort(trips.begin(), trips.end(), myCompare);
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, bool(*)(const std::vector<int>&, const std::vector<int>&) > pq(myCompare1);
        
        pq.push(trips[0]);
        int currSeating = pq.top().at(0);
        if (currSeating > capacity)
            return 0;
        for (int i = 1; i < trips.size(); i++) {
            while (!pq.empty()) {
               // std::cout << pq.top().at(2) << std::endl;
                if (pq.top().at(2) <= trips[i][1]) {
                    currSeating -= pq.top().at(0);
                    pq.pop();
                } else 
                    break;
            }
            currSeating += trips[i][0];
            pq.push(trips[i]);
            
            if (currSeating > capacity)
                return 0;
        }
        
        return 1;
    }
};