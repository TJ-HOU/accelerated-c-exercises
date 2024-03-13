#include <stdexcept>
#include <vector>
#include <iostream>
#include <numeric>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error; using std::vector;
using std::ostream;
using std::string;
using std::endl;

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
    throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

// median of the nonzero elements of s.homework, or 0 if no such elements exist 
double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
    back_inserter(nonzero), 0);

    if (nonzero.empty())
    return grade(s.midterm, s.final, 0);
    else
    return grade(s.midterm, s.final, median(nonzero));
}
