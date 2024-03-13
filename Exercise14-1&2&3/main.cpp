// Exercise 14-2
#include "Student_info.h"
#include <iomanip>
#include <stdexcept>
using std::vector;
using std::string;
using std::cin;
using std::max;
using std::cout;
using std::streamsize;
using std::setprecision;
using std::domain_error;
using std::endl;

int main()
   {
   vector<Student_info> students; // changed type
   Student_info record; // changed type
   string::size_type maxlen = 0;

   // read and store the data
   while (record.read(cin)) 
      {
      maxlen = max(maxlen, record.name().size()); 
      students.push_back(record);
      }

   // compare must be rewritten to work on const Handle<Core>&
   sort(students.begin(), students.end(), Student_info::compare);

   // write the names and grades
   for (auto i = 0; i != students.size(); ++i) 
      {
      // students[i] is a Handle, which we dereference to call the functions 
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
      // no delete statement
      }

   return 0;
   }
