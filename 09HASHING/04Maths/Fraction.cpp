typedef long long ll;
class Solution {
public:
    string fractionToDecimal(int numerator_int, int denominator_int) {
        ll numerator = numerator_int;
        ll denominator = denominator_int;
        std::string output;
        std::unordered_map<int, int> mapRemainderToStringIndex;
        bool isRecurring = false;
        bool isNeg = false;
        int recurringStIndex = -1;
        if (numerator < 0) {
            isNeg = !isNeg;
            numerator *= -1;
        }
        
        if (denominator < 0) {
            isNeg = !isNeg;
            denominator *= -1;
        }
        
        if (numerator == 0) {
            return std::string("0");
        }
        
        if (denominator == 0)
            return output;
        
        ll integerPart = numerator/denominator;
        std::string decimalPart;
        ll remainder = numerator % denominator;
        int index = 0;
        while (remainder != 0) {
            if (mapRemainderToStringIndex.count(remainder)) {
                isRecurring = true;
                recurringStIndex = mapRemainderToStringIndex[remainder];
                break;
            } else {
                mapRemainderToStringIndex.insert({remainder,index++});
            }
            
            ll dividend = remainder*10;
            if (dividend < denominator) {
                decimalPart += "0";
                remainder *= 10;
            } else {
                char temp = (dividend/denominator) + '0';
                remainder = dividend % denominator;
                decimalPart += temp;
            }
        }
        if (isNeg) {
            output += "-";
        }
        output += std::to_string(integerPart);
        
        if (decimalPart.size() > 0) {
            output += ".";  
            if (isRecurring) {
                output += decimalPart.substr(0, recurringStIndex);
                output += "(";
                output += decimalPart.substr(recurringStIndex);
                output += ")";
            } else {
                output += decimalPart;
            }
        }
        return output;
            
    }
};