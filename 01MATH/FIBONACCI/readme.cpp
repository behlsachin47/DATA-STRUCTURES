/*We already know about fibonacci numbers. Numbers that are defined 
 * as the sum of last two numbers in the sequence provided that first
 * two numbers are 0 and 1.
 *
 * F(m) = F(m-1) + F(m-2)
 *
 * */

//HOW TO FIND THE Nth Fibonacci number.
//This can be done in O(logN) way :)
//  assuming F(n) can be represented as
//  [ F(n) ]  = [ 1 1 ] [ F(n-1) ]
//  [ F(n-1)] = [ 1 0 ] [ F(n-2) ]
//
// Matrix multiplication;
//
// This can be expanded as :
//  [ F(n) ] = power (c_mat, n-1) * [F[1]]
//  [ F(n-1)]                       [F[0]]
//


//This much power can be calculated using fast exponention method



