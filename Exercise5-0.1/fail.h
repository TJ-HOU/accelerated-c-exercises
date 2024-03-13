#ifndef GUARD_fail_h
#define GUARD_fail_h

// fail.h
#include <list>
#include "Student_info.h"
#include "grade.h"

bool fgrade(const Student_info&);
std::list<Student_info> extract_fails(std::list<Student_info>&);

#endif