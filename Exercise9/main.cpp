/*
9.1 Reimplement the Student_info class so that it calculates the final grade when reading 
the student's record, and stores that grade in the object. Reimplement the grade function to 
use this precomputed value.
9.4 Rewrite your program from the previous exercise to use the valid function, thereby 
avoiding the exception altogether.
9.5 Write a class and associated functions to generate grades for students who take the 
course for pass/fail credit. Assume that only the midterm and final grades matter, and that a
student passes with an average exam score greater than 60. The report should list the
students in alphabetical order, and indicate P or F as the grade.  
9.6 Rewrite the grading program for the pass/fail students so that the report shows all the 
students who passed, followed by all the students who failed.
9.7 Integrate read_hw with the rest of the Student_info code, in order to clarify that it was not intended
for public access despite its apparent generality
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

   cout << "list the students in alphabetical order, and indicate the numerical grade" << endl;
   // alphabetize the student records
   sort(students.begin(), students.end(), name_compare);

   // write the names and grades
   for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) 
      {
      cout << students[i].name()
      << string(maxlen + 1 - students[i].name().size(), ' ');
      streamsize prec = cout.precision();
      cout << setprecision(3) << students[i].final_grade() // Exercise 9.1
      << setprecision(prec) << endl;
      }

   cout << endl;

   cout << "show all the students who passed, followed by all the students who failed" << endl;
   // Exercise 9.6
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
