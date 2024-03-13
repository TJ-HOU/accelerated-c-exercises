#ifndef GUARD_extract_h
#define GUARD_extract_h

#include <list>
#include <vector>
#include "Student_info.h"
#include "math.h"
#include "grade.h"

std::vector<Student_info> extract(std::vector<Student_info>, bool criteria(const Student_info&));
bool fgrade(const Student_info&);
bool pgrade(const Student_info&);
bool did_all_hw(const Student_info&);
bool didnt_all_hw(const Student_info&);

#endif