#include <algorithm>
#include <stdexcept>
#include <vector>
#include <numeric>
#include "math.h"

using std::domain_error; 
using std::sort; 
using std::vector;

// compute the median of a vector<double>
double median(vector<double> vec)
   {
   const auto size = vec.size();
   if (size == 0)
      {
      throw domain_error("median of an empty vector");
      }

   sort(vec.begin(), vec.end());

   const auto mid = size / 2;
   return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
   }

// compute the average of a vector<double>
double average(const vector<double>& vec)
   {
   const auto size = vec.size();
   if (size == 0)
      {
      throw domain_error("average of an empty vector");
      }
   return accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
   }