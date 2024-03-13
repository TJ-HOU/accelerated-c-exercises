#ifndef GUARD_hw_h
#define GUARD_hw_h

// fail.h
#include <list>
#include <vector>
#include "Student_info.h"
#include "grade.h"

bool did_all_hw(const Student_info&);
bool didnt_all_hw(const Student_info&);
students_type extract_didnt_v1(students_type&);
students_type extract_didnt_v2(students_type&);

#endif