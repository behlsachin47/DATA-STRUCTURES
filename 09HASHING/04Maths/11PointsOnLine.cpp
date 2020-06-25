typedef std::pair<int, int> iPair;
int calculateGcd(int a, int b) {
    if (b == 0)
        return a;
    else {
        return calculateGcd(b, a%b);
    }
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};
bool debug = 0;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        if (points.size() <= 2) {
            return points.size();
        }
        
        std::unordered_map<iPair, int, pair_hash> pointToFreqMap;
        for (int i = 0; i < points.size(); i++) {
            iPair temp = std::make_pair(points[i][0], points[i][1]);
            if (pointToFreqMap.count(temp)) {
                pointToFreqMap[temp]++;
            } else {
                pointToFreqMap.insert({temp, 1});
            }
        }
        
        if (pointToFreqMap.size() == 1) {
            return pointToFreqMap.begin()->second;
        }
        
        for (auto iter1 = pointToFreqMap.begin(); iter1 != pointToFreqMap.end(); iter1++) {
            iPair pt1 = iter1->first;
            int freq1 = iter1->second;
            if (debug) {
                std::cout << pt1.first << " " << pt1.second << std::endl;
            }
            std::unordered_map<iPair, int, pair_hash> slopeToFreqMap;
            
            for (auto iter2 = iter1; iter2 != pointToFreqMap.end(); iter2++) {
                
                if(iter1 == iter2)
                    continue;
                iPair pt2 = iter2->first;
                int freq2 = iter2->second;
                iPair slope;
                int slopeDenom = pt2.second - pt1.second;
                int slopeNum = pt2.first - pt1.first;
                
                if (slopeDenom == 0) {
                    slopeNum = INT_MAX;
                } else if (slopeNum == 0) {
                    slopeDenom = INT_MAX;
                } else {
                    //std::cout << "sachin\n";
                    bool isNeg = false;
                    if (slopeDenom < 0) {
                        isNeg = !isNeg;
                        slopeDenom *= -1;
                    }
                    
                    if (slopeNum < 0) {
                        isNeg = !isNeg;
                        slopeNum *= -1;
                    }
                    
                    int gcd = calculateGcd(slopeDenom, slopeNum);
                    slopeNum /= gcd;
                    slopeDenom /= gcd;
                    
                    if (isNeg) {
                        slopeDenom *= -1;
                    }
                }   
                
                slope = std::make_pair(slopeDenom, slopeNum);
                if (debug) {
                  std::cout << "\t" << pt2.first << " " << pt2.second << std::endl;
                  std::cout << "\t" << slope.first << " " << slope.second << std::endl;
                }
                    if (slopeToFreqMap.count(slope)) {
                        slopeToFreqMap[slope] += freq2;
                    } else {
                        slopeToFreqMap.insert({slope, freq1 + freq2});
                    }
                    
                    ans = std::max(slopeToFreqMap[slope], ans);
                    
                
                
            }
        }
        return ans;

        
    }
};

















typedef std::pair<int, int> iPair;
int calculateGcd(int a, int b) {
    if (b == 0)
        return a;
    else {
        return calculateGcd(b, a%b);
    }
}
bool debug = 0;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        if (points.size() <= 2) {
            return points.size();
        }
        
        std::map<iPair, int> pointToFreqMap;
        for (int i = 0; i < points.size(); i++) {
            iPair temp = std::make_pair(points[i][0], points[i][1]);
            if (pointToFreqMap.count(temp)) {
                pointToFreqMap[temp]++;
            } else {
                pointToFreqMap.insert({temp, 1});
            }
        }
        
        if (pointToFreqMap.size() == 1) {
            return pointToFreqMap.begin()->second;
        }
        
        for (auto iter1 = pointToFreqMap.begin(); iter1 != pointToFreqMap.end(); iter1++) {
            iPair pt1 = iter1->first;
            int freq1 = iter1->second;
            if (debug) {
                std::cout << pt1.first << " " << pt1.second << std::endl;
            }
            std::map<iPair, int> slopeToFreqMap;
            
            for (auto iter2 = iter1; iter2 != pointToFreqMap.end(); iter2++) {
                
                if(iter1 == iter2)
                    continue;
                iPair pt2 = iter2->first;
                int freq2 = iter2->second;
                iPair slope;
                int slopeDenom = pt2.second - pt1.second;
                int slopeNum = pt2.first - pt1.first;
                
                if (slopeDenom == 0) {
                    slopeNum = INT_MAX;
                } else if (slopeNum == 0) {
                    slopeDenom = INT_MAX;
                } else {
                    //std::cout << "sachin\n";
                    bool isNeg = false;
                    if (slopeDenom < 0) {
                        isNeg = !isNeg;
                        slopeDenom *= -1;
                    }
                    
                    if (slopeNum < 0) {
                        isNeg = !isNeg;
                        slopeNum *= -1;
                    }
                    
                    int gcd = calculateGcd(slopeDenom, slopeNum);
                    slopeNum /= gcd;
                    slopeDenom /= gcd;
                    
                    if (isNeg) {
                        slopeDenom *= -1;
                    }
                }   
                
                slope = std::make_pair(slopeDenom, slopeNum);
                if (debug) {
                  std::cout << "\t" << pt2.first << " " << pt2.second << std::endl;
                  std::cout << "\t" << slope.first << " " << slope.second << std::endl;
                }
                    if (slopeToFreqMap.count(slope)) {
                        slopeToFreqMap[slope] += freq2;
                    } else {
                        slopeToFreqMap.insert({slope, freq1 + freq2});
                    }
                    
                    ans = std::max(slopeToFreqMap[slope], ans);
                    
                
                
            }
        }
        return ans;

        
    }
};