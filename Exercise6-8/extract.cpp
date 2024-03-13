#include "Student_info.h"
#include "math.h"
#include "grade.h"
#include "extract.h"
#include <algorithm>
#include <iterator>

using std::istream; 
using std::list;
using std::vector;

// extract info of students who meet the criteria
vector<Student_info>
extract(vector<Student_info> students, bool criteria(const Student_info&))
   {
   vector<Student_info>::iterator iter =
   stable_partition(students.begin(), students.end(), criteria);
   vector<Student_info> ret(students.begin(), iter);
   //students.erase(iter, students.end());
   return ret;
   }

// predicate to determine whether a student failed 
bool fgrade(const Student_info& s)
   {
   return median_grade(s) < 60;
   }

// predicate to determine whether a student passed
bool pgrade(const Student_info& s)
   {
   return median_grade(s) >= 60;
   }

// predicate to determine whether a student did all homework
bool did_all_hw(const Student_info& s)
   {
   if (s.homework.empty())
      {
      return false;
      }
   else
      {
      return ((find(s.homework.begin(), s.homework.end(), 0))
         == s.homework.end());
      }
   }

// predicate to determine whether a student didn't do all homework
bool didnt_all_hw(const Student_info& s)
   {
   if (s.homework.empty())
      {
      return true;
      }
   else
      {
      return ((find(s.homework.begin(), s.homework.end(), 0))
         != s.homework.end());
      }
   }

