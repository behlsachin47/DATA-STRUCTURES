


void generateAllSubsetsWithDup(std::vector<int>& num, int index,
std::vector<int>& iter, std::vector<std::vector<int>>& output) {
  
  output.push_back(iter);
  if (index == num.size()) {
    return;
  }

  for (int i = index; i < num.size();i++) {
    int val = num[i];
    int freq = 1;
    while (i+1 < num.size() && num[i] == num[i+1]) {
      freq++;
      i++;
    }

    for (int j = 0; j < freq; j++) {
      iter.push_back(val);
    }

    for (int j = 0; j < freq; j++) {
      generateAllSubsetsWithDup(num, i+1, iter, output);
      iter.pop_back();
    }

  }

}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& num) {
  std::sort(num.begin(), num.end());
  std::vector<std::vector<int>> output;
  std::vector<int> iter;
  generateAllSubsetsWithDup(num, 0, iter, output);
  return output;
}
