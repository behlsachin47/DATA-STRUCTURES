void removeInitialZeros(std::string& tempA) {
            //remove the zeros at the start
    if (tempA.size() > 0) {
        int ind = 0;
        while (ind < tempA.size() && tempA[ind] == '0')
            ind++;
        if (ind == tempA.size()) {
            tempA = "";
        } else {
            tempA = tempA.substr(ind);
        }
    }
    
}

int Solution::compareVersion(string A, string B) {
    std::stringstream strA (A);
    std::stringstream strB (B);
    
    while (1) {
        std::string tempA = "";
        std::string tempB = "";
        
        getline(strA, tempA, '.');
        getline(strB, tempB, '.');
        //std::cout << "DEBUG: " << tempA << " " << tempB << std::endl;
        if (tempA == tempB && tempA == "")
            return 0;
        removeInitialZeros(tempA);
        removeInitialZeros(tempB);
        
        if (tempA == tempB) 
            continue;
        else if (tempA.size() > tempB.size()) {
            return 1;
        } else if (tempA.size()  < tempB.size()) {
            return -1;
        } else if (tempA > tempB) {
            return 1;
        } else {
            return -1;
        }
    }
    return 0;
}
