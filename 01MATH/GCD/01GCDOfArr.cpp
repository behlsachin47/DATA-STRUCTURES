#include <iostream>

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else 
    return gcd(b, a%b);
}

int gcd(int* arr, int n) {
  if (n == 0)
    return -1;

  int ans = arr[0];
  for (int i = 1; i < n; i++) {
    ans = gcd(ans, arr[i]);
  }
  return ans;
}


int main() {
  int arr[] = {1,2,3,4,5};
  std::cout << gcd(arr, 5) << std::endl;
}
