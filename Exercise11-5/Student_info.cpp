#include <iostream>
#include <vector>

#include "Student_info.h"
#include "grade.h"

using std::istream; 
using std::vector;

Student_info::Student_info(): midterm(0), final(0) 
   {
   std::cout << "create" << std::endl;
   }
Student_info::Student_info(istream& is) 
   { 
   read(is);
   std::cout << "create" << std::endl;
   }

double Student_info::grade() const
   {
   return ::grade(midterm, final, homework);
   }

bool compare(const Student_info& x, const Student_info& y)
   {
   return x.name() < y.name();
   }

// read homework grades from an input stream into a vector<double>
istream& Student_info::read_hw(istream& in, vector<double>& hw) 
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
   return in;
   }
