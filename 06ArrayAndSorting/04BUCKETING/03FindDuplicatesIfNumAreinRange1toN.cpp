////////////////////////////////////////////////////////////////////////////
//      FIND THE DUPLICATE IF GIVEN AN ARRAY OF LENGTH N+1 AND NUMBERS IN RANGE
//      1 - N. there exists only one duplicate
//
//


//METHOD1: EQUATION METHOD
//  Find sum of all numbers => currsum and sum of all natural numbers. Then
//  result will be the subtraction of these two.


//METHOD2: USING ARRAY AS HASH MAP
//  SIMPLY INVERT THE SIGN OF NUMBER-1 INDEX; WHEN YOU ENCOUNTER NUMBER
//



//////////////////////////////////////////////////////////////////////////////
//      FIND DUPLICATES IF GIVEN AN ARRAY OF LENGTH N+2 AND NUMBERS IN RANGE
//      1 - N. TWO NUMBERS ARE DUPLICATED


//METHOD1: EQUATION METHOD
//      Find sum of all numbers and subtract it from sum of natural numbers; a+
//      b
//
//      Find product of all numbers and divide it by n!; a*b


//METHOD2: USING ARRAY AS HASH MAP
// INVERT THE SIGN OR ADD N



//METHOD3: XOR METHOD; AS YOU DID IN THE CASE WHERE EXCEPT TWO ELEMENTS; ALL
//ARE DUPS
//  a ^ b = xor of all natural number ^ xor of all elements in the array
//  now maintain two lists; where a bit is set as in xor and bit is unset; this
//  list should be made from all natural numbers and all elements in the list.
//  
//  Now take xor list1 => a and xor list2 = > b
//
//  eg. 1,2,3,1,2
//
//  a^b = 1^2^3^1^2  ^ 1^2^3 = 011
//  now list1 (1st bit set) : 2; 3; 2; 2; 3 => xor all and get a =>2
//  now list2 (1st bit unset): 1; 1; 1 => xor all and get b => 1
// 




/////////////////////////////////////////////////////////////////////////////
//          FIND THE NUMBERS IF K ELEMENTS ARE DUPS IN AN ARRAY SIZE OF N
//          SUCH THAN NUMBERS CAN BE IN RANGE 1-N
//
//  METHOD1: EQUATION : WONT WORK HERE
//
//
//  METHOD2: HASH MAP METHOD => KEWL !!
