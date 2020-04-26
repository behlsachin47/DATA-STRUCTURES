// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    
    int findCelebrity(vector<int>& arr_celeb, int m) {
        if (arr_celeb.size() == 0)
            return -1;
        else if (arr_celeb.size() == 1) {
            //if this knows everyone
            int celeb = arr_celeb[0];
            for (int i = 0; i < m; i++) {
                if (i == celeb)
                    continue;
                
                if (knows(celeb, i))
                    return -1;
                
                if (!knows(i, celeb))
                    return -1;
                
            }
            return celeb;
        }
            
        int n = arr_celeb.size();
        //lets focus on last two
        int person1 = arr_celeb[n-1];
        int person2 = arr_celeb[n-2];
        
        arr_celeb.pop_back();
        arr_celeb.pop_back();
        
        if (knows(person1, person2) == 1) {
            if (!knows(person2, person1)) {
                arr_celeb.push_back(person2);
            }
        } else {
            if (knows(person2, person1)) {
                arr_celeb.push_back(person1);
            }
        }
        
        return findCelebrity(arr_celeb, m);
    }
    
    int findCelebrity(int n) {
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back(i);
        }
        
        return findCelebrity(arr,n);
    }
};