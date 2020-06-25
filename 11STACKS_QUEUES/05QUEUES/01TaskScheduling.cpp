int Solution::solve(vector<int> &A, vector<int> &B) {
    int answer = 0;
    std::queue<int> scheduleQueue;
    for (int i = 0; i < A.size(); i++) {
        scheduleQueue.push(A[i]);
    }
    
    int taskNum = 0;
    while (scheduleQueue.empty() == false) {
        while (scheduleQueue.front() != B[taskNum]) {
            int task = scheduleQueue.front();
            scheduleQueue.pop();
            scheduleQueue.push(task);
            answer++;
        }
        taskNum++;
        answer++;
        scheduleQueue.pop();
    }
    
    return answer;
}
