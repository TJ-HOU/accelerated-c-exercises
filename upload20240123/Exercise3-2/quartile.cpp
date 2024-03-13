#include <cmath>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <iostream>
#include "median.h"
#include "quartile.h"

using std::vector;
using std::domain_error;
using std::streamsize;
using std::cout;
using std::setprecision;
using std::endl;
using std::floor;

void quartile(vector<double> nums)
   {
   typedef vector<double>::size_type vec_sz;
   vec_sz size = nums.size();

   // compute the median
   sort(nums.begin(), nums.end());
   double mid = median(nums);

   double qtr1 = 0;
   double qtr3 = 0;

   vector<double> lower_half(nums.begin(), nums.begin() + size / 2);
   vector<double> upper_half(nums.begin() + (size + 1) / 2, nums.end());

   // Compute 1st and 3rd quartile
   // Second try based on Ziqi's suggestion: Concise and works!
   qtr1 = median(lower_half);
   qtr3 = median(upper_half);


   /* First try: long but works
   // compute 1st and 3rd quantile
   if (size == 1)
      {
      qtr1 = nums[0];
      qtr3 = nums[0];
      }
   else
      {
      sort(nums.begin(), nums.end());
      mid = median(nums);    
      if (size%4 == 0)
         {
         qtr1 = 0.5*(nums[size/4]+nums[size/4-1]);
         qtr3 = 0.5*(nums[3*size/4]+nums[3*size/4-1]);
         }
      else if (size%4 == 1)
         {
         qtr1 = 0.5*(nums[size/4]+nums[size/4-1]);
         qtr3 = 0.5*(nums[3*size/4]+nums[3*size/4+1]);
         }
      else if (size%4 == 2)
         {
         qtr1 = nums[size/4];
         qtr3 = nums[3*size/4];
         }
      else
         {
         qtr1 = nums[size/4];
         qtr3 = nums[3*size/4];
         }         
      }
   */

   streamsize prec = cout.precision();
   cout << "Q1: " << setprecision(3) << qtr1 << endl;
   cout << "Q2: " << mid << endl;
   cout << "Q3: " << qtr3 << setprecision(prec) << endl;

   }






