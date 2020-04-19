
class MedianFinder {

    int n;
    std::vector<int> cont;

public:
      
    MedianFinder() {
      cont = std::vector<int>(100000, 0);
        n = 0;
    }
    
    void addNum(int num) {
      //std::cout << "adding\n";
      if (n == 0) {
          cont[0] = num;
          n++; 
          return;
      }
      //add this number to the correct position as we have insertion sort
      int ind = 0;
      while (ind < n && cont[ind] <= num)
        ind++;
      
      int ind2 = n;
      while (ind2 > ind) {
        cont[ind2] = cont[ind2-1];
        ind2--;
      }

      cont[ind] = num;
      n++;
    }
    
    double findMedian() {
        //std::cout << "finding " << n << std::endl;
        if (n == 0)
            return -1;
        if (n % 2 == 0) {
          return (double)(cont[n/2] + cont[-1+n/2])/2.0;
        } else {
          return cont[n/2];
        }
        
    }
};


