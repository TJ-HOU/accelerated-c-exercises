#include <string>
#include <list>
#include <cctype>
#include "scenders.h"
 
using std::string;
using std::list;

bool ascender(string& s)
{
    
    for (string::size_type i = 0;i != s.size();++i){
        if (s[i] == 'b'|| s[i] == 'd'|| s[i] == 'f'||s[i] == 'h'||s[i] == 'k'||s[i] == 'l')
            return true;
    }
    
    return false;

}

bool descender(string& s)
{
    
    for (string::size_type i = 0;i != s.size();++i){
        if (s[i] == 'g'|| s[i] == 'j'|| s[i] == 'p'||s[i] == 'q'||s[i] == 'y')
            return true;
    }
    
    return false;

}

list<string> extract_scenders(list<string>& words)
{
    list<string> ret;
    list<string>::iterator iter = words.begin();
 
    while (iter != words.end()) { 
        if (ascender(*iter)||descender(*iter)) {
            ret.push_back(*iter);
            iter = words.erase(iter);
        } else
            ++iter;
    }
    return ret;
}