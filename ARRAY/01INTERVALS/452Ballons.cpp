typedef std::pair<int, int> iPair;
bool myCompare(const iPair& a, const iPair& b) {
    return a.second >= b.second;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 0;
        std::sort(points.begin(), points.end());
        std::priority_queue<iPair, std::vector<iPair>, bool(*)(const iPair&, const iPair&)> pq(myCompare); 
        
        int ans = 1;
        pq.push(std::make_pair(points[0][0], points[0][1]));
        
        for (int i = 1; i < points.size(); i++) {
            bool flag = 0;
            if (!pq.empty()) {
               // std::cout << pq.top().second << std::endl;
                if (pq.top().second < points[i][0]) {
                    //clear it
                    while (!pq.empty())
                        pq.pop();
                    flag = 1;
                } 
            }
            if (flag)
                ans++;
            pq.push(std::make_pair(points[i][0], points[i][1]));
        }
        
        return ans;
        
    }
};



////////////////////////APPROACH 2: GREEDY
/*
Greedy problems usually look like "Find minimum number of something to do something" or 
"Find maximum number of something to fit in some conditions", and typically propose an unsorted input.

The idea of greedy algorithm is to pick the locally optimal move at each step, that will lead to the globally optimal solution.
*/

typedef std::pair<int, int> iPair;
bool myCompare(const iPair& a, const iPair& b) {
    return a.second >= b.second;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 0;
        std::sort(points.begin(), points.end());
        int ans = 1;
        for (int i = 0; i < points.size()-1; i++) {
              if (points[i+1][0] >= points[i][0] && points[i+1][0] <= points[i][1]) {
                  points[i+1][1] = std::min(points[i][1], points[i+1][1]);
              } else {
                  ans++;
              }
        }
        return ans;
        
    }
};