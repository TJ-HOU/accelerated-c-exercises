#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include "split.h"
#include "cat.h"
#include "permute.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream;
using std::sort;
using std::find;
using std::max;

vector<string> rotate(const vector<string>& v)
   {
   vector<string> ret;
   string left;
   string right;
   typedef vector<string>::size_type vector_size;
   vector_size i = 0;
   vector_size len = v.size();

   while (i != len) 
      {  
      for (vector<string>::const_iterator it = v.begin(); it != v.begin()+i; ++it)
         left = left + (*it) + ' ';

      for (vector<string>::const_iterator it = (v.begin()+i); it != v.end(); ++it)
         right = right + (*it) + ' ';

      ret.push_back(right+left);

      left.clear();
      right.clear();

      ++i;  
      }

   return ret;
   }

vector<string> unrotate(vector<string>& v, const string& begin, const string& end)
   {   
   vector<string> str_vec;
   vector<string> ret;
   vector<string> left_vec;
   vector<string> right_vec;

   for (vector<string>::size_type i = 0; i != v.size(); ++i)
      {
      str_vec = split(v[i]);

      string left;
      string right;
            
      vector<string>::size_type k = 0;
      if (str_vec[0]!=begin)
         {
         while (str_vec[k]!=begin)
            {
            right = right + str_vec[k] + ' ';
            ++k;
            }
         while (k!=str_vec.size())
            {
            left = left + str_vec[k] + ' ';
            ++k;
            }               
         }
      else
         {
         while (k!=str_vec.size())
            {
            right = right + str_vec[k] + ' ';
            ++k;
            } 
         }

      left_vec.push_back(left);
      right_vec.push_back(right);

      left.clear();
      right.clear();     
      }

   ret = hcat (left_vec,right_vec);

   return ret;
   }
