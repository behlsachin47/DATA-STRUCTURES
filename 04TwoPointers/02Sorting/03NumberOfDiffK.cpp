/* Number of diffk possible. We have to find out how many pairs exist such that
 * diff is k.
 *
 * Lets consider distinct integers for now.
 *
 * ptr1 - ptr2 = k'
 *
 * Now how do we choose ptr1 and ptr2 such that we are able to make the
 * concrete decision of either reducing k' or increasing k'
 *
 * if we have to increase k': what are our options; increase ptr1 and decrease
 * ptr2
 *
 * if we have to decrease k' : what are our options; decrease ptr1 and increase
 * ptr2
 *
 * so we should not move the two pointers in the same directions. Instead lets
 * say we consider two cases:
 *  CASE1:Increase ptr1; increase ptr2
 *  CASE2:dECREASE ptr1; decrease ptr1
 * */
#include <iostream>
#include <vector>

//case1
int countDiffK(const std::vector<int>& vec, int k) {
  int n = vec.size();
  int ptr1 = 1;
  int ptr2 = 0;
  int ans = 0;
  while (ptr1 < n) {
    if (vec[ptr1] - vec[ptr2] == k) {
      ans++;
      ptr1++;
      ptr2++;
    } else if (vec[ptr1] - vec[ptr2] > k) {
      ptr2++;
    } else {
      ptr1++;
    }

    if (ptr1 == ptr2) {
      ptr1++;
    }
  
  }

  return ans;

}



//repeated elements
//

int countDiffK2(const std::vector<int>& vec, int k) {
  int n = vec.size();
  int ptr1 = 1;
  int ptr2 = 0;
  int ans = 0;
  while (ptr1 < n) {
    if (vec[ptr1] - vec[ptr2] == k) {
      if (vec[ptr1] == vec[ptr2]) {
        int count = 1;
        while (ptr2+1 < n && vec[ptr2+1] == vec[ptr2]) {
          ptr2++;
          count++;
        }

        ans += (count*(count-1))/2;
        ptr1 = ptr2+1;

      } else {
        int count1 = 1;
        int count2 = 1;
        while (ptr1+1 < n && vec[ptr1] == vec[ptr1+1]) {
          count1++;
          ptr1++;
        }

        while ( vec[ptr2] == vec[ptr2+1]) {
          count2++;
          ptr2++;
        }

        ans += count1*count2;
        ptr1++;
        ptr2++;
      }

    } else if (vec[ptr1] - vec[ptr2] > k) {
      ptr2++;
    } else {
      ptr1++;
    }

    if (ptr1 == ptr2) {
      ptr1++;
    }
  
  }

  return ans;

}



int main() {
  std::vector<int> vec = {1,1,1, 2,2,2,3,3,4,4,4,5,5,6,6};
  std::cout << countDiffK2(vec, 1) << std::endl;

}
