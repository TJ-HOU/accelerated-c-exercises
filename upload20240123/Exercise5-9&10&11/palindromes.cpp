#include <string>
#include <list>
#include <cctype>
#include "palindromes.h"
 
using std::string;
using std::list;
using std::tolower;

bool palindromes(string& s)
   {    
   string::size_type i = 0;
   string::size_type j = s.size()-1;
   while ((i<j) && tolower(s[i])== tolower(s[j]))
      {
      ++i;
      --j;
      }
   if (i < j)
      {
      return false;
      }
   return true;
   }

list<string> extract_palindromes(list<string>& words)
   {
   list<string> ret;
   auto iter = words.begin();

   while (iter != words.end()) 
      { 
      if (palindromes(*iter)) 
         {
         ret.push_back(*iter);
         iter = words.erase(iter);
         } 
      else
         {
         ++iter;
         }  
      }
   return ret;
   }