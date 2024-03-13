/*
10.1 Rewrite the student-grading program from §9.6/166 to generate letter grades.
10.2 Rewrite the median function from §8.1.1/140 so that we can call it with either a vector or
a built-in array. The function should allow containers of any arithmetic type.
10.3 Write a test program to verify that the median function operates correctly. Ensure that
calling median does not change the order of the elements in the container.
*/
#include "Student_info.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::domain_error;
using std::setprecision;
using std::streamsize;

int main()
   {
   vector<Student_info> students;
   Student_info record;
   string::size_type maxlen = 0;

   // read and store the data
   while (record.read(cin)) 
      { 
      maxlen = max(maxlen, record.name().size()); 
      students.push_back(record);
      }

   cout << endl;

   // Exercise 10.1
   cout << "show students' letter grade, in letter grade order" << endl;
   sort(students.begin(), students.end(), lg_compare);

   // write the names and grades
   for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) 
      {
      cout << students[i].name()
      << string(maxlen + 1 - students[i].name().size(), ' ');
      cout << students[i].letter_grade() << endl; // Exercise 9.5
      }
   return 0;
   }
