#include <stdexcept>
#include <vector>
#include <iostream>
#include <numeric>
#include "grade.h"
#include "median.h"

using std::domain_error; using std::vector;
using std::ostream;
using std::string;
using std::endl;

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

std::string letter_grade(double g)
   {
   static const double numbers[] = 
   {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
   static const char* const letters[] = 
   {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
   static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
   for (size_t i = 0; i < ngrades; ++i) 
      {
      if (g >= numbers[i])
         {
         return letters[i];
         }   
      }
   return "?\?\?";
   }
