#include "split.h"

bool space(char c)
   {
   return isspace(c);
   }

bool not_space(char c)
   {
   return !isspace(c);
   }

Linkedlist split(const std::string& str)
   {
   typedef std::string::const_iterator iter;
   Linkedlist ret;

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
         ret.appendNode(std::string(i, j));
         }
      i = j;
      }
   return ret;
   }