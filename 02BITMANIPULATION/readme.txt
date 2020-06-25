unsigned int Solution::reverse(unsigned int A) {
    for (int i = 0; i <= 15; i++) {
        int bit1 = ((A >> i)&1);
        int bit2 = ((A >> (31-i))&1);
        
        
        if (bit1 == bit2)
            continue;
        else {
            A ^= (1 << (31-i));
            A ^= (1 << i); 
        }
        
        
        
    }
    
    return A;
}


XOR PROPERTIES

a ^ 0 = a;
a ^ a = 0;
a ^ b = c;
c ^ a = b;
c ^ b = a;


NEGATIVE NUMBER REPRESENTATION IN 1'S COMPLIMENT

  The idea is simple, MSB is used to represent the sign of number.
  Drawback here is that we represent two forms of zero ; one with signed bit
  set and one with signed bit 0



NEGATIVE NUMBER REP IN 2'S COMPLIMENT

  The idea here is that we can simply represent negative numbers by
  representing MSB negative value
  eg consider 4 bit signed number

  0: 0000 
  1: 0001
  2: 0010
  3: 0011
  4: 0100
  5: 0101
  6: 0110
  7: 0111


  1000 => -8 => 0 (num + 2^(numBits-1))   what would the value without signed bit => 0
  1001 => -7 => 1
  1010 => -6 => 2
  1011 => -5 => 3
  1100 => -4 => 4
  1101 => -3 => 5
  1110 => -2 => 6
  1111 => -1 => 7


  -8 to 7



BITS PLAY

  1. Find first set bit
    int findFirstSetBit(int n ) {
      if (n == 0)
        return -1;

      int temp = n & n-1;
      temp = temp ^ n;

      return log2(temp) + 1;
    }

  2. Rightmost different bit of two numbers

    take xor of two numbers and find the first set bit with above algo


  3. Check if ith bit is set or not
    
    int check(int n, int i) {
      return (n & (1 << i)); 
    }


  4. Count total set bits
    
    int countSetBits(int n) {
      int ans = 0;
      while (n) {
       n = n & n-1;
       ans++;
      }
      return ans;
    }


  5. Number is sparse or not; sparse number is the number with no conssecutive
     1's


     bool isSparse(int n){
         return !(n & (n << 1));
     }

  6. Check how many conssecutive 1 is present in the number.
    
     bool numConssecutive(int n) {
      while (n & (n << 1)) {
        n = n << 1;
        ans++;
      }
      return ans;
     }


  7. swap odd and even bits
 
unsigned int swapBits (unsigned int n) {
    int even = 85;
    int odd = 42;
    
    even = even & n;
    odd = odd & n;

    return ((even << 1) | (odd >> 1));
} 
