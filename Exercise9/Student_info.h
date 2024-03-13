#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <string>
#include <vector>

class Student_info 
   {
   public:
      Student_info(); // construct an empty Student_info object
      Student_info(std::istream&); // construct one by reading a stream
      std::string name() const 
         {
         return n;
         }
      double final_grade() const
         {
         return f;
         }
      bool valid() const 
         { 
         return !homework.empty(); 
         }
      std::istream& read(std::istream&); 
      std::string letter_grade() const;

   private:
      std::string n; //student name
      double midterm, final, f;
      std::vector<double> homework;  
      std::istream& read_hw(std::istream&, std::vector<double>&); // Exercise 9.7
   };

bool name_compare(const Student_info&, const Student_info&);
bool lg_compare(const Student_info&, const Student_info&);

#endif