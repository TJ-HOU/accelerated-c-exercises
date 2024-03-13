#include "Student_info.h"
#include <iostream>
using std::istream;

std::istream& Student_info::read(istream& is) 
   {
   char ch;
   is >> ch;
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

Str Student_info::name() const 
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

double Student_info::grade() const 
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

bool Student_info::valid() const 
   { 
   if(!cp->valid())
      {
      throw std::domain_error("incomplete student record");
      } 
   return true;
   }

Str Student_info::letter_grade() const 
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
   
bool Student_info::met_reqs() const 
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
   
bool Student_info::compare(const Student_info& s1, const Student_info& s2) 
   {
   return s1.name() < s2.name(); 
   }

void Student_info::regrade(double final, double thesis)
   {
   // get our own copy before changing the object
   cp.make_unique();
   if (cp)
      {
      cp->regrade(final, thesis);
      }
   else 
      {
      throw std::runtime_error("regrade of unknown student");
      }
   }
