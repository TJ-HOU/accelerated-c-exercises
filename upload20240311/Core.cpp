#include "Core.h"
#include "grade.h"

using std::istream;
using std::min;

// Core
istream& Core::read_common(istream& in)
   {
   // read and store the student's name and exam grades
   in >> n >> midterm >> final;
   return in;
   }
istream& Core::read(istream& in)
   {
   read_common(in);
   read_hw(in, homework);
   return in;
   }
double Core::grade() const
   {
   return ::grade(midterm, final, homework);
   }
void Core::regrade(double d1, double d2 = 0)
   {
   final = d1;
   }
// 13-3 Add a valid function to check whether the object held values for a student record
bool Core::valid() const 
   { 
   return !homework.empty(); 
   }
// 13-4 Add a letter grade function
Str Core::letter_grade() const
   {
   return ::letter_grade(grade());
   }
// 13-5 Add a predicate to check if a student met all the relevant requirements
bool Core::met_reqs() const 
   { 
   return (std::find(homework.begin(), homework.end(), 0.0) == homework.end()); 
   }

// Grad
istream& Grad::read(istream& in)
   {
   read_common(in);
   in >> thesis;
   read_hw(in, homework);
   return in;
   }
double Grad::grade() const
   {
   return std::min(Core::grade(), thesis);
   }
void Grad::regrade(double d1, double d2)
   {
   final = d1;
   thesis = d2;
   }
bool Grad::met_reqs() const 
   { 
   return (Core::met_reqs() && thesis > 0.0); 
   }

// 13-6 Add a class to represent students taking the courses for pass/fail credit
double PorF::grade() const
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
bool PorF::valid() const 
   { 
   return true; 
   }
Str PorF::letter_grade() const
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
bool PorF::met_reqs() const 
   { 
   return true; 
   }

// 13-7 Add a class to represent students auditing the course
double Audit::grade() const
   {
   return 0.0;
   }
bool Audit::valid() const 
   { 
   return true; 
   }
Str Audit::letter_grade() const
   {
   return "Audit";
   }
bool Audit::met_reqs() const 
   { 
   return true; 
   }

// 14-1 Implement a comparison operation that operate on Ptr<Core>  
bool compare_Core_handles(const Ptr<Core> cp1, const Ptr<Core> cp2)
   {
   return cp1->name() < cp2->name();
   } 

// read homework grades from an input stream into a vector<double>
std::istream& read_hw(std::istream& in, Vec<double>& hw) 
   {
   if (in) 
      {
      // get rid of previous contents 
      hw.clear() ;

      // read homework grades 
      double x;
      while (in >> x)
      {
      hw.push_back(x);
      }
      
      // clear the stream so that input will work for the next student
      in.clear();   
      }
   
   return in;
   }