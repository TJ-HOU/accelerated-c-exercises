/*
Exercise4-2, 4-3, 4-4
See detailed explanation for each exercise in the code.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::streamsize;
using std::fixed;
using std::setprecision;
using std::endl;
using std::setw;
using std::max;
using std::to_string;

int main()
   {
   /*
   Exercise 4-2&3: Use setw to line up the int values up in columns
   Example:
   - Output: 
   -100 10000
   -99  9801
   ...
   99  9801
   100 10000
   */
  
   vector<int> col1, col2;
   string::size_type maxlen1 = 0;
   string::size_type maxlen2 = 0;

   for (int i = -100; i != 101; ++i)
      {
      col1.push_back(i);
      col2.push_back(i*i);
      maxlen1=max(to_string(i).size(),maxlen1);
      maxlen2=max(to_string(i*i).size(),maxlen2);
      }

   cout << "Line up 2 int columns: " << endl;
   for (vector<int>::size_type i=0; i!=col1.size(); ++i)
      {
      cout << setw(maxlen1) << col1[i] << setw(maxlen2+1) << col2[i] << endl;
      }

   /*
   Exercise 4-4: Use manipulator to line up the double values up in columns
   Example:
   - Input: 
   -1 1 0.5
   - Output: 
   -1.000000 1.000000
   -0.500000 0.250000
   0.000000 0.000000
   0.500000 0.250000
   */

   double begin = 0;
   double end = 0;
   double increment = 0;
   cout << "To generate double values in [a,b), please enter a and b and increment: " << endl;
   cin >> begin >> end >> increment;

   vector<double> col3, col4;

   // read in numbers 
   while (begin < end)
      {
      col3.push_back(begin);
      col4.push_back(begin*begin);
      maxlen1=max(to_string(begin).size(),maxlen1);
      maxlen2=max(to_string(begin*begin).size(),maxlen2);
      begin = begin + increment;
      }

   cout << "Line up 2 double columns: " << endl;
   for (vector<double>::size_type i=0; i!=col3.size(); ++i)
      {
      // use fixed to ensure the output is not in scientific notation
      cout << fixed << setw(maxlen1) << col3[i] << setw(maxlen2+1) << col4[i] << endl;
      }

   cout << endl;

   /*   
   2nd method for Exercise 4-4:
   use setprecision() to ensure the output is not in scientific notation
   cout << "result of manipulator: " << endl;
   streamsize prec = cout.precision();
   for (vector<double>::size_type i=0; i!=col1.size(); ++i)
      {
      if (col1[i] < 0) 
         { 
         cout << setprecision(6) << col1[i] << " " << col2[i]  << endl;
         } 
      else
         {
         cout << setprecision(6) << col1[i] << "  " << col2[i]  << endl;
         }     
      }
   cout << setprecision(prec) << endl;
   */

   return 0;
   }

