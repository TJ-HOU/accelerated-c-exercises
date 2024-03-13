#include "Str.h"

Str& Str::operator+=(const Str& s)
   {
   data.make_unique();
   std::copy(s.data->begin(), s.data->end(),
   std::back_inserter(*data));
   return *this;
   }

Str operator +(const Str& s, const Str& t) 
   {
   Str r = s;
   r += t;
   return r;
   }

bool operator<(const Str& lhs, const Str& rhs) 
   {
   return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
   }

std::istream& operator>>(std::istream& is, Str& s)
   {
   // obliterate existing value(s)
   s.data->clear();

   // read and discard leading whitespace
   char c;
   while (is.get(c) && isspace(c))
      {
      ; // nothing to do, except testing the condition
      }
   // if still something to read, do so until next whitespace character
   if(is) 
      {
      do 
         {
         s += Str(1,c);
         }
      while (is.get(c) && !isspace(c));
      // if we read whitespace, then put it back on the stream
      if (is)
         {
         is.unget();
         }
      }
   return is;
   } 

std::ostream& operator<<(std::ostream& os, const Str& s) 
   {
   for (auto i = 0; i != s.size(); ++i) 
      {
      os << s[i];
      }
   return os;
   }

std::istream& getline(std::istream& input, Str& line) 
   {
   char c;
   line.data->clear();
   // Read characters until newline or end-of-file
   while (input.get(c) && c != '\n') 
      {
      line += Str(1,c);
      }
   return input;
   }