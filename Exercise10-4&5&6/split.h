#ifndef GUARD_split_h
#define GUARD_split_h

#include "String_list.h"
#include <string>

bool space(char c)
   {
   return isspace(c);
   }

bool not_space(char c)
   {
   return !isspace(c);
   }

String_list split(const std::string& str)
   {
   typedef std::string::const_iterator iter;
   String_list ret;

   iter i = str.begin();
   while (i != str.end()) 
      {
      // ignore leading blanks
      i = find_if(i, str.end(), not_space);
      // find end of next word
      iter j = find_if(i, str.end(), space);
      // copy the characters in [i, j)
      if (i != str.end())
         {
         ret.push_back(std::string(i, j));
         }
      i = j;
      }
   return ret;
   }

#endif