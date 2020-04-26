queue<ll> modifyQueue(queue<ll> q, int k)
{
    //keep the first k elements in the stack 
    stack<int> s1;
    queue<int> res;
    
    for (int i = 0; i < k; i++) {
        int num = q.front();
        q.pop();
        s1.push(num);
    }
    
    for (int i = 0; i < k; i++) {
        int num = s1.top();
        s1.pop();
        res.push(num);
    }
    
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        res.push(num);
    }
    return res;
    
}