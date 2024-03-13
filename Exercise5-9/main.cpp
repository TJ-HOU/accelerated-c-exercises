#include <iostream>
#include "uppers.h"

using std::string;
using std::list;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

int main(){
    string s;
    list<string> v;
    // read and split each line of input 
    while (cin>>s) 
        v.push_back(s);

    list<string> uppers = extract_uppers(v);
    v.insert(v.end(),uppers.begin(),uppers.end());
    list<string>::iterator iter = v.begin();

    cout << endl;
    cout << "Results: " << endl;
    while (iter != v.end()) { 
        cout << *iter << endl;
        ++iter;
    }

    cout << endl;

    return 0;   
}


