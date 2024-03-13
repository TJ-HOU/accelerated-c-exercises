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

double grade_aux(const Student_info& s)
{
    try {
    return grade(s);
    } catch (domain_error) {
    return grade(s.midterm, s.final, 0) ;
    }
}

// this version works fine
double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(),
    back_inserter(grades), grade_aux);
    return median(grades);
}

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(),
    back_inserter(grades), average_grade);
    return median(grades);
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

void write_analysis(ostream& out, const string& name, 
    double median_analysis(const vector<Student_info>&),
    const vector<Student_info>& did,
    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << median_analysis(did) <<
    ", median(didnt) = " << median_analysis(didnt) << endl;
}
