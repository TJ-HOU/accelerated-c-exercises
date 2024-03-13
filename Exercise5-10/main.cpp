#include<string>
#include<cctype>
#include<list>
#include<iostream>
#include "palindromes.h"

using std::getline;
using std::cin;
using std::cout;
using std::endl;

int main(){

    string s;
    list<string> v;
 
    while (cin>>s) 
        v.push_back(s);

    list<string> result = extract_palindromes(v);
    list<string>::iterator iter = result.begin();
    string longest;
    string::size_type maxlen = 0;

    cout << endl;
    cout << "Results: " << endl;
    while (iter != result.end()) { 
        cout << *iter << endl;
        if ((*iter).size()>maxlen){
            maxlen = (*iter).size();
            longest = *iter;
        }                      
        ++iter;
    }

    cout << endl;
    cout << "the longest palindrome is " << longest << endl;

    return 0;   
}


