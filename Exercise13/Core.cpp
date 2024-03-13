#include "Core.h"
#include "grade.h"

using std::string;
using std::istream;
using std::min;

istream& Core::read_common(istream& in)
   {
   //std::cerr << "Core::read_common(istream&)" << std::endl;
   // read and store the student's name and exam grades
   in >> n >> midterm >> final;
   return in;
   }
istream& Core::read(istream& in)
   {
   //std::cerr << "Core::read(istream&)" << std::endl;
   read_common(in);
   read_hw(in, homework);
   return in;
   }

istream& Grad::read(istream& in)
   {
   //std::cerr << "Grad::read(istream&)" << std::endl;
   read_common(in);
   in >> thesis;
   read_hw(in, homework);
   return in;
   }

/* istream& Audit::read(istream& in)
   {
   in >> n;
   return in;
   } */

std::istream& Student_info::read(istream& is) 
   {
   delete cp; // delete previous object, if any
   char ch;
   is >> ch; // get record type
   if (ch == 'R') 
      {
      cp = new PorF(is);
      } 
   else if(ch == 'G')
      {
      cp = new Grad(is);
      }
   else if(ch == 'V')
      {
      cp = new Audit(is);
      }
   else
      {
      cp = new Core(is);
      }
   return is;
   }
Student_info::Student_info(const Student_info& s) : cp(0)
   {
   if (s.cp) 
      {
      cp = s.cp->clone();
      }
   //std::cerr << "Student_info::Student_info(const Student_info&)" << std::endl;
   }
Student_info& Student_info::operator = (const Student_info& s)
   {
   if (&s != this) 
      {
      delete cp;
      if (s.cp)
         {
         cp = s.cp->clone();
         }
      else
         {
         cp = 0;
         }
      }
   return *this;
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