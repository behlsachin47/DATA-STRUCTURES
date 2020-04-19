
typedef long long ll;
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        std::vector<double> ans (5, 10000.0);
        
        ll n = 0;
        ll totalSum = 0;
        ll highestFreq = 0;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == 0)
                continue;
            n += count[i];
            totalSum += count[i]*i;

            //min
            if (ans[0] > 255) {
                ans[0] = i;
            }
            //max
            ans[1] = i;
            
            //mode
            if (highestFreq < count[i]) {
                highestFreq = count[i];
                ans[4] = i;
            }
        }
        
        //mean
        ans[2] = (double)totalSum/n;
        
        int first = -1;
        int second = -1;
        bool flag1 = 1;
        bool flag2 = 0;
        if (n % 2 == 0) {
            first = n/2;
            second = first+1;
            flag2 = 1;
        } else {
            first = n/2;
            first++;
        }
        
        
        int currCount = 0;
        for (int i = 0; i <= 255; i++) {
            currCount += count[i];
            if (currCount >= first && flag1) {
                flag1 = false;
                ans[3] = i;
            }
            
            if (currCount >= second && flag2) {
                flag2 = 0;
                ans[3] += i;
                ans[3] /= 2;
            }
            
            if (!flag1 && !flag2)
                break;
        }
        
        
        return ans;
        
        
        
        
    }
};