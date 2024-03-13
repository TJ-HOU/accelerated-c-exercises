#include <algorithm>
#include <stdexcept>
#include <vector>
#include <string>
#include <list>
#include <iostream>
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

    students_type originals,students1,students2;
    Student_info record;
    string::size_type maxlen = 0;

    // read in students' records
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        originals.push_back(record);
    }

    cout << endl;

    //method 1: resizing
    start=clock();

    students1 = originals;
    students_type fails = extract_fails_v1(students1);
    
    students_type::iterator iter = fails.begin();
    cout << "Fail list: " << endl;
    while (iter != fails.end()) { 
        cout << iter->name << " " << grade(*iter) << endl;
        ++iter;
    }

    cout << endl;

    iter = students1.begin();
    cout << "Pass list: " << endl;
    while (iter != students1.end()) { 
        cout << iter->name << " " << grade(*iter) << endl;
        ++iter;
    }

    end=clock(); 

    cout << endl;

    time_taken = double(end - start)/ double(CLOCKS_PER_SEC); 
    cout << "Time taken of resizing method is : " << time_taken; 
    cout << " sec " << endl; 


    fails.clear();
    //method 2: erasing
    start=clock();

    students2 = originals;
    fails = extract_fails_v2(students2);
    
    iter = fails.begin();
    cout << "Fail list: " << endl;
    while (iter != fails.end()) { 
        cout << iter->name << " " << grade(*iter) << endl;
        ++iter;
    }

    cout << endl;

    iter = students2.begin();
    cout << "Pass list: " << endl;
    while (iter != students2.end()) { 
        cout << iter->name << " " << grade(*iter) << endl;
        ++iter;
    }

    end=clock(); 

    time_taken = double(end - start)/ double(CLOCKS_PER_SEC); 
    cout << "Time taken of erasing method is : " << time_taken; 
    cout << " sec " << endl; 
    
    return 0;
    
}