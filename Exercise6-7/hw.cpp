#include "Student_info.h"
#include "grade.h"
#include "hw.h"
#include <algorithm>

using std::istream; 
using std::list;
using std::vector;

bool did_all_hw(const Student_info& s)
{
return ((find(s.homework.begin(), s.homework.end(), 0))
 == s.homework.end());
}

bool didnt_all_hw(const Student_info& s)
{
return ((find(s.homework.begin(), s.homework.end(), 0))
 != s.homework.end());
}

// 2-pass solution
vector<Student_info> 
extract_didnt_v1(vector<Student_info>& students) 
{
    vector<Student_info> didnt;
    remove_copy_if(students.begin(), students.end(),back_inserter(didnt), did_all_hw);
    // erase function cannot use !did_all_hw as the bool argument.
    students.erase(remove_if(students.begin(), students.end(),
    didnt_all_hw), students.end());
    return didnt;
}


// single-pass solution
vector<Student_info>
extract_didnt_v2(vector<Student_info>& students)
{
    vector<Student_info>::iterator iter =
    stable_partition(students.begin(), students.end(), did_all_hw);
    vector<Student_info> didnt(iter, students.end());
    students.erase(iter, students.end());
 
 return didnt;
}
