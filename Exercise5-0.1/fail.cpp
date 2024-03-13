#include "Student_info.h"
#include "grade.h"
#include "fail.h"

using std::istream; using std::list;

// predicate to determine whether a student failed 
bool fgrade(const Student_info& s)
{
 return grade(s) < 60;
}

// separate passing and failing student records
list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

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