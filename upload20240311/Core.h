/*
13-3 Add a valid function to check whether the object held values for a student record
13-4 Add a letter grade function
13-5 Add a predicate to check if a student met all the relevant requirements
13-6 Add a class to represent students taking the courses for pass/fail credit
13-7 Add a class to represent students auditing the course
14-1 Implement a comparison operation that operate on Ptr<Core>
*/
#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <iostream>
#include <algorithm>
#include "grade.h"
#include "Ptr.h"
#include "Vec.h"
#include "Str.h"

class Core 
   {
   template <class T> friend class Ptr;
   template <class T> friend T* clone(const T*);
   public:
      // default constructor for Core
      Core(): midterm(0),final(0)
         {        
         }
      // build a Core from an istream
      Core(std::istream& is)
         {
         read(is);
         }
      virtual ~Core()
         {
         }
      Str name() const
         {
         return n; 
         }
      virtual std::istream& read(std::istream&);
      virtual double grade() const;
      virtual void regrade(double, double);
      // 13-3 Add a valid function to check whether the object held values
      virtual bool valid() const;
      // 13-4 Add a letter grade function
      virtual Str letter_grade() const;
      // 13-5 Add a predicate to check if a student met all the requirements
      virtual bool met_reqs() const;
   protected:
      std::istream& read_common(std::istream&);
      double midterm, final;
      Vec<double> homework;
      virtual Core* clone() const
         {
         return new Core(*this);
         }
      Str n;
   };

class Grad: public Core 
   {
   public:
      Grad(): thesis(0)
         {
         }
      Grad(std::istream& is)
         {
         read(is);
         }
      std::istream& read(std::istream&);
      double grade() const;
      void regrade(double d1, double d2);
      bool met_reqs() const;
   protected:
      Grad* clone() const
         {
         return new Grad(*this);
         }
   private:
      double thesis;
   };

// 13-6 Add a class to represent students taking the courses for pass/fail credit
class PorF: public Core 
   {
   public:
      PorF()
         {
         }
      PorF(std::istream& is)
         {
         Core::read(is);
         }
      double grade() const;
      virtual bool valid() const;
      Str letter_grade() const;
      bool met_reqs() const;
   protected:
      PorF* clone() const
         {
         return new PorF(*this);
         }
   };

// 13-7 Add a class to represent students auditing the course
class Audit: public Core 
   {
   public:
      Audit()
         {
         }
      Audit(std::istream& is)
         {
         Core::read(is);
         }
      double grade() const;
      virtual bool valid() const;
      Str letter_grade() const;
      bool met_reqs() const;
   protected:
      Audit* clone() const
         {
         return new Audit(*this);
         }
   };

// 14-1 Implement a comparison operation that operate on Ptr<Core>
bool compare_Core_handles(const Ptr<Core>, const Ptr<Core>);

std::istream& read_hw(std::istream&, Vec<double>&);

#endif