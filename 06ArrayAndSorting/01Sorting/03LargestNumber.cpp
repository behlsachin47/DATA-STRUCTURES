/*Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * For example:
 *
 * Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 * */
bool myCompare(const int& a, const int& b) {
    std::string c1 = std::to_string(a) + std::to_string(b);
    std::string c2 = std::to_string(b) + std::to_string(a);
    
    if (c1 > c2)
        return 1;
    else
        return 0;
}
string Solution::largestNumber(const vector<int> &A_) {
    std::vector<int> A = A_;
    std::sort(A.begin(), A.end(), myCompare);
    std::string result;
    for (int i = 0; i < A.size(); i++)
        result += std::to_string(A[i]);
    
    int prefix = 0;
    while (prefix < result.size() && result[prefix] == '0')
        prefix++;
    if (prefix == result.size())
        result = "0";
    else
        result = result.substr(prefix);
    
    return result;
}

