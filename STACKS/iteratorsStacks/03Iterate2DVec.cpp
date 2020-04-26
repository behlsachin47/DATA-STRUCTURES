typedef std::vector<int>::iterator it;
class Vector2D {
    std::stack<std::pair<it, it>> st1;
public:
    Vector2D(vector<vector<int>>& v) {
        for (int i = v.size()-1; i >= 0; i--) {
            if (v[i].begin() == v[i].end())
                continue;
            st1.push(std::make_pair(v[i].begin(), v[i].end()));
        }
    }
    
    int next() {
        auto curr = st1.top();
        int ans = *(curr.first);

        iterateForward();
        return ans;
    }
    
    bool hasNext() {
        return (st1.size() > 0);
    
    }
    
    void iterateForward() {
       // std::cout << st1.size() << std::endl;
        while (!st1.empty()) {
            auto curr = st1.top();
            st1.pop();
            if (curr.first+1 == curr.second) 
                return;
            else {
                st1.push(std::make_pair(curr.first+1, curr.second));
                return;
            }
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */