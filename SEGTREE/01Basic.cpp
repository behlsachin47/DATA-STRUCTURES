#include <iostream>
#include <vector>

class SegmentTree {
private:
  std::vector<int>* arr;
  int n;
  bool debug = 1;

  void InternalSegmentTree(int index, int st, int end, const std::vector<int>& input) {
    if (st == end) {
      arr->at(index) = input[st];
      return;
    }
    
    if (debug)
      std::cout << "index: " << index << std::endl;

    int mid = (st + end)/2;
    InternalSegmentTree(2*index+1, st, mid, input);
    InternalSegmentTree(2*index+2, mid+1, end, input);
    arr->at(index) = arr->at(2*index+1) + arr->at(2*index+2);
  }
  
  int getSum(int low, int high, int st, int end, int ind) {
    if (low > high)
      return 0;
    else if (low == st && end == high)
      return arr->at(ind);

    int mid = (st+end)/2;
    if (mid >= low && mid <= high)
      return getSum(low, mid, st, mid, 2*ind+1) + getSum(mid+1, high, mid+1, end, 2*ind+2);
    else if (mid > high) 
      return getSum(low, high, st, mid, 2*ind+1);
    else if (mid < st) 
      return getSum(low, high, mid+1, end, 2*ind+2);
  }

public:
  SegmentTree(const std::vector<int>& input) {
    n = 4*input.size();
    arr = new std::vector<int> (n, -1);
    InternalSegmentTree(0, 0, input.size()-1, input);
     
    if (debug) {
      for (int i = 0; i < arr->size(); i++)
        std::cout << arr->at(i) << " ";
      std::cout << std::endl;
    }
  }
  
  int getSum(int low, int high) {
    if (low > high || high >= (n)/4)
      return -1;

    return getSum(low, high, 0, (n/4)-1, 0);
  }
  void updateIndex() {}

};


int main() {
  int n;
  std::cin >> n;
  std::vector<int>arr (n,0);
  for (int i = 0; i < n; i++)
    std::cin >> arr[i];
  
  SegmentTree st(arr);
  std::cout << st.getSum(0,1) << std::endl;
  std::cout << st.getSum(0,2) << std::endl;
  std::cout << st.getSum(3,5) << std::endl;

}

