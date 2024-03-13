#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
double optimistic_median(const Student_info&);
double grade_aux(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double opt_median_analysis(const std::vector<Student_info>&);
double average(const std::vector<double>&);
double average_grade(const Student_info&);
double average_analysis(const std::vector<Student_info>&);
void write_analysis(const std::vector<Student_info>&,const std::vector<Student_info>&);

#endif