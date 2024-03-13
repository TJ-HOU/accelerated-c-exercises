#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <stdexcept>

// Exercise 10.2
template<class T,class In>
T median(In begin, const In end)
   {
   if (begin == end)
      {
      throw std::domain_error("median of an empty vector");
      }
   std::vector<T> v;
   while (begin != end)
      {
      v.push_back(*begin);
      ++begin;
      }
   typedef typename std::vector<T>::size_type vec_sz;
   vec_sz size = v.size();
   sort(v.begin(), v.end());
   vec_sz mid = size/2;
   return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
   }
#endif