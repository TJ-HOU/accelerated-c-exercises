/*
13-8 Write a program to generate a grade report that can handle all 4 kinds of students.
14-3 Test the Student_info class using Ptr<Core> objects
14-5 Test the reimplemented Str class using Ptr< Vec<char> > objects
15-1 Test the Pic class
15-4 Test the reframe operations
15-5 Test the reimplemented HCat_Pic class
16-0 Convert each student's final grade into a string of = symbols 
     whose length is proportional to the grade
*/
#include "Core.h"
#include "Student_info.h"
#include "Pic.h"
#include <iomanip>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::setprecision;
using std::streamsize;

Picture histogram(const Vec<Student_info>& students) 
{
Picture names;
Picture grades;
for (auto it = students.begin(); it != students.end(); ++it) 
   {
   // create vertically concatenated pictures of the names and grades 
   names = vcat(names, Vec<Str>(1, it->name()));
   grades = vcat(grades, Vec<Str>(1, " " + Str(it->grade() / 5, '=')));
   }
// horizontally concatenate the name and grade pictures to combine them 
return hcat(names, grades);
}

int main()
   {
   // 13-8 Write a program to generate a grade report that can handle all 4 kinds of students.
   // Test the Student_info class using Ptr<Core> objects
   Vec<Student_info> students; 
   Student_info record;

   while (record.read(cin)) 
      {
      students.push_back(record);
      }

   // alphabetize the student records
   std::sort(students.begin(), students.end(), Student_info::compare);

   cout << "Test the Student_info class for Undergrad, Grad, P/F, Audit students" << endl;
   // write the names and grades
   for (auto i = 0; i != students.size(); ++i) 
   // students[i] is a pointer that we dereference to call the functions
      {
      cout << students[i].name() << endl; 
      try 
         {
         double final_grade = students[i].grade(); // Core::grade
         Str letter = students[i].letter_grade();
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
   cout << endl;

   // 15-1 Test the Pic class
   Vec<Str> vs;
   vs.push_back("hello");
   vs.push_back("world"); 
   cout << "Picture: " << endl;  
   Picture p(vs);
   cout << p << endl;
   cout << "Framed picture: " << endl;
   Picture q = frame(p);
   cout << q << endl;
   // 15-5 Test the reimplemented HCat_Pic
   cout << "Concatenate pictures horizontally: " << endl;
   Picture r = hcat(p, q);
   cout << r << endl;
   cout << "Concatenate pictures vertically: " << endl;
   Picture s = vcat(q, r);
   cout << s << endl;
   cout << "Frame previous pictures: " << endl;
   Picture t = frame(hcat(s, vcat(r, q)));
   cout << t << endl;
   // 15-4 Test the reframe operations
   cout << "Reframe the picture: " << endl;
   t.reframe('~', '~', '~');
   cout << t << endl;

   // 16-0 Convert each student's final grade into a string of = symbols 
   //      whose length is proportional to the grade
   cout << "Histogram of students' final grades"<< endl;
   cout << frame(histogram(students))<< endl;

   return 0;
   }
 