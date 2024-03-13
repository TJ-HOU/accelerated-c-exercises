#include "Student_info.h"
#include "math.h"
#include "grade.h"
#include "extract.h"
#include "analysis.h"
#include <vector>
#include <iostream>

using std::cin;
using std::vector;
using std::cout;
using std::endl;

int main()
   {
   vector<Student_info> students;
   Student_info student;

   // read all the records, separating them based on whether all homework was done 
   while (read(cin, student)) 
      {
      students.push_back(student);
      }
   
   /* 
   Exercise 6-6
   Classify students into 2 groups based on if they have done all the homework.
   For each group, compute the median of students' overall grades using 3 different grading schemes.
   The 3 grading schemes are median_grade, optimistic_median, average_grade.
   The 3 grading schemes should be merged into 1 analysis() function. 
   
   Input:
   Moo 100 100 100 100 100 100 100 100
   Moore 75 85 77 59 0 85 75 40    
   Olson 89 86

   Output:
   These students did all homework:
   Moo
   median(did) = 100
   optimistic_median(did) = 100
   average(did) = 100

   These students didn't do all homework:
   Moore
   Olson
   median(didnt) = 64
   optimistic_median(didnt) = 65.6
   average(didnt) = 61.8
   */
   vector<Student_info> didnt = extract(students,didnt_all_hw);
   vector<Student_info> did = extract(students, did_all_hw);
   cout << "These students did all homework:" << endl;
   for (auto i = did.begin(); i != did.end(); ++i)
      {
      cout << (i->name) << endl;
      } 
   cout << "median(did) = " << analysis(did,median_grade) << endl;
   cout << "optimistic_median(did) = " << analysis(did,optimistic_median) << endl;
   cout << "average(did) = " << analysis(did,average_grade) << endl;

   cout << endl;

   cout << "These students didn't do all homework:" << endl;
   for (auto i = didnt.begin(); i != didnt.end(); ++i)
      {
      cout << (i->name) << endl;
      }
   cout << "median(didnt) = " << analysis(didnt,median_grade) << endl;
   cout << "optimistic_median(didnt) = " << analysis(didnt,optimistic_median) << endl;
   cout << "average(didnt) = " << analysis(didnt,average_grade) << endl;

   cout << endl;
   /* 
   Exercise 6-8
   Write a single function that can be used to classify students based on criteria of your choice.
   I used the same extract() function as the one in last Exercise to classify students into fail/pass. 
   
   Input:
   Same as last Exercise

   Output:
   These students have passed:
   Moo (100)
   Moore (75.8)
   These students have failed:
   Olson (52.2)
   */
   vector<Student_info> fail = extract(students, fgrade);
   vector<Student_info> pass = extract(students, pgrade);
   cout << "These students have passed:" << endl;
   for (auto i = pass.begin(); i != pass.end(); ++i)
      {
      cout << (i->name) << " (" << median_grade(*i) << ")" << endl;
      } 
   cout << endl;
   cout << "These students have failed:" << endl;
   for (auto i = fail.begin(); i != fail.end(); ++i)
      {
      cout << (i->name) << " (" << median_grade(*i) << ")" << endl;
      }

   cout << endl;

   
   
   return 0;
   }
