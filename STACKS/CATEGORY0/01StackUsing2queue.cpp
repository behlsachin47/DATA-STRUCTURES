
        else if (q1.empty()) {
            while (q2.size() != 1) {
                q1.front(q2.front());
                q2.pop();
            }
            int ans = q2.front();
            q2.pop();
            return ans;
        }