#include "grade.h"
#include "median.h"

double grade(double midterm, double final, double homework)
   {
   return 0.2 * midterm + 0.4 * final + 0.4 * homework;
   }

double grade(double midterm, double final, const Vec<double>& hw)
   {
   if (hw.size() == 0)
      {
      throw std::domain_error("student has done no homework");
      }
   return grade(midterm, final, median(hw));
   }

// 13-4 Add a letter grade function
Str letter_grade(double g)
   {
   static const double numbers[] = 
   {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
   static const char* const letters[] = 
   {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
   static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
   for (size_t i = 0; i < ngrades; ++i) 
      {
      if (g >= numbers[i])
         {
         return letters[i];
         }   
      }
   return "?\?\?";
   }
