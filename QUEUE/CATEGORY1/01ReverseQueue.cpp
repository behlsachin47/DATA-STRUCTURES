//using stack

#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::queue<int> q;
    q.push(100);
    q.push(200);
    q.push(300);
    q.push(400);

    std::stack<int> s;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        s.push(top);
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        q.push(top);
    }

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }

    return 0;
}