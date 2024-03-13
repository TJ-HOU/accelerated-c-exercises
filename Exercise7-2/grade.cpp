#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error; 
using std::vector;
using std::string;

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

string letter(double& g)
{
    if (g<0 || g>100)
    throw domain_error("grade is wrong");
    string ret;
    if ( g >= 90 )
        ret = "A";
    else if ( g >= 80 )
        ret = "B";
    else if ( g >= 70 )
        ret = 'C';
    else if ( g >= 60 )
        ret = 'D';
    else if (g < 60 )
        ret = 'F';
        
    return ret;
}
