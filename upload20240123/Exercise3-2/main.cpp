/*
Exercise 3-2: Compute and print the 1st, 2nd and 3rd quartiles

Examples:
- Input: 5
- Output: Q1:5 Q2:5 Q3:5
- Input (even-sized): 3 6 7 8 8 10 13 15 16 20
- Output : Q1:7 Q2:9 Q3:15
- Input (odd-sized): 3 6 7 8 8 9 10 13 15 16 20
- Output : Q1:7 Q2:9 Q3:15
*/

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include "quartile.h"

using std::cin; 
using std::cout;
using std::endl; 
using std::string;
using std::vector;
using std::domain_error;

int main()
   {
   cout << "Enter a set of numbers, "
      "followed by end-of-file: " << endl;

   double x;
   vector<double> nums;

   while (cin >> x)
      {
      nums.push_back(x);
      }
      
   try
      {
      cout << "Quantiles: " << endl;
      quartile(nums);
      }
   catch(domain_error e)
      {
      cout << e.what();
      }

   return 0;
   }