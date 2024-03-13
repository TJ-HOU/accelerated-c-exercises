#include "Core.h"
#include "grade.h"

using std::string;
using std::istream;
using std::min;

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

istream& Grad::read(istream& in)
   {
   read_common(in);
   in >> thesis;
   read_hw(in, homework);
   return in;
   }

bool compare(const Core&c1, const Core&c2)
   {
   return c1.name() < c2.name();
   };
bool compare_grades(const Core& c1, const Core& c2)
   {
   return c1.grade() < c2.grade();
   }
bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
   {
   return compare(*cp1, *cp2);
   }   
bool compare_Core_handles(const Ref_handle<Core> cp1, const Ref_handle<Core> cp2)
   {
   return compare(*cp1, *cp2);
   } 
// read homework grades from an input stream into a vector<double>
std::istream& read_hw(std::istream& in, std::vector<double>& hw) 
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