#include "Student_info.h"
#include "grade.h"
#include "fail.h"

using std::istream; using std::list;

// predicate to determine whether a student failed 
bool fgrade(const Student_info& s)
   {
   return grade(s) < 60;
   }

//copy passing students to the beginning and resize to remove extra from the end of the input
students_type extract_fails_v1(students_type& students)
   {
   students_type fail;
   students_type::size_type len = students.size();
   students_type::size_type len2 = len;

   for (students_type::size_type i = 0;i!=len2;++i)
      {
      if (fgrade(students[len-i-1])) 
         {
         fail.push_back(students[len-i-1]);
         }
      else
         {
         students.insert(students.begin(),students[len-i-1]);
         len = len + 1;
         }
      }

   students.resize(students.size()-len2);

   return fail;
   }

//erase failing records from the input
students_type extract_fails_v2(students_type& students)
   {
   students_type fail;
   students_type::iterator iter = students.begin();

   while (iter != students.end()) 
      { 
      if (fgrade(*iter)) 
         {
         fail.push_back(*iter);
         iter = students.erase(iter);
         } 
      else
         {
         ++iter;
         }   
      }

   return fail;
   }