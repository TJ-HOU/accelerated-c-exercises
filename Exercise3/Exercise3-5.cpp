#include <algorithm>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>

using std::cin; using std::sort;
using std::cout; using std::endl; 
using std::string; using std::vector;
using std::streamsize; using std::setprecision; 

int main()
{
    cout << " Enter a student's name: ";
    string name;
    vector<string> names;
    const vector<double>::size_type size= 5; //assume a fixed number of homework grades.
    vector<double> grades;

    while (cin >> name){
        names.push_back(name);

        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;

        cout << "Please enter " << size << " homework grades below: " << endl;
        
        double sum = 0;
        double x;
        for (vector<double>::size_type i = 0; i != size; ++i){
            cin >> x;
            sum += x;
        }
        
        grades.push_back(0.2 * midterm + 0.4 * final + 0.4 * sum / size);

        cout << "Enter another student's name" << endl;

    }

    cout << "Summary: " << endl;
    for (vector<string>::size_type i=0; i!=names.size(); ++i){
        cout << names[i] << " " << grades[i] << endl;
    }

    return 0;
 
}