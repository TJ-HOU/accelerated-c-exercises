#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Vec.h"
#include "Str.h"

double grade(double, double, double);
double grade(double, double, const Vec<double>&);
// 13-4 Add a letter grade function
Str letter_grade(double);

#endif