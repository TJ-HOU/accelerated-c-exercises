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
         streamsize prec = cout.precision();
         cout << setprecision(3) << final_grade
         << setprecision(prec) << endl;
         } 
      catch (domain_error e) 
         {
         cout << e.what() << endl;
         }
      }
   return 0;
   }
