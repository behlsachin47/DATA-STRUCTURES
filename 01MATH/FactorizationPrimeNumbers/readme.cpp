#include <iostream>
#include <vector>
#include <cmath>
///////////////////////////////FACTORS OF A NUMBER ////////////////////////////

/*Alright !!!
1. Lets first talk about factors of a number n. This is simply getting the
divisors that has remainder 0. 

2. Trick here is to observe that the factors exist in pairs. for eg. 100 :
1,100  2,50  4,25  5,20  10,10 [special case :P]  that's it

3. so instead of having iterate from 1 to n; we can iterate from 1 to sqrt(n)

4. Secondly, we have this one more thing; I hope you observed. Number of factors of
   perfect square is odd and others is even.
*/

void print(std::vector<int>& list) {
  for (int i = 0; i < list.size(); i++) {
    std::cout << list[i] << " ";
  }
  std::cout << std::endl;
}


int countPrintFactors(int num) {
  
  int count = 0;
  std::vector<int> list1;
  std::vector<int> list2;
  int limit = sqrt(num);
  for (int i = 1; i < limit; i++) {
    if (num %i == 0) {
      count += 2;
      list1.push_back(i);
      list2.push_back(num/i);
    }
  }

  if (num % limit == 0) {
    count++;
    list1.push_back(limit);
  }
  print(list1);
  print(list2);
  return count;


}




////////////////////////////PRIME CHECK ///////////////////////////



bool isPrime(int n) {
  n = abs(n);
  if (n <= 1)
    return false;

  for (int i = 2; i <= sqrt(n); i++) 
    if (n % i == 0)
      return false;

  return true;

}

///////////////////////////COUNT PRIME TILL N ///////////////////
//
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        n--;
        std::vector<bool> vec (n+1, 1);
        int count = 0;
        vec[0] = 0;
        vec[1] = 0;
        
        for (int i = 2; i*i <= n; i++) {  /// note how we go till sqrt(n)
            if (vec[i]) {
                for (int j = i*i; j <= n; j += i) {  // how we start from i*i
                                                    //instead of i*1; i*2 so
                                                    //on..
                    vec[j] = 0;
                }
            }
        }  
        
        
        for (int i = 0; i <= n; i++) {
            if (vec[i] == 1) {
                count++;
            }
        }
        
        return count;
    }




/*THE idea here is to cancel those who have prime factors; the approach takes
time complexity O(nlogn); more stricter bound is O(nloglogn)

*/






///////////////////////PRIME FACTORIZATION OF A NUMBER ////////////////

/*sO BASIC IDEA HERE IS TO move from all factors; 2 to sqrt(n)
and do a repeated multiplication till that number is divisible

this way we can ignore the pf 'as prime factors of composite number have
already been considered.

However, there is this special case where the last number remains; even after
dividing by all factors from 2 to sqrt(n)
  IDEA IS TO CHECK IF n > 1; if it is ; it must be a prime factor of n
  eg. 62 = 2*31

*/

void printPrimeFactorization(int n) {
  if (n <= 1)
    return;

  int limit = sqrt(n);
  for (int i = 2; i <= limit; i++) {
    int count = 0;
    while (n%i == 0) {
      count++;
      n = n/i;
    }
    
    if (count > 0) {
      std::cout << i << "; " << count << std::endl;
    }
  }
  if (n > 1)
    std::cout << n << ";" << 1 << std::endl;

}

///////////////////////PRIME FACTORIZATION FOR MULTIPLE QUERIES //////////////
//We first make the sieve in O(nloglogn) time complexity
//this is to be made with slight modifications; like we have to store the 
//smallest factor instead of boolean; if sf == i => this is prime
//
//Then for each query; pf can be caluclates in O(logn) time :))

void printFactorizationMultipleQueries(int n, std::vector<int>& queries) {
  //make a sieve in O(nloglogn)
  std::vector<int> sieve;
  sieve.push_back(0);
  sieve.push_back(1);
  for (int i = 2; i <= n; i++) {
    sieve.push_back(i);
  }

  for (int i = 2; i <= sqrt(n); i++) {
    if (sieve[i] == i) {
      for (int j = i*i; j <= n; j+= i) {
        if (sieve[j] == j)
          sieve[j] = i;
      }
    }
  }

  for (int i = 0; i < queries.size(); i++) {
    int k = queries[i];
    while (sieve[k] != k) {
      int sf = sieve[k];
      std::cout << sf << " ";
      k = k/sf;
    }

    if (k != 1)
      std::cout << k ;
    std::cout << std::endl;
  
  }
}

int main() {
  int n;
  std::cin >> n;
  printPrimeFactorization(n);

  std::vector<int> queries(n, 1);
  for (int i = 0; i < n; i++)
    queries[i] = i+1;

  printFactorizationMultipleQueries(n, queries);
}
