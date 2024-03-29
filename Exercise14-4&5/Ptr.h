#ifndef GUARD_Ptr
#define GUARD_Ptr

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
         if (*refptr != 1) 
            {
            --*refptr;
            refptr = new size_t(1);
            // calls the nonmember clone function which in turn
            // calls the clone member of the for the object to which p points to
            p = p ? clone(p) : 0; 
            }
         }
      // the rest of the class looks like Ref_handle except for its name
      Ptr(): refptr(new size_t(1)), p(0) 
         { 
         }
      Ptr(T* t): refptr(new size_t(1)), p(t) 
         { 
         }
      Ptr(const Ptr& h): refptr(h.refptr), p(h.p) 
         { 
         ++*refptr; 
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
      size_t* refptr;
   };

template<class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
   {
   ++*rhs.refptr;
   // free the left-hand side, destroying pointers if appropriate 
   if (--*refptr == 0) // --i returns the value after it is decremented
      {
      delete refptr;
      delete p;
      }
   // copy in values from the right-hand side 
   refptr = rhs.refptr;
   p = rhs.p;
   return *this;
   }

template<class T> 
Ptr<T>::~Ptr()
   {
   if (--*refptr == 0) 
      {
      delete refptr;
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