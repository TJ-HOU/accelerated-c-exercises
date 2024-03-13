#include "Student_info.h"
#include "grade.h"
#include "fail.h"

using std::istream; using std::list;

// predicate to determine whether a student failed 
bool fgrade(const Student_info& s)
{
 return grade(s) < 60;
}

// this version gives up sort function.
students_type extract_fails(students_type& students)
{
    students_type fail;
    students_type::iterator iter = students.begin();

    // invariant:elements [0, i) of students represent passing grades 
    while (iter != students.end()) { 
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}