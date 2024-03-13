// Copy from previous exercises
#ifndef GUARD_Vec_h
#define GUARD_Vec_h 

#include <memory>
#include <iostream>
#include <cstddef>

template <class T> class Vec 
   {
   public:
   typedef T* iterator; 
   typedef const T* const_iterator; 
   typedef size_t size_type; 
   typedef T value_type; 

   Vec() 
      { 
      create(); 
      }
   explicit Vec(size_type n, const T& val = T()) 
      { 
      create(n, val); 
      }
   Vec (const Vec& v) // copy constructor
      { 
      create(v.begin(), v.end());
      } 

   Vec& operator=(const Vec&);
   ~Vec() 
      { 
      uncreate(); 
      }

   T& operator[](size_type i) 
      { 
      return data[i]; 
      }
   const T& operator[](size_type i) const 
      { 
      return data[i]; 
      }

   void push_back(const T& val) 
      {
      if (avail == limit) // get space if needed
         {
         grow();
         }
      unchecked_append(val) ; // append the new element
      }
   size_type size() const 
      { 
      return avail - data; 
      }

   iterator begin() 
      { 
      return data; 
      } 
   const_iterator begin() const 
      { 
      return data; 
      } 
   iterator end() 
      { 
      return avail; 
      } 
   const_iterator end() const 
      { 
      return avail; 
      } 

   // 11-6
   // erase returns an iterator that is positioned on th element that follows the one that we just erased
   iterator erase(iterator position) 
      {
      for (iterator i = position; i != avail; ++i) 
         {
         alloc.destroy(i);
         if ((i + 1) != avail) 
            {
            alloc.construct(i, *(i + 1));
            }
         }
      --avail;
      return position;
      }

   // 11-6
   // empty the contatiner
   void clear() 
      { 
      uncreate(); 
      }

   bool empty() const
      {
      return (data == avail);
      } 
   
   // 12-12
   template<class In>
   void insert(iterator pos, In first, In last) 
      {
      size_type newlength = (limit - data) + (last - first);
      iterator newdata = alloc.allocate(newlength);
      iterator newavail = newdata + (avail-data) + (last - first);
      iterator newlimit = newdata + (limit-data) + (last - first);
      std::uninitialized_copy(data, pos, newdata);
      std::uninitialized_copy(first, last, newdata + (pos - data));
      std::uninitialized_copy(pos, avail, newdata + (pos - data) + (last - first));
      uncreate();
      data = newdata;
      avail = newavail;
      limit = newlimit;
      }

   private:
   iterator data; // first element in the Vec
   iterator avail; // (one past) the last element in the Vec
   iterator limit; // (one past) the allocated memory

   // facilities for memory allocation
   std::allocator<T> alloc; // object to handle memory allocation

   // allocate and initialize the underlying array
   void create() ;
   void create(size_type, const T&);
   void create(const_iterator, const_iterator);

   // destroy the elements in the array and free the memory
   void uncreate();

   // support functions for push_back
   void grow();
   void unchecked_append(const T&);
   };

template <class T> 
Vec<T>& Vec<T>::operator=(const Vec& rhs)
   {
    // check for self-assignment
    if (&rhs != this) 
       {
        // free the array in the left-hand side
        uncreate();
        // copy elements from the right-hand to the left-hand side
        create(rhs.begin(),rhs.end());
       }
    return *this;
   }

template <class T> void Vec<T>::create()
   {
   data = 0;
   limit = 0;
   avail = 0;
   }

template <class T> void Vec<T>::create(size_type n, const T& val)
   {
   data = alloc.allocate(n);
   avail = data + n;
   limit = avail;
   std::uninitialized_fill(data, limit, val);
   }

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
   {
   data = alloc.allocate(j - i);
   avail = std::uninitialized_copy(i, j, data);
   limit = avail;
   }

template <class T> void Vec<T>::uncreate()
   {
   if (data) 
      {
      // destroy (in reverse order) the elements that were constructed
      iterator it = avail;
      while (it != data)
         {
         alloc.destroy(--it);
         }
      // return all the space that was allocated
      alloc.deallocate(data, limit - data);
      }
   // reset pointers to indicate that the Vec is empty again
   data = 0;
   limit = 0;
   avail = 0;
   }

template <class T> void Vec<T>::grow()
   {
   // when growing, allocate twice as much space as currently in use
   // type ptrdiff_t is thet ype of limite-data
   size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

   // allocate new space and copy existing elements to the new space
   iterator new_data = alloc.allocate(new_size);
   iterator new_avail = std::uninitialized_copy(data, avail, new_data);

   // return the old space
   uncreate();

   // reset pointers to point to the newly allocated space
   data = new_data;
   avail = new_avail; 
   limit = data + new_size;
   }

// assumes avail points at allocated, but uninitialized space
template <class T> void Vec<T>::unchecked_append(const T& val)
   {
   alloc.construct(avail++, val);
   }

#endif
