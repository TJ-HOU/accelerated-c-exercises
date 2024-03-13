/*
Exercise 5-6
Compare the performance of 2 versions of the extract_fails function
Version 1: Copy the records for the passing students to the beginning
of the input vector v, and then uses the resize function to remove the extra elements from the end of v
Version 2: Erase each failing student from v

Example:
- Input:
Johnny 50 60 70 80 90 100 Jared 60 70 90 100 50 40 Joe 66 55 77 90 10 45
^D
- Output:
Fail list: 
Joe 59.6
Pass list: 
Johnny 68
Jared 68
Time taken of resizing method is : 5.5e-05 sec
Time taken of erasing method is : 2.8e-05 sec
*/

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <string>
#include <list>
#include <iostream>
#include "median.h"
#include "Student_info.h"
#include "grade.h"
#include "fail.h"

using std::domain_error; 
using std::sort; 
using std::vector;
using std::list;
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::max;
using std::istream;

int main()
   {
   clock_t start, end;
   double time_taken = 0;

   students_type originals,students1,students2;
   Student_info record;
   string::size_type maxlen = 0;

   // read in students' records
   while (read(cin, record)) 
      {
      maxlen = max(maxlen, record.name.size());
      originals.push_back(record);
      }

   cout << endl;

   // Version 1: resizing
   start=clock();

   students1 = originals;
   students_type fails = extract_fails_v1(students1);

   // write the list of failing students
   students_type::iterator iter = fails.begin();
   cout << "Fail list: " << endl;
   while (iter != fails.end()) 
      { 
      cout << iter->name << " " << grade(*iter) << endl;
      ++iter;
      }

   cout << endl;

   // write the list of passing students
   iter = students1.begin();
   cout << "Pass list: " << endl;
   while (iter != students1.end()) 
      { 
      cout << iter->name << " " << grade(*iter) << endl;
      ++iter;
      }

   end=clock(); 

   cout << endl;

   // write the time taken for version 1
   time_taken = double(end - start)/ double(CLOCKS_PER_SEC); 
   cout << "Time taken of resizing method is : " << time_taken; 
   cout << " sec " << endl; 


   fails.clear();
   //Version 2: erasing
   start=clock();

   students2 = originals;
   fails = extract_fails_v2(students2);

   // write the list of failing students
   iter = fails.begin();
   cout << "Fail list: " << endl;
   while (iter != fails.end()) 
      { 
      cout << iter->name << " " << grade(*iter) << endl;
      ++iter;
      }

   cout << endl;

   // write the list of passing students
   iter = students2.begin();
   cout << "Pass list: " << endl;
   while (iter != students2.end()) 
      { 
      cout << iter->name << " " << grade(*iter) << endl;
      ++iter;
      }

   end=clock(); 

   // write the time taken for version 1
   time_taken = double(end - start)/ double(CLOCKS_PER_SEC); 
   cout << "Time taken of erasing method is : " << time_taken; 
   cout << " sec " << endl; 

   return 0;
   }