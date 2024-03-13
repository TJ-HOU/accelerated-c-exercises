#include "Pic.h"
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
   {
   vector<Student_info> students;
   Student_info s;
   // read the names and grades 
   while (s.read(cin))
      {
      students.push_back(s);
      }
   // put the students in alphabetical order
   sort(students.begin(), students.end(), Student_info::compare);
   // write the names and histograms
   cout << frame(histogram(students))<< endl;
   return 0;
   }