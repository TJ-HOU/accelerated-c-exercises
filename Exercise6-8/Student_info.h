#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>
#include <list>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

typedef std::vector<Student_info> students_type;
//typedef std::list<Student_info> students_type;

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
void read_hw(std::istream&, std::vector<double>&);

#endif