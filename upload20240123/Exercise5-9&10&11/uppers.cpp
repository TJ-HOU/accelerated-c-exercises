#include <string>
#include <list>
#include <cctype>
#include "uppers.h"
 
using std::string;
using std::list;

// predicate to determine whether a student failed 
bool upper(string& s)
   {
   for (string::size_type i = 0;i != s.size();++i)
      {
      if (isupper(s[i]))
         {
         return true;
         }
      }

   return false;
   }

list<string> extract_uppers(list<string>& words)
   {
   list<string> uppers;
   auto iter = words.begin();

   while (iter != words.end()) 
      { 
      if (upper(*iter)) 
         {
         uppers.push_back(*iter);
         iter = words.erase(iter);
         } 
      else
         {
         ++iter;
         }
      }

   return uppers;
   }