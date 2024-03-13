#include <list>
#include <string>
#include <iostream>
#include "report.h"

using std::string;
using std::list;
using std::cout;
using std::endl;

void write(list<string>& result)
   {
   auto iter = result.begin();
   while (iter != result.end()) 
      { 
      cout << *iter << endl;
      ++iter;
      }
   }

string longest(list<string>& result)
   {
   auto iter = result.begin();
   string longest;
   string::size_type maxlen = 0;

   while (iter != result.end()) 
      { 
      if ((*iter).size() > maxlen)
         {
         maxlen = (*iter).size();
         longest = *iter;
         }                      
      ++iter;
      }

   return longest;
   }

string shortest(list<string>& result)
   {
   auto iter = result.begin();
   string shortest = *iter;
   string::size_type minlen = shortest.size();

   while (iter != result.end()) 
      { 
      if ((*iter).size() < minlen)
         {
         minlen = (*iter).size();
         shortest = *iter;
         }                      
      ++iter;
      }

   return shortest;
   }

