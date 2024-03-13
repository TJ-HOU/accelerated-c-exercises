#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>
#include "grade.h"
#include "math.h"
#include "Student_info.h"

using std::vector;
using std::ostream;
using std::string;
using std::endl;
using std::cout;

// compute a student's overall grade from midterm, final, and an overall homework grade
double grade(double midterm, double final, double homework)
   {
   return 0.2 * midterm + 0.4 * final + 0.4 * homework;
   }

// compute a student's overall grade from midterm, final, and median of homework grade 
double median_grade(const Student_info& s)
   {
   if (s.homework.empty())
      {
      return grade(s.midterm, s.final, 0); 
      }
   return grade(s.midterm, s.final, median(s.homework));
   }

// compute a student's overall grade from midterm, final, and median of submitted homework grade 
double optimistic_median(const Student_info& s)
   {
   if (s.homework.empty())
      {
      return grade(s.midterm, s.final, 0); 
      }
   else
      {
      vector<double> nonzero;

      // copy nonzero elements from vector s to vector nonzero
      remove_copy(s.homework.begin(), s.homework.end(),
      back_inserter(nonzero), 0);

      if (!nonzero.empty())
         {
         return grade(s.midterm, s.final, median(nonzero));
         }
      return(grade(s.midterm, s.final, median(s.homework)));
      }
   }

// compute a student's overall grade from midterm, final, and average of homework grade
double average_grade(const Student_info& s)
   {
   if (s.homework.empty())
      {
      return grade(s.midterm, s.final, 0); 
      }
   return grade(s.midterm, s.final, average(s.homework));
   }
