class Solution {
public:
    bool debug = 0;
    int findNth(std::vector<int>& arr, int st, int end, int n) {
      if (st > end)
        return -1;
      
      int mid = (st+end)/2;
      if (mid - st +1 == n)
        return arr[mid];
      else if (mid-st + 1 > n)
        return findNth(arr, st, mid, n);
      else 
        return findNth(arr, mid+1, end, n-mid+st-1);
    }

    int findLessEqual(std::vector<int>& arr, int st, int end, int elem) {
      if (st > end)
        return -1;

      int mid = (st + end)/2;
      if (arr[mid] <= elem) {
        int smallAns = findLessEqual(arr, mid+1, end, elem);
        if (smallAns == -1)
          return mid;
          
        return smallAns;
      } else {
        return findLessEqual(arr, st, mid-1, elem);
      }
    }

    int findNth(std::vector<int>& arr1, int st1, int end1, std::vector<int>&
    arr2, int st2, int end2, int n) {
      if (debug) {
          std::cout << st1 << "," << end1 << "   " << st2 << "," << end2 << " " << n<< std::endl;
      }
      if (st1 > end1 && st2 > end2)
        return -1;
      else if (st1 > end1)
        return findNth(arr2, st2, end2, n);
      else if (st2 > end2)
        return findNth(arr1, st1, end1, n); 
      

      int mid1 = (st1 + end1)/2;
      int mid2 = findLessEqual(arr2, st2, end2, arr1[mid1]);
      
      if (debug) {
          std::cout << "\t" << mid1 << "," << mid2 << std::endl;
          std::cout << "\t[" << arr1[mid1] << "," ;
          if (mid2 != -1)
              std::cout << arr2[mid2] << "]";
          std::cout << std::endl;
      }
      int mid;
      if (mid2 == -1) {
          mid = mid1 - st1 + 1;
         // std::cout << mid << std::endl;
          if (mid == n) {
              return arr1[mid1];
          } else if (mid > n) {
              return findNth(arr1, st1, mid1-1, n);
          } else if (mid < n) {
              return findNth(arr1, mid1+1, end1, arr2, st2, end2, n-mid);
          }
      } else {
        mid = mid1 + mid2 -st1 -st2 + 2;
        if (mid == n)
            return arr1[mid1] > arr2[mid2] ? arr1[mid1] : arr2[mid2];
        else if (mid > n) {
            if (arr1[mid1] > arr2[mid2]) {
                return findNth(arr1, st1, mid1-1, arr2, st2, mid2, n);
            } else {
                return findNth(arr1, st1, mid1, arr2, st2, mid2-1, n);
            }
        }
        else
            return findNth(arr1, mid1+1, end1,arr2,  mid2+1, end2, n - mid);
      }
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      double ans = 0;
      int n1 = nums1.size();
      int n2 = nums2.size();
      if ((n1 + n2) % 2 == 0) {
        if (debug) {
            std::cout << "finding " << (n1+n2)/2 << std::endl;
            
        }
        int elem1 = findNth(nums1, 0, n1-1, nums2, 0, n2-1, (n1+n2)/2);
        if (debug) {
            std::cout << "finding " << 1+ (n1+n2)/2 << std::endl;
            
        }
        int elem2 = findNth(nums1, 0, n1-1, nums2, 0, n2-1, 1+(n1+n2)/2);
        
        if (debug) {
            std::cout << "\n ans:" << elem1 << " " << elem2 << std::endl;
        }
        ans = (elem1 + elem2)/2.0;
      } else {
        if (debug) {
            std::cout << "finding " << 1+ (n1+n2)/2 << std::endl;
            
        }
        int elem1 = findNth(nums1, 0, n1-1, nums2, 0, n2-1, 1+(n1+n2)/2);
        if (debug)
          std::cout << elem1 << std::endl;
        ans = elem1;
      } 
      return ans;
    }
};
