/*
Chapter 12: Create the Str class
Q1 The class should manage the storage itself. Hint: store an array of char and a length.
Q2 Implement the c_str, data, and copy functions.
Q3 Define the relational operators (>,<,>=,<=).
Q4 Define the equality and inequality operators (==,!=).
Q5 Implement concatenation for Str (Str+Str,char+Str,Str+char).
Q6 Define a conversion operator, allowing Str objects to be used as if they were of type bool.
Q7 Add iterators and the iterator operations begin and end to the Str class.
Q8 Add the getline function to the Str class.
Q9 Use class ostream_iterator to reimplement the Str output operator.
Q12 Define the insert function that takes 2 iterators for the Str class.
*/

#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <iostream>
#include <memory>
#include <iterator>

class Str 
   {
   friend std::istream& operator>>(std::istream&, Str&);
   friend std::istream& getline(std::istream&, Str&);
   public:
      typedef size_t size_type;
      typedef char* iterator;
      typedef const char* const_iterator; 

      // constructor 
      Str() 
         {
         create(0, '\0');
         }
      Str(size_type n, char c) 
         {
         create(n, c); 
         }
      Str(const Str& s) 
         { 
         create(s.begin(), s.end()); 
         }
      Str(const char* cp) 
         {
         // strlen doesn't include the last null element
         create(cp, cp + strlen(cp));
         }
      template<class In> Str(In b, In e) 
         {
         create(b, e);
         }

      // deconstructor
      ~Str() 
         { 
         uncreate(); 
         }

      // assignment constructor
      Str& operator = (const Str& s);

      // index operations
      char& operator[](size_type i) 
         { 
         return value[i]; 
         }
      const char& operator[](size_type i) const 
         { 
         return value[i]; 
         }
      
      size_type size() const 
         { 
         return length - 1;
         }

      void clear() 
         { 
         uncreate(); 
         }

      Str& operator+=(const Str&);

      // Q2
      const char* c_str() 
         {
         return value;
         }
      const char* data();
      Str& copy(char*, size_type);

      // Q6
      operator bool() const 
         { 
         return (size() > 0); 
         }

      // Q7
      iterator begin() 
         { 
         return value; 
         } 
      const_iterator begin() const 
         { 
         return value; 
         } 
      iterator end() 
         { 
         return value + length - 1; 
         } 
      const_iterator end() const 
         { 
         return value + length - 1; 
         }

      // Q12
      template<class In>
      void insert(iterator pos, In first, In last) 
         {
         size_type newlength = length + last - first;
         iterator newvalue = alloc.allocate(newlength); 
         std::uninitialized_copy(value, pos, newvalue);
         std::uninitialized_copy(first, last, newvalue + (pos - value)); 
         std::uninitialized_copy(pos, value + length - 1, newvalue + (pos - value) + (last - first));  
         alloc.construct(newvalue + newlength - 1, '\0');
         uncreate();
         length = newlength;
         value = newvalue;
         }
   private:
      // chars is null-terminated, has length - 1 non-null chars
      size_type length;
      char* value;

      // facilities for memory allocation
      std::allocator<char> alloc; // object to handle memory allocation

      // allocate and initialize the underlying array
      void create(size_type, const char&);
      template<class In>
      void create(In, In);

      // destroy the elements in the array and free the memory
      void uncreate();
   };

template <class In> 
void Str::create(In i, In j) 
   {
   length = j - i + 1;
   value = alloc.allocate(length);
   std::uninitialized_copy(i, j, value);
   alloc.construct(value + length - 1, '\0');
   } 

// Q3
bool operator<(const Str&, const Str&);
bool operator>=(const Str&, const Str&); 
bool operator>(const Str&, const Str&);
bool operator<=(const Str&, const Str&); 

// Q4
bool operator==(const Str&, const Str&); 
bool operator!=(const Str&, const Str&);

// Q5
Str operator +(const Str&, const Str&);
Str operator +(const char*, const Str&);
Str operator +(const Str&, const char*);

// Q8
std::istream& getline(std::istream&, Str&);

// Q9
std::ostream& operator<<(std::ostream&, const Str&);
std::istream& operator>>(std::istream&, Str&);

#endif