#ifndef GUARD_scenders_h
#define GUARD_scenders_h

#include <string>
#include <list>

using std::string;
using std::list;

bool ascender(string&);
bool descender(string&);
list<string> extract_scenders(list<string>&);

#endif