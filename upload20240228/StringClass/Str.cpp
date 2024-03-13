#include "Str.h"

// Q1
void Str::create(size_type n, const char& val)
   {
   length = n + 1;
   value = alloc.allocate(length);
   std::uninitialized_fill(value, value + length - 1, val);
   alloc.construct(value + length - 1, '\0');
   }
void Str::uncreate()
   {
   if (value) 
      {
      // destroy (in reverse order) the elements that were constructed
      iterator it = value + length;
      while (it != value)
         {
         alloc.destroy(--it);
         }
      // return all the space that was allocated
      alloc.deallocate(value, length);
      }
   // reset pointers to indicate that the array is empty again
   value = 0;
   length = 0;
   }
Str& Str::operator=(const Str& rhs)
   {
   // check for self-assignment
   if (&rhs != this) 
      {
      uncreate();
      create(rhs.begin(),rhs.end());
      }
   return *this;
   }

// Q2
// In C++11 onwards, data and c_str are the same.
// In this practice, pretend that data() return the array that is not null terminated. 
const char* Str::data()
   { 
   iterator newvalue = value;
   std::uninitialized_copy(value, value + length - 1, newvalue);
   return newvalue;
   }
Str& Str::copy(char* cp, size_type n)
   {
   std::uninitialized_copy(value, value + n, cp);
   alloc.construct(value + n, '\0'); 
   return *this;
   }

// Q3
bool operator<(const Str& lhs, const Str& rhs) 
   {
   return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
   }
bool operator>=(const Str& lhs, const Str& rhs) 
   {
   return !std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
   }
bool operator>(const Str& lhs, const Str& rhs) 
   {
   return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
   }
bool operator<=(const Str& lhs, const Str& rhs) 
   {
   return !std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
   }

// Q4
bool operator==(const Str& lhs, const Str& rhs) 
   {
   return (lhs>=rhs && lhs<=rhs);
   }
bool operator!=(const Str& lhs, const Str& rhs) 
   {
   return !(lhs==rhs);
   }

// Q5
Str& Str::operator+=(const Str& s) 
   {
   size_type newlength = length + s.size();
   iterator newvalue = alloc.allocate(newlength); 
   std::uninitialized_copy(value, value + length - 1, newvalue);
   std::uninitialized_copy(s.begin(), s.end(), newvalue + length - 1);
   alloc.construct(newvalue + newlength - 1, '\0');
   uncreate();
   length = newlength;
   value = newvalue;
   return *this;
   }

Str operator +(const Str& s, const Str& t) 
   {
   Str r = s;
   r += t;
   return r;
   }
Str operator +(const char* c, const Str& s) 
   {
   Str r(c);
   r += s;
   return r;
   }
Str operator +(const Str& s, const char* c) 
   {
   Str r = s;
   r += Str(c);
   return r;
   }

// Q8
std::istream& getline(std::istream& input, Str& line) 
   {
   char c;
   line.clear();
   line = Str(0,'\0');
   // Read characters until newline or end-of-file
   while (input.get(c) && c != '\n') 
      {
      line += Str(1,c);
      }
   return input;
   }

// Q9
std::ostream& operator<<(std::ostream& os, const Str& s)
   {
   std::copy(s.begin(), s.end(), std::ostream_iterator<char>(os));
   return os;
   }
std::istream& operator>>(std::istream& is, Str& s)
   {
   // obliterate existing value(s)
   s.clear();
   s = Str(0,'\0');
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