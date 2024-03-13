// 14-4 Use Ptr class to reimplement Str
#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <iostream>
#include <memory>
#include <iterator>
#include "Vec.h"
#include "Ptr.h"

// the key to making Ptr< Vec<char> > work
template<>
inline Vec<char>* clone(const Vec<char>* vp)
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
         std::copy(cp, cp + std::strlen(cp), std::back_inserter(*data));
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

      Str& operator+=(const Str&);
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

Str operator +(const Str&, const Str&);
bool operator<(const Str&, const Str&);
std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);
std::istream& getline(std::istream&, Str&);
#endif