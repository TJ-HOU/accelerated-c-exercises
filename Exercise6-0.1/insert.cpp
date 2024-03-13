#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::isspace;

int main(){

    // compile using g++ std=c++11 ...
    vector<string> bottom = {"ab","cde","fhg","abcde","ghde"};
    vector<string> ret1 = {"xyz","opq","wsj"};
    vector<string> ret2 = {"xyz","opq","wsj"};
    vector<string> ret3 = {"xyz","opq","wsj"};

    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
        ret1.push_back(*it);

    ret2.insert(ret2.end(), bottom.begin(), bottom.end());

    copy(bottom.begin(), bottom.end(), back_inserter(ret3));

    // doesn't work!! copy(bottom.begin(), bottom.end(), ret.end());

    cout << "Method 1: loop" << endl;
    for (vector<string>::const_iterator it = ret1.begin(); it != ret1.end(); ++it)
        cout << *it << endl;

    
    cout << endl;
    cout << "Method 2: insert" << endl;
    for (vector<string>::const_iterator it = ret2.begin(); it != ret2.end(); ++it)
        cout << *it << endl;

    cout << endl;
    cout << "Method 3: copy" << endl;
    for (vector<string>::const_iterator it = ret3.begin(); it != ret3.end(); ++it)
        cout << *it << endl;

    return 0;
}
