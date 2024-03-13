#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include "Ptr.h"
#include "Core.h"

class Student_info 
   {
   public:
      // constructors and copy control
      Student_info() 
         {
         }
      Student_info(std::istream& is)
         {
         read(is); 
         }

      // operations
      std::istream& read(std::istream&);

      std::string name() const 
         {
         if (cp) 
            {
            return cp->name();
            }
         else 
            {
            throw std::runtime_error("uninitialized Student");
            }
         }

      double grade() const 
         {
         if (cp) 
            {
            return cp->grade();
            }
         else 
            {
            throw std::runtime_error("uninitialized Student");
            }
         }
         
      static bool compare(const Student_info& s1, const Student_info& s2) 
         {
         return s1.name() < s2.name(); 
         }
      
      void regrade(double, double);
   private:
      Ptr<Core> cp;
   };

#endif