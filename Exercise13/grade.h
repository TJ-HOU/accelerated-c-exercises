#ifndef GUARD_grade
#define GUARD_grade

// grade.h
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
std::string letter_grade(double);

#endif