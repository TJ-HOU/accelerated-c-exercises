#include <string>
#include <vector>
#include <iostream>
#include "frame.h"

using std::string;
using std::vector;
using std::max;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

int main(){
    string s;
    vector<string> v;
     
    while (getline(cin, s)) 
        v.push_back(s);

    vector<string> result;
    result = center(v);
    cout << "centered picture: " << endl << endl;
    for (vector<string>::size_type i = 0; i != result.size(); ++i)
        cout << result[i] << endl;

    cout << endl;

    return 0;   
}

