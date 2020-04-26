typedef std::pair<std::vector<int>::iterator, std::vector<int>::iterator> iterPair;

class ZigzagIterator {
    std::queue<iterPair> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end())
            q.push(std::make_pair(v1.begin(), v1.end()));
        
        if (v2.begin() != v2.end())
            q.push(std::make_pair(v2.begin(), v2.end()));
    }

    int next() {
        iterPair curr = q.front();
        q.pop();
        int ans = *(curr.first);
        
        auto iter = curr.first;
        iter++;
        
        if (iter != curr.second) {
            q.push(std::make_pair(iter, curr.second));
        }
        
        return ans;
    }

    bool hasNext() {
        if (q.empty())
            return false;
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */