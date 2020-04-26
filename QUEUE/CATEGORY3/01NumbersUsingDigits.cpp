typedef long long ll;
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
         int result = 0;
        std::queue<ll> q;
        if (D.size() == 0)
            return result;
        for (int i = 0; i < D.size(); i++) {
            int num = D[i][0]-'0';
            q.push(num);
        }
        bool flag = true;
        
        while (q.size()) {
            ll curr = q.front();
            if (curr <= N) {
                result++;
            } else {
                break;
            }
            q.pop();
            if (flag)
            for (int i = 0; i < D.size(); i++) {
                int num = D[i][0] - '0';
                ll next = curr*10 + num;
                if (next > N)
                    flag = false;
                else
                    q.push(curr*10 + num);
            }
        }
        return result;
    }
};