/*
Exercise 7-9
RAND_MAX=2^15-1=32767; largest possible integer=2^31-1=2147483647
rand(defined in <cstdlib>) returns an integer in the range [0,RAND_MAX].
Create a function with rand() to return an integer in the range [0,max) where max can be > RAND_MAX
Output:
generate a random integer between 0 and 2147483647
nrand() result: 16807
library result: 317278233

nrand() result: 282475249
library result: 1156326387

nrand() result: 1622650073
library result: 1406702275

nrand() result: 984943658
library result: 957799755

nrand() result: 1144108930
library result: 781245650
*/
#include <iostream>
#include <cstdlib>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::rand;
using std::domain_error;
using std::to_string;

// forward declaration
int nrand(int n);

// generate random integer in the range of [0,n)
int nrand(int n)
   {
   if (n <= 0)
      {
      throw domain_error("Argument to nrand is out of range");
      }
   else if (n <= RAND_MAX)
      {
      const int bucket_size = RAND_MAX / n;
      int r;
      do 
         {
         r = rand() / bucket_size;
         }
      while (r >= n);
      return r;
      }
   else
      {
      const int bucket_size = n / RAND_MAX;
      int r;
      do 
         {
         // recursively call nrand on the remainder of the given range
         r = rand() * bucket_size + nrand(bucket_size);
         }
      while (r >= n);
      return r;
      }    
   }

// use Mersenne Twister pseudo-random number generator as the default prng
int prng(const int& a, const int& b)
   {
   std::random_device rd;
   std::mt19937 gen(rd()); 
   std::uniform_int_distribution<int> distribution(a, b);
   return distribution(gen);
   }

int main() 
   { 
   int range = 2147483647;
   cout << "genreate a random integer between 0 and " << to_string(range) << endl;
   cout << endl;
   for (int i = 0; i < 5; i++)
      {
      // use self-defined function to generate random integers
      cout << "nrand() result: ";
      cout << nrand(range) << endl;

      // compare with the result of default prng
      cout << "library result: ";
      cout << prng(0, range) << endl;
      cout << endl;
      }
   return 0;
   }