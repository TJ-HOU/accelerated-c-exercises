#include "Student_info.h"
#include <vector>
#include <iostream>

using std::cin;
using std::vector;
using std::cout;
using std::endl;

bool did_all_hw(const Student_info& s)
{
return ((find(s.homework.begin(), s.homework.end(), 0))
 == s.homework.end());
}

int main(){

    vector<Student_info> did, didnt;
    Student_info student;

    // read all the records, separating them based on whether all homework was done 
    while (read(cin, student)) {
    if (did_all_hw(student))
    did.push_back(student);
    else
    didnt.push_back(student);
    }

    // check that both groups contain data 
    if (did.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
    }
    if (didnt.empty()) {
    cout << "Every student did all the homework!" << endl;
    return 1;
    }
    
}
