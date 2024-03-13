#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

#include "RefCtr.h"
#include <stdexcept>

template<class T> T* clone(const T* tp)
   {
   return tp->clone();
   }

template<class T> class Ptr 
   {
   public:
      // new member to copy the object conditionally when needed 
      void make_unique() 
         {
         if (refptr.val()!= 1) 
            {
            --refptr;
            refptr = RefCtr();
            // calls the nonmember clone function which in turn
            // calls the clone member of the for the object to which p points to
            p = p ? clone(p) : 0; 
            }
         }
      // the rest of the class looks like Ref_handle except for its name
      Ptr(): p(0) 
         { 
         }
      Ptr(T* t): p(t) 
         { 
         }
      Ptr(const Ptr& h): refptr(h.refptr), p(h.p) 
         { 
         ++refptr; 
         }
      Ptr& operator=(const Ptr&) ; // implemented analogously to §14.2/261
      ~Ptr(); // implemented analogously to §14.2/262
      operator bool() const 
         {
         return p; 
         }
      T& operator*() const; // implemented analogously to §14.2/261
      T* operator->() const; // implemented analogously to §14.2/261
   private:
      T* p;
      RefCtr refptr;
   };

template<class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
   {
   if (&rhs!=this)
      {
      --refptr;
      // free the left-hand side, destroying pointers if appropriate 
      if (refptr.val() == 0) // --i returns the value after it is decremented
         {
         delete p;
         }
      // copy in values from the right-hand side 
      refptr = rhs.refptr;
      p = rhs.p;
      ++refptr;
      }
   return *this;
   }

template<class T> 
Ptr<T>::~Ptr()
   {
   --refptr;
   if (refptr.val() == 0) 
      {
      delete p;
      }
   }

template<class T> 
T& Ptr<T>::operator*() const
   {
   if (p)
      {
      return *p;
      }
   throw std::runtime_error("unbound Ptr");
   }

template<class T> 
T* Ptr<T>::operator->() const 
   {
   if (p)
      {
      return p;
      }
   throw std::runtime_error("unbound Ptr");
   }

#endif