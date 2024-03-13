#include <stdexcept>
#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>
#include "grade.h"
#include "math.h"
#include "Student_info.h"

using std::domain_error; 
using std::vector;
using std::ostream;
using std::string;
using std::endl;
using std::cout;
using std::left;
using std::setw;

// compute students' overall grades with selected grading schemes 
// and return the median of the overall grades of all students
double analysis(const vector<Student_info>& students, double scheme(const Student_info&))
   {
   vector<double> grades;
   transform(students.begin(), students.end(),
   back_inserter(grades), scheme);
   if (grades.empty())
      {
      return 0; 
      }
   return median(grades);
   }

