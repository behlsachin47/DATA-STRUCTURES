///////////////////////APPROACH 1 ///////////////////////

typedef std::pair<int, int> iPair;

bool myCompare(const iPair& p1, const iPair& p2) {
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    
    return p1.first < p2.first;
}


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0;
        std::vector<iPair> list;
        for (int i = 0; i < intervals.size(); i++) {
            list.push_back(std::make_pair(intervals[i][0], 0));
            list.push_back(std::make_pair(intervals[i][1], 1));
        }
        std::sort(list.begin(), list.end(), myCompare);
        
        int currMeeting = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].second == 0)
                currMeeting++;
            else
                currMeeting--;
            
            ans = std::max(ans, currMeeting);
            
        }
        
        return ans;
        
    }
};



//////////////APPROACH 2 ////////
//NOTICE HOW REVERSE COMPARATOR IS DEFINED FOR HEAPS;
//
//


typedef std::pair<int, int> iPair;
bool myCompare(const iPair& p1, const iPair& p2) {
    
    return p1.second >= p2.second;
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0;
        if (intervals.size() == 0)
            return ans;
        
        std::sort(intervals.begin(), intervals.end());
        /*for (int i = 0; intervals.size(); i++) {
            std::cout << intervals[i][0] << "," << intervals[i][1] << " ";
        }*/
        
        std::priority_queue<iPair, std::vector<iPair>, bool (*)(const iPair&, const iPair&)> pq(myCompare);
        pq.push(std::make_pair(intervals[0][0], intervals[0][1]));
        ans = 1;
        
        for (int i = 1; i < intervals.size(); i++) {
            //check min heap top
            while (!pq.empty()) {
                std::cout << pq.top().second << std::endl;
                if (pq.top().second <= intervals[i][0])
                    pq.pop();
                else
                    break;
            }
            pq.push(std::make_pair(intervals[i][0], intervals[i][1]));
            
            ans = std::max(ans, (int)pq.size());
        }
        return ans;
    }
};



