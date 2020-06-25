
std::string generateNext(std::string str) {
    for (int i = str.size()-1; i >= 0; i--) {
        if (str[i] == '3') {
            str[i] = '1';
        } else {
            if (str[i] == '2') {
                str[i] = '3';
            } else {
                str[i] = '2';
            }
            return str;
        }
    }
    return "1" + str;
}
vector<int> Solution::solve(int A) {
    
    std::vector<int> output;
    if (A== 0) {
        return output;
    } else if (A== 1) {
        output.push_back(1);
        return output;
    } else if (A== 2) {
        output.insert(output.end(), {1, 2});
        return output;
    }
    
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    int index = 3;
    while (index < A) {
        int front = q.front();
        output.push_back(front);
        q.pop();
        int element1 = front*10 + 1;
        q.push(element1);
        index++;
        if (index == A) {
            break;
        }
        
        int element2 = front*10 + 2;
        q.push(element2);
        index++;
        
        if (index == A) {
            break;
        }
        
        int element3 = front*10 + 3;
        q.push(element3);
        index++;
        
    }
    
    
    while (q.empty() == false) {
        output.push_back(q.front());
        q.pop();
    }
    
    return output;
    
    
    
}
