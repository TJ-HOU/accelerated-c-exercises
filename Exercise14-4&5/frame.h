#ifndef GUARD_frame
#define GUARD_frame

#include "Str.h"
#include "Vec.h"
#include <vector>
#include <cmath>
#include <iostream>

using std::max;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;

Str::size_type width(const Vec<Str>& v)
   {
   Str::size_type maxlen = 0;
   for (auto i = 0; i != v.size(); ++i)
      {
      maxlen = max(maxlen, v[i].size());
      }
   return maxlen;
   }

Vec<Str> frame(const Vec<Str>& v) 
   {
   Vec<Str> ret;
   Str::size_type maxlen = width(v);
   Str border(maxlen + 4, '*');

   // write the top border
   ret.push_back(border);

   // write each interior row, bordered by an asterisk and a space 
   for (auto i = 0; i != v.size(); ++i) 
      {
      ret.push_back( "* " + v[i] +
      Str(maxlen - v[i].size(), ' ') + " *");
      }

   // write the bottom border 
   ret.push_back(border);
   return ret;
   }

Vec<Str> vcat(const Vec<Str>& top, const Vec<Str>& bottom)
   {
   // copy the top picture
   Vec<Str> ret = top;

   // copy entire bottom picture
   for (auto it = bottom.begin();it != bottom.end(); ++it)
      {
      ret.push_back(*it);
      }

   return ret;
   }

Vec<Str> hcat(const Vec<Str>& left, const Vec<Str>& right)
   {
   Vec<Str> ret;

   // add 1 to leave a space between pictures
   Str::size_type width1 = width(left) + 1;

   // indices to look at elements from left and right respectively 
   Vec<Str>::size_type i = 0, j = 0;

   // continue until we've seen all rows from both pictures
   while (i != left.size() || j != right.size()) 
      {
      // construct new string to hold characters from both pictures
      Str s;

      // copy a row from the left-hand side, if there is one 
      if (i != left.size())
         {
         s = left[i++];
         }

      // pad to full width
      s += Str(width1 - s.size(), ' ');

      // copy a row from the right-hand side, if there is one
      if (j != right.size())
         {
         s += right[j++];
         }

      // add s to the picture we're creating 
      ret.push_back(s);
      }
   return ret;
   }

#endif

