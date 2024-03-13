#include <string>
#include <vector>
#include <iostream>
#include "frame.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main(){

    string s;
    vector<string> v;
     
    while (getline(cin, s)) 
        v.push_back(s);

    vector<string> result;
    result = frame(v);
    cout << "frame: " << endl << endl;
    for (vector<string>::size_type i = 0; i != result.size(); ++i)
        cout << result[i] << endl;

    return 0;   
}