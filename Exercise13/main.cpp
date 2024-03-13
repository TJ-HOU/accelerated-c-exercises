#include "Core.h"
#include <iomanip>
#include <stdexcept>
#include <iomanip>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::setprecision;
using std::max;
using std::streamsize;
using std::setw;
using std::right;
using std::left;

int main()
   {
   /* 
   // Exercise 13-1
   Core c1; // Core::Core() 
   Grad g1; // Core::Core() Grad::Grad() 
   Core c2(cin); // Core::Core(istream&)
   Grad g2(cin); // Core::Core() Grad::Grad(istream&)

   // Exercise 13-2
   Core* p1 = new Core; // Core::Core()
   Core* p2 = new Grad; // Core::Core() Grad::Grad()
   Core s1; // Core::Core()
   Grad s2; // Core::Core() Grad::Grad()

   try 
      {
      p1->grade(); // Core::grade()
      }
   catch (domain_error e) 
      { 
      }
   p1->name(); // name()

   try 
      {
      p2->grade(); // Grad::grade() Core::grade()
      }
   catch (domain_error e) 
      {
      }
   p2->name(); // name()

   try 
      {
      s1.grade(); // Core::grade()
      }
   catch (domain_error e) 
      {
      }
   s1.name(); // name()

   try 
      {
      s2.grade(); // Grad::grade() Core::grade()
      }
   catch (domain_error e) 
      {
      }
   s2.name(); // name()
   
   // ~Core()
   // ~Core()
   // ~Core()
   // ~Core()
   // ~Core()
   // ~Core()
   delete p1; // ~Core()
   delete p2; // ~Core()  
   */
   
   // Exercise 13-8
   vector<Student_info> students; // read and process Core records
   Student_info record;
   string::size_type maxlen = 0;

   // read and store the data
   while (record.read(cin)) 
      {
      //maxlen = max(maxlen, record.name().size());
      students.push_back(record);
      }

   // alphabetize the student records
   sort(students.begin(), students.end(), Student_info::compare);

   // write the names and grades
   for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) 
   // students[i] is a pointer that we dereference to call the functions
      {
      cout << students[i].name() << endl;
      //<< string(maxlen + 1 - students[i].name().size(), ' ');  
      try 
         {
         double final_grade = students[i].grade(); // Core::grade
         string letter = students[i].letter_grade();
         streamsize prec = cout.precision();
         cout << "numeric grade: " << setprecision(3) << final_grade
         << setprecision(prec) << endl;
         cout << "letter grade: " << letter << endl;
         } 
      catch (domain_error e) 
         {
         cout << e.what() << endl;
         }
      }

   return 0;
   }
 