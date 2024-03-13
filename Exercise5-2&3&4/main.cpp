#include <algorithm>
#include <stdexcept>
#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <iomanip>
#include "median.h"
#include "Student_info.h"
#include "grade.h"
#include "fail.h"

using std::domain_error; 
using std::sort; 
using std::vector;
using std::list;
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::max;
using std::istream;

int main()
{

    clock_t start, end;
    double time_taken = 0;

    start=clock();

    students_type students;
    Student_info record;
    string::size_type maxlen = 0;


    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    cout << endl;

    students_type fails = extract_fails(students);
    students_type::iterator iter = fails.begin();

    cout << "Fail list: " << endl;
    while (iter != fails.end()) { 
        cout << iter->name << " " << grade(*iter) << endl;
        ++iter;
    }

    cout << endl;

    iter = students.begin();
    cout << "Pass list: " << endl;
    while (iter != students.end()) { 
        cout << iter->name << " " << iter->final << endl;
        ++iter;
    }

    end=clock(); 

    time_taken = double(end - start)/ double(CLOCKS_PER_SEC); 
    cout << "Time taken is : " << std::fixed 
        << time_taken << std::setprecision(5); 
    cout << " sec " << endl; 
    
    return 0;
    
}