/* In searching, we have two things: the target and search space.
 * 
 *  1. SEARCH SPACE: This can be both ordered and unordered.
 *              :Unordered search space can still work if somehow we have some
 *              logic to discard some part of search space every time.
 *  2. Function should be monotonous. ??
 *
 *  
 *
 * */



 int binarySearch (std::vector<int>& arr, int key) {
  int ans = -1;
  int low = 0;
  int high = arr.size()-1;

  while (low <= high) {
    int mid = low + (high-low)/2;

    if (arr[mid] == key) {
      ans = mid;
      break;
    } else if (arr[mid] > key) {
      high = mid-1;
    } else {
      low = mid+1;
    }
  }

  return ans;
 }




 /* The idea is to simply reduce the search space by half in each iteration.
  * What if we say that the array is having duplicates and we want to find the
  * first occurrence of an element.
  * */


 int binarySearchFirst(const std::vector<int>& arr, int key) {
  int ans = -1;
  int low = 0;
  int high = arr.size()-1;

  while (low <= high) {
    int mid = low + (high-low)/2;
    
    if (arr[mid] == key) {
      ans = mid;
      high = mid-1;
    } else if (arr[mid] > key) {
      high = mid-1;
    } else {
      low = mid+1;
    }
  
  }

  return ans;
  
 }



 /* Similary you can find the last occurrence of an element. and number of
  * occurrence of an elemenet by finding both first and last occurrence.
  * 
  * 
  * WHY WE SHOULD NOT HAVE TERNIARY SEARCH BUT BINARY SEARCH ? oR WHY NOT
  * DIVIDE THE ARRAY IN 5 PARTS ? wHY NOT DIVIDE THE ARRAY IN N PARTS AND HAVE
  * o(1) :p ?
  */

 int trinarySearch(const std::vector<int>& arr, int low, int high, int key) {
  
  if (low > high)
    return -1;

  int part1 = (high-low)/3 + low;
  int part2 = high - (high-low)/3;
  
  if (arr[part1] == key)
    return part1;
  else if (arr[part2] == key)
    return part2;
  else if (arr[part1] > key) {
    return trinarySearch(arr, low, part1-1, key);
  } else if (arr[part2] < key) {
    return trinarySearch(arr, part2+1, high, key);
  } else {
    return trinarySearch(arr, part1+1, part2-1, key);
  }
 
 }


 /* number of comparisons in trinary search is 4 and in binary search it is 2/
  *  
  * T(n) = T(n/3) + 4
  * 
  * T(n) = T(n/2) + 2
  *
  *
  * Worst case comparisons in trinary : 4*log3(n)
  *                        in binary: 2*log2(n)
  *
  * Here we can see that number of comparisons are more in trinary than binary
  * search. :)
  * */




/* CLASS QUESTIONS
 * 1. SEARCH IN SORTED AND ROTATED ARRAY
 * 2. PEAK ELEMENT; GIVEN AN ARRAY
 * 3. SINGLE ELEMENT IN A SORTED ARRAY WITH EVERY OTHER ELEMENT REPEATED TWICE.
 * */



 
  
 
