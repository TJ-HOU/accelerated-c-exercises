#ifndef GUARD_RefCtr
#define GUARD_RefCtr

#include <cstddef>

class RefCtr
   {
   public:
   RefCtr():count(new std::size_t(1))
      {
      }
   RefCtr(std::size_t s):count(new std::size_t(s))
      {
      }
   RefCtr(const RefCtr& r):count(r.count)
      {
      }
   RefCtr& operator=(const RefCtr& rhs) 
      {
      if (*count <= 0)
         {
         delete count;
         }
      count = rhs.count;
      return *this;
      }
   std::size_t val()
      {
      return *count;
      }
   RefCtr& operator++()
      {
      ++*count;
      return *this;
      }
   //postfix
   RefCtr operator++(int) 
      {
      RefCtr temp = *this;
      ++(*this);
      return temp;
      }
   RefCtr& operator--()
      {
      --*count;
      return *this;
      }
   RefCtr operator--(int) 
      {
      RefCtr temp = *this;
      --(*this);
      return temp;
      }
   ~RefCtr()
      {
      if (*count<=0)
         {
         delete count;
         }
      } 
   private:
      std::size_t* count;
   };
#endif
