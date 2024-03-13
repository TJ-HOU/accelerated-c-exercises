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
      template<class In>void insert(iterator, In, In);
   private:
      // chars is null-terminated, has length - 1 non-null chars
      size_type length;
      char* value;

      // facilities for memory allocation
      std::allocator<char> alloc; // object to handle memory allocation

      // allocate and initialize the underlying array
      void create(size_type, const char&);
      void create(const_iterator, const_iterator);

      // destroy the elements in the array and free the memory
      void uncreate();
   };

// Q1
void Str::create(size_type n, const char& val)
   {
   length = n + 1;
   value = alloc.allocate(length);
   std::uninitialized_fill(value, value + length - 1, val);
   alloc.construct(value + length - 1, '\0');
   }
void Str::create(const_iterator i, const_iterator j)
   {
   length = j - i + 1;
   value = alloc.allocate(length);
   std::uninitialized_copy(i, j, value);
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

// Q12
template<class In>
void Str::insert(iterator pos, In first, In last) 
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

#endif