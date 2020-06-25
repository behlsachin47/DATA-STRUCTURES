void generateAll(int sumLeft, std::vector<int>& candidates, int index, std::vector<int>&
iter, std::vector<std::vector<int>>& output) {
  if (sumLeft == 0) {
    output.push_back(iter);
    return;
  } else if (index > candidates.size() || sumLeft < 0) {
    return;
  }

  for (int i = index; i < candidates.size(); i++) {
    int val = candidates[i];
    int freq = 1;

    while (i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
      i++;
      freq++;
    }

    for (int j = 0; j < freq; j++) {
      iter.push_back(val);
    }
    
    int temp = freq*val;
    for (int j = 0; j < freq; j++) {
      generateAll(sumLeft-temp, candidates, i+1, iter, output);
      iter.pop_back();
      temp -= val;
    }

  }
}


std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int
target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<std::vector<int>> output;
  std::vector<int> iter;
  generateAll(target, candidates, 0, iter, output);
  return output;
}
