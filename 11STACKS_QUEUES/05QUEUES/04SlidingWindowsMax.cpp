vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    //first push the firstB elments 
    std::vector<int> output;
    std::deque<int> dq;
    
    for (int i = 0; i < A.size() && i < B; i++) {
        if (dq.empty()) {
            dq.push_back(i);
        } else {
            if (A[dq.back()] <= A[i]) {
                while (dq.empty() == false && A[dq.back()] <= A[i]) {
                  dq.pop_back();
                }
                dq.push_back(i);
            } else {
                dq.push_back(i);
            }
        }
    }
    output.push_back(A[dq.front()]);
    for (int i = B; i < A.size(); i++) {
        //remove the first element if it is oput of curr window and then push this new elment
        if (dq.front() == i-B) {
            dq.pop_front();
        }
        if (dq.empty()) {
            dq.push_back(i);
        } else {
        
        if (A[dq.back()] <= A[i]) {
            while (dq.empty() == false && A[dq.back()] <= A[i]) {
              dq.pop_back();
            }
            dq.push_back(i);
        } else {
            dq.push_back(i);
        }
        }
        output.push_back(A[dq.front()]);
        
        
        
        
    }
    return output;
}
