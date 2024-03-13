#include<string>
#include<cctype>
#include<list>
#include<iostream>
#include "scenders.h"

using std::string;
using std::vector;
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

    list<string> result = extract_scenders(v);

    if (result.size()==0){
        cout << "None of the words in the dictionary has ascenders or descenders." << endl;
    }
    else{
        list<string>::iterator iter = v.begin();
        string longest;
        string::size_type maxlen = 0;
        cout << endl;
        cout << "Results: " << endl;
        while (iter != v.end()) { 
            cout << *iter << endl;
            if ((*iter).size()>maxlen){
                maxlen = (*iter).size();
                longest = *iter;
            }                      
            ++iter;
        }
        cout << endl;
        cout << "the longest word in the dictionary that has neither ascenders nor descenders: " << longest << endl;

    }
    
    return 0;   
}


