#include <iostream>
#include <vector>

#include "Student_info.h"
#include "grade.h"

using std::istream; 
using std::vector;
using std::string;

Student_info::Student_info(): midterm(0), final(0), f(0)
   {
   }
Student_info::Student_info(istream& is) 
   { 
   read(is);
   }

string Student_info::letter_grade() const
   {
   return ::letter_grade(midterm, final);
   }

bool name_compare(const Student_info& x, const Student_info& y)
   {
   return x.name() < y.name();
   }

bool lg_compare(const Student_info& x, const Student_info& y)
   {
   return !(x.letter_grade() < y.letter_grade());
   }

// read homework grades from an input stream into a vector<double>
istream& Student_info::read_hw(istream& in, vector<double>& hw) // Exercise 9.7
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

istream& Student_info::read(istream& in)
   {
   in >> n >> midterm >> final;
   read_hw(in, homework);
   if (valid()) // Exercise 9.4
      {
      f = ::grade(midterm, final, homework); // Exercise 9.1
      }
   else
      {
      f = ::grade(midterm, final, 0);   
      }
   return in;
   }
