
void generateAllSubsets(std::vector<int>& A, int index, std::vector<int>& iter, 
    std::vector<std::vector<int>>& output) {

    output.push_back(iter);
    if (index == A.size()) {
        return;
    }
    
    for (int i = index; i < A.size(); i++) {
        iter.push_back(A[i]);
        generateAllSubsets(A, i+1, iter, output);
        iter.pop_back();
    }
    
    
    
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    std::sort(A.begin(), A.end());
    std::vector<std::vector<int>> output;
    std::vector<int> iter;
    generateAllSubsets(A, 0, iter, output);
    
    return output;
}

/*******************************************************TIME COMPLEXITY***/
O(N*2^N)


void generateAllSubsets(const std::vector<int>& A, int index, std::vector<int>&
iter, 
                        std::vector<std::vector<int> >& output) {
    if (index == A.size()) {
        output.push_back(iter);
        return;
    }          
    
    generateAllSubsets(A, index+1, iter, output);
    iter.push_back(A[index]);
    generateAllSubsets(A, index+1, iter, output);
    iter.pop_back();
}


vector<vector<int> > Solution::subsets(vector<int> &A) {
    std::sort(A.begin(), A.end());
    std::vector<std::vector<int> > output;
    std::vector<int> iter;
    generateAllSubsets(A, 0,  iter, output);
    
    std::sort(output.begin(), output.end());
    return output;
}



/**********************APPROACH 3 ***************/
/*** GET THE POWER SET OF N-1 ELEMENTS AND  1. DONT ADD THE NTH ELEMENT 2. ADD
 * THE NTH ELEMENT
 *
 */

void generateAllSubsets3(const std::vector<int>& arr, int index,
std::vector<std::vector<int>>& output) {
  if (index == arr.size())
  {
    output.push_back(std::vector<int> {});
    return;
  }
  generateAllSubsets3(arr, index+1, output);

  for (int i = 0; i < output.size(); i++) {
    std::vector<int> temp = output[i];
    temp.push_back(arr[index]);
    output.push_back(temp);
  }
}

O(N*2^N)




