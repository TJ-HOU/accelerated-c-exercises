#ifndef GUARD_frame_h
#define GUARD_frame_h

#include <vector>
#include <string>

using std::string;
using std::vector;

string::size_type width(const vector<string>&);
vector<string> frame(const vector<string>&);

#endif