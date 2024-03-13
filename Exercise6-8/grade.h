#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>
#include "Student_info.h"
#include "math.h"

double grade(double, double, double);
double median_grade(const Student_info&);
double optimistic_median(const Student_info&);
double average_grade(const Student_info&);

#endif