/*
13-3 Add a valid function
13-4 Add a letter grade function
13-5 Add a predicate to check if a student met all the relevant requirements
13-6 Add a class to represent students taking the courses for pass/fail credit
13-7 Add a class to represent students auditing the course
13-8 Write a program to generate a grade report that can handle all 4 kinds of students
*/
#ifndef GUARD_Core
#define GUARD_Core

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "grade.h"

class Core 
   {
   friend class Student_info;
   public:
      // default constructor for Core
      Core(): midterm(0),final(0)
         { 
         //std::cerr << "Core::Core()" << std::endl;        
         }
      // build a Core from an istream
      Core(std::istream& is)
         {
         read(is);
         //std::cerr << "Core::Core(istream&)" << std::endl;
         }
      virtual ~Core()
         {
         //std::cerr << "~Core()" << std::endl;
         }
      std::string name() const
         {
         //std::cerr << "name()" << std::endl;
         return n; 
         }
      virtual std::istream& read(std::istream&);
      virtual double grade() const
         {
         //std::cerr << "Core::grade()" << std::endl;
         return ::grade(midterm, final, homework);
         }
      // Exercise 13-3
      virtual bool valid() const 
         { 
         return !homework.empty(); 
         }
      // Exercise 13-4
      virtual std::string letter_grade() const
         {
         return ::letter_grade(grade());
         }
      // Exercise 13-5
      virtual bool met_reqs() const 
         { 
         return (std::find(homework.begin(), homework.end(), 0.0) == homework.end()); 
         }
   protected:
      std::istream& read_common(std::istream&);
      double midterm, final;
      std::vector<double> homework;
      virtual Core* clone() const
         {
         //std::cerr << "Core* clone()" << std::endl;
         return new Core(*this);
         }
      std::string n;
   };

class Grad: public Core 
   {
   public:
      // both constructors implicitly use Core::Core() to initialize the base part
      Grad(): thesis(0)
         {
         //std::cerr << "Grad::Grad()" << std::endl;
         }
      Grad(std::istream& is)
         {
         read(is);
         //std::cerr << "Grad::Grad(istream&)" << std::endl;
         }
      double grade() const
         {
         //std::cerr << "Grad::grade()" << std::endl;
         return std::min(Core::grade(), thesis);
         }
      std::istream& read(std::istream&);
      // Exercise 13-5
      bool met_reqs() const 
         { 
         return (Core::met_reqs() && thesis > 0.0); 
         }
   protected:
      Grad* clone() const
         {
         //std::cerr << "Grad* clone()" << std::endl;
         return new Grad(*this);
         }
   private:
      double thesis;
   };

// Exercise 13-6
class PorF: public Core 
   {
   public:
      // both constructors implicitly use Core::Core() to initialize the base part
      PorF()
         {
         }
      PorF(std::istream& is)
         {
         Core::read(is);
         }
      double grade() const
         {
         if(!homework.empty())
            {
            return ::grade(midterm, final, homework);
            }
         else
            {
            return 0.5 * (midterm + final);
            }
         }
      std::string letter_grade() const
         {
         if (PorF::grade() >= 60)
            {
            return "P";
            }
         else
            {
            return "F";
            }
         }
      // Exercise 13-3
      virtual bool valid() const 
         { 
         return true; 
         }
      // Exercise 13-5
      bool met_reqs() const 
         { 
         return true; 
         }
   protected:
      PorF* clone() const
         {
         return new PorF(*this);
         }
   };
// Exercise 13-7
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
      //std::istream& read(std::istream&);
      double grade() const
         {
         return 0.0;
         }
      std::string letter_grade() const
         {
         return "Audit";
         }
      // Exercise 13-3
      virtual bool valid() const 
         { 
         return true; 
         }
      // Exercise 13-5
      bool met_reqs() const 
         { 
         return true; 
         }
   protected:
      Audit* clone() const
         {
         return new Audit(*this);
         }
   };

// Exercise 13-8
class Student_info 
   {
   public:
      // constructors and copy control
      Student_info(): cp(0) 
         {
         //std::cerr << "Student_info::Student_info()" << std::endl;
         }
      Student_info(std::istream& is): cp(0) 
         {
         read(is); 
         //std::cerr << "Student_info::Student_info(istream&)" << std::endl;
         }
      Student_info(const Student_info&);
      Student_info& operator=(const Student_info&);
      ~Student_info() 
         {
         delete cp; 
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
      bool valid() const 
         { 
         if(!cp->valid())
            {
            throw std::domain_error("incomplete student record");
            } 
         return true;
         }
      std::string letter_grade() const 
         {
         if (cp) 
            {
            return cp->letter_grade();
            }
         else 
            {
            throw std::runtime_error("uninitialized Student");
            }
         }
      bool met_reqs() const 
         { 
         if (cp) 
            {
            return cp->met_reqs();
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
   protected:
      Student_info* clone() const
         {
         return new Student_info(*this);
         }
   private:
      Core* cp;
   };

bool compare(const Core&, const Core&);
bool compare_grades(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);
// read homework grades from an input stream into a vector<double>
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif