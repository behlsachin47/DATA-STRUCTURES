/* Given a sorted array with distinct integers. Find the number of pairs that
 * add to the given sum k.
 *
 *
 * */


int countPairs(const std::vector<int>& vec, int k) {
  int ptr1 = 0;
  int ptr2 = vec.size()-1;
  int ans = 0;

  while (ptr1 < ptr2) {
    if (vec[ptr1] + vec[ptr2] == k) {
      ans++;
      ptr1++;
      ptr2++;
    } else if (vec[ptr1] + vec[ptr2] > k) {
      ptr2--;
    } else {
      ptr1++;
    }
  }

  return ans;

}



/* What if repeated integers. That is not distinct.
 *
 * */

int countPairs(const std::vectir<int>& vec, int k) {
  int ptr1 = 0;
  int ptr2 = vec.size()-1;
  int ans = 0;

  while (ptr1 < ptr2) {
    if (vec[ptr1] + vec[ptr2] == k) {
      if (vec[ptr1] != vec[ptr2]) {
        int count1 = 1;
        int count2 = 1;
        while (vec[ptr1] == vec[ptr1+1]) {
          ptr1++;
          count1++;
        }
        
        while (vec[ptr2] == vec[ptr2+1]) {
          ptr2++;
          count2++;
        }

        ptr1++;
        ptr2++;
        
        ans += (count1 * count2);

      } else {
        int count = ptr2-ptr1+1;
        ans += (n*(n-1))/2;
        break;
      } 

    } else if (vec[ptr1] + vec[ptr2] > k) {
      ptr2--;
    } else {
      ptr1++;
    }
  
  }

  return ans;

}
