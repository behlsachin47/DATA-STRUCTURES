typedef std::pair<float, std::vector<int>> fvPair;
class Solution {
public:
    
    float calculateDistance(std::vector<int>& point) {
        float dist = point[0]*point[0] + point[1]*point[1];
        return dist;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::vector<std::vector<int>> res;

        if (points.size() == 0)
            return res;
        std::priority_queue<fvPair> pq;
        for (int i = 0; i < K; i++) {
            float dist = calculateDistance(points[i]);
            pq.push(std::make_pair(dist, points[i]));
        }
        
        for (int i = K; i < points.size(); i++) {
            float dist = calculateDistance(points[i]);
            if (pq.top().first > dist) {
                pq.pop();
                pq.push(std::make_pair(dist, points[i]));
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};



//////////////////////O(N) approach :: quickselect works here as well . Think babe

class Solution {
public:
    int distance(vector<int>& points) {
        return points[0]*points[0] + points[1]*points[1];
    }
    bool quickSelect(std::vector<std::vector<int>>& points, int st, int end, int k) {
        if (st > end) {
            return false;
        } else if (st == end) {
            return true;
        }
        
        int pivot = rand()%(end-st) + st;
        std::vector<int> temp = points[pivot];
        points[pivot] = points[end];
        points[end] = temp;
        
        int divider = st;
        int distancePivot = distance(points[end]);
        for (int i = st; i < end; i++) {
            if (distance(points[i]) < distancePivot) {
                std::vector<int> temp = points[i];
                points[i] = points[divider];
                points[divider] = temp;
                
                divider++;
            }           
        }
        temp = points[divider];
        points[divider] = points[end];
        points[end] = temp;
        
        if (divider == k) {
            return true;
        } else if (divider > k) {
            return quickSelect(points, st, divider-1, k);
        } else {
            return quickSelect(points, divider+1, end, k);   
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        std::vector<std::vector<int>> res;
        
        if (quickSelect(points, 0, points.size()-1, k-1)) {
            for (int i = 0; i < k; i++)
                res.push_back(points[i]);
        }
            
        return res;
    }
};