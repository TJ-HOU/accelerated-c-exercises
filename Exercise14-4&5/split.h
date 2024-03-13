#ifndef GUARD_split
#define GUARD_split

#include "Vec.h"
#include "Str.h"

#include <cctype>
#include <algorithm>

bool space(char c)
   {
   return std::isspace(c);
   }

bool not_space(char c)
   {
   return !space(c);
   }

Vec<Str> split(const Str& str)
   {
   typedef Str::const_iterator iter;
   Vec<Str> ret;

   iter i = str.begin();
   while (i != str.end()) 
      {
      i = std::find_if(i, str.end(), not_space);
      iter j = std::find_if(i, str.end(), space);
      if (i != str.end())
         {
         ret.push_back(Str(i, j));
         }
      i = j;
      }
   return ret;
   }

#endif