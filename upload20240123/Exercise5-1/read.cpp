#include <vector>
#include <string>
#include <iostream>
#include "read.h"

using std::string;
using std::vector;
using std::getline;
using std::istream;

vector<string> read(istream& in) 
   {
   string s;    
   vector<string> v;
   while (getline(in, s)) 
      {
      v.push_back(s);
      }

   return v;
   }