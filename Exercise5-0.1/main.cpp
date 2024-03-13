#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include "grade.h"
#include "Student_info.h"
#include "fail.h"

using std::list;
using std::string;
using std::cin;
using std::max;
using std::cout;
using std::endl;

int main()
{
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // read and store all the records, and find the length of the longest name
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    cout << endl;
    
    // alphabetize the records
    students.sort(compare);

    list<Student_info> fails = extract_fails(students);
    list<Student_info>::iterator iter = fails.begin();

    cout << "Fail list: " << endl;
    while (iter != fails.end()) { 
        cout << iter->name << " " << iter->final << endl;
        ++iter;
    }

    cout << endl;

    iter = students.begin();
    cout << "Pass list: " << endl;
    while (iter != students.end()) { 
        cout << iter->name << " " << iter->final << endl;
        ++iter;
    }
  
    return 0;
    
}




