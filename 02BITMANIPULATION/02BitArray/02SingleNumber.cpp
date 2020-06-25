/* There is an array with n numbers. All numbers appear thrice except one
 * number. Find the number that appears once.
 *
 *  we can look at all the 32 bits; and count those and take mod 3
 *
 *
 *
 * */


typedef long long ll;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;        
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] >> i) & 1) {
                    count++;
                }
            }
            if (count % 3) {
                result |= (1 << i);
            }
        }
        
        
        return result;
    }
};
