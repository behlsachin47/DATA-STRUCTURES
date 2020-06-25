#include <iostream>
#include <vector>
#include <cmath>

void radixSort(std::vector<int>& input, int exp) {
  std::vector<std::vector<int>> storage (10, std::vector<int>{});
  for (int i = 0; i < input.size(); i++) {
    storage[((input[i]/exp)%10)].push_back(input[i]);
  }
  int iter = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < storage[i].size(); j++) {
      //std::cout << iter << std::endl;
      input[iter++] = storage[i][j];
    }
  }
}
int main() {
  std::vector<int> input {101, 23, 73, 223, 293, 33, 41, 39, 85, 45, 75};
  int maxElement = input[0];
  for (int i = 0; i < input.size(); i++)
    maxElement = std::max(maxElement, input[i]);
  
  int exp = 1;
  for (int i = 0; i < log10(maxElement); i++) {
    radixSort(input, exp);
    exp *= 10;
  }

  for (int i = 0; i < input.size(); i++)
    std::cout << input[i] << " ";
}
