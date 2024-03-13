#include <stdexcept>
#include <vector>
#include <string>
#include "grade.h"
#include "median.h"

using std::domain_error; 
using std::vector;
using std::string;

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
   {
   return 0.2 * midterm + 0.4 * final + 0.4 * homework;
   }

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double>& hw)
   {
   if (hw.size() == 0)
      {
      throw domain_error("student has done no homework");
      }   
   return grade(midterm, final, median(hw));
   }

string letter_grade(double midterm, double final)
   {
   if (0.5 * (midterm + final) > 60)
      {
      return "P";
      }
   else
      {
      return "F";
      }
   }

