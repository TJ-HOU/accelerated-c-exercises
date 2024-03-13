// 14-2 Implement the Student_info class using Ptr<Core> objects
#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include "Str.h"
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
      std::istream& read(std::istream&);
      Str name() const;
      double grade() const;     
      bool valid() const;
      Str letter_grade() const;
      bool met_reqs() const;         
      static bool compare(const Student_info&, const Student_info&);     
      void regrade(double, double);
   private:
      Ptr<Core> cp;
   };

#endif