#ifndef GUARD_Core
#define GUARD_Core

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "grade.h"
#include "Ref_handle.h"

class Core 
   {
   template <class T> friend class Ref_handle;
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
      std::string name() const
         {
         return n; 
         }
      virtual std::istream& read(std::istream&);
      virtual double grade() const
         {
         return ::grade(midterm, final, homework);
         }
      virtual void regrade(double d1, double d2 = 0)
         {
         final = d1;
         }
   protected:
      std::istream& read_common(std::istream&);
      double midterm, final;
      std::vector<double> homework;
      virtual Core* clone() const
         {
         return new Core(*this);
         }
   private:
      std::string n;
   };

class Grad: public Core 
   {
   public:
      // both constructors implicitly use Core::Core() to initialize the base part
      Grad(): thesis(0)
         {
         }
      Grad(std::istream& is)
         {
         read(is);
         }
      double grade() const
         {
         return std::min(Core::grade(), thesis);
         }
      std::istream& read(std::istream&);
      void regrade(double d1, double d2)
         {
         final = d1;
         thesis = d2;
         }
   protected:
      Grad* clone() const
         {
         return new Grad(*this);
         }
   private:
      double thesis;
   };

bool compare(const Core&, const Core&);
bool compare_grades(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);
bool compare_Core_handles(const Ref_handle<Core>, const Ref_handle<Core>);
// read homework grades from an input stream into a vector<double>
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif