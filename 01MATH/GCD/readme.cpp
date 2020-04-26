/*=> GCD OF a and b IS THE GREATEST COMMON DIVISOR; I.E. the greatest number that divides both
a and b.
  => GCD(a, 0) = |a|
  => GCD(a, 1) = 1
      for a != 0
*/

//////////////////1. NAIVE ALGORITHM:

int gcd(int a, int b) {
  if (a == 0 && b == 0)
    return -1; //undefined
  else if (a == 0)
    return b;
  else if (b == 0)
    return a;


  int ans = 1;
  for (int i = std::min(a,b); i > 0; i--) {
    if (a % i == 0 && b % i == 0) {
      ans = i;
      break;
    }
  }

  return ans;
}

//TIME COMPLEXITY: O(min(a,b))


/*2. Euclid's subtraction algo

=> This is based on the fact that gcd(a, b) === gcd(a-b, b)
=> We can prove this by saying that a and b are multiples of gcd g. And
subtracting some multiple of g from a. Same gcd will be of a-b and b.
*/

int gcd_imp1(int a, int b) {
  if (a == 0 && b == 0)
    return -1;
  
  if (b > a) {
    swap(a, b);
  }

  if (b == 0)
    return a;
  else
    return gcd(a-b, b);
}

/*TIME COMPLEXITY: worst case shall be when we have b as 1; then we have to go
till O(std::max(a,b))


3. EUCLID'S ALGO

=> Repeated subtraction is actually division
=> gcd(a, b ) = gcd(b, a%b)
=> Lets say gcd is g

  a = b*q + r

  now g completely divides a and b. so it has to divide r.
*/


int gcd(int a, int b) {
  if (a == 0 && b == 0)
    return -1;
  if ( b == 0)
    return a;
  else 
    return gcd(b, a%b);
}

/*TIME COMPLEXITY: How much does a reduces to after a%b ?
  => a%b can be maximum b-1. 
  => b can be 
    1. > a/2  a%b = 0 to (a/2)-1
    2. = a/2  a%b = 0
    3. < a/2  a%b = 0 to (a/2)-1
  => Hence we can say that a at least reduces to half.
  => O(log2(std::max(a, b))

*/
  

/////////////////SOME BASIC EXAMPLES
//1. gcd of an array : O(NlogN)
//2. Given an array; return true if there is a subsequence with gcd 1
// 
//1. Largest number x; that divides A and is coprime with B.
//
//1. Maximize gcd of an array with one deletion.
//
//1. There are N players each with strength A[i]. when player i attack player j,
//player j strength reduces to max(0, A[j]-A[i]). When a player's strength
//reaches zero, it loses the game and the game continues in the same manner
//among other players until only 1 survivor remains.Can you tell the minimum
//health of last surviving person ?
//
//
//

