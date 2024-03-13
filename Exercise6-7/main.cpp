#include "Student_info.h"
#include "hw.h"
#include "grade.h"
#include <vector>
#include <iostream>

using std::cin;
using std::vector;
using std::cout;
using std::endl;


int main(){

    vector<Student_info> did;
    Student_info student;

    // read all the records, separating them based on whether all homework was done 
    while (read(cin, student)) 
        did.push_back(student);

    // vector<Student_info> didnt = extract_didnt_v1(did);
    vector<Student_info> didnt = extract_didnt_v1(did);
    
    // write_analysis(didnt,did);

    for (vector<Student_info>::const_iterator it = didnt.begin(); it != didnt.end(); ++it)
    {
        cout << it->name << endl;
    }

    return 0;
    
}
