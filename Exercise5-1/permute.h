#ifndef GUARD_permute_h
#define GUARD_permute_h

#include <vector>
#include <string>

using std::string;
using std::vector;

vector<string> rotate(const vector<string>&);
vector<string> unrotate(vector<string>&, const string&, const string&);

#endif