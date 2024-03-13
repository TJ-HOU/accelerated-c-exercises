#include "Student_info.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::max;

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

   // alphabetize the student records
   sort(students.begin(), students.end(), compare);

   // write the names and grades
   for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) 
      {
      cout << students[i].name()
      << string(maxlen + 1 - students[i].name().size(), ' ');
      try 
         {
         double final_grade = students[i].grade(); 
         std::streamsize prec = cout.precision();
         cout << std::setprecision(3) << final_grade
         << std::setprecision(prec) << endl;
         } 
      catch (std::domain_error e) 
         {
         cout << e.what() << endl;
         }
      }
   
   return 0;
   }