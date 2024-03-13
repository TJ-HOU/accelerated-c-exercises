#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <iostream>
#include <memory>
#include <iterator>
#include "Vec.h"
#include "Ptr.h"

// the key to making Ptr< Vec<char> > work
template<>
Vec<char>* clone(const Vec<char>* vp)
   {
   return new Vec<char>(*vp);
   }

class Str 
   {
   friend std::istream& operator>>(std::istream&, Str&);
   friend std::istream& getline(std::istream&, Str&); 
   public:
      typedef size_t size_type;
      typedef char* iterator;
      typedef const char* const_iterator; 
      // constructor 
      Str(): data(new Vec<char>) 
         {
         }
      Str(const char* cp): data(new Vec<char>)
         {
         std::copy(cp, cp + std::strlen(cp),
         std::back_inserter(*data));
         }
      Str(size_type n, char c): data(new Vec<char>(n, c)) 
         {
         }
      template<class In> 
      Str(In i, In j): data(new Vec<char>) 
         {
         std::copy(i, j, std::back_inserter(*data));
         }

      // index operations
      char& operator[](size_type i) 
         { 
         data.make_unique();
         return (*data)[i]; 
         }
      const char& operator[](size_type i) const 
         { 
         return (*data)[i]; 
         }
      
      size_type size() const 
         { 
         return data->size();
         }

      Str& operator+=(const Str& s)
         {
         data.make_unique();
         std::copy(s.data->begin(), s.data->end(),
         std::back_inserter(*data));
         return *this;
         }
      iterator begin() 
         { 
         return data->begin(); 
         } 
      const_iterator begin() const 
         { 
         return data->begin();  
         } 
      iterator end() 
         { 
         return data->end(); 
         } 
      const_iterator end() const 
         { 
         return data->end(); 
         }

   private:
      Ptr< Vec<char> > data;
   };

Str operator +(const Str& s, const Str& t) 
   {
   Str r = s;
   r += t;
   return r;
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
#endif