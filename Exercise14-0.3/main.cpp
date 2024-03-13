// Exercise 14-2
#include "Ptr.h"
#include "Core.h"
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
   vector< Ptr<Core> > students; // changed type
   Ptr<Core> record; // changed type
   string::size_type maxlen = 0;
   char ch;

   // read and store the data
   while (cin >> ch) 
      {
      if (ch == 'U')
         {
         record = new Core; // allocate a Core object
         }
      else
         {
         record = new Grad; // allocate a Grad object
         }
      record->read(cin);
      maxlen = max(maxlen, record->name().size()); 
      students.push_back(record);
      }

   // compare must be rewritten to work on const Handle<Core>&
   sort(students.begin(), students.end(), compare_Core_handles);

   // write the names and grades
   for (auto i = 0; i != students.size(); ++i) 
      {
      // students[i] is a Handle, which we dereference to call the functions 
      cout << students[i]->name()
      << string(maxlen + 1 - students[i]->name().size(), ' ');
      try 
         {
         double final_grade = students[i]->grade();
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
