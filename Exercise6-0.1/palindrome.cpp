#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::isspace;

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

int main(){

    vector<string> test = {"bob","abc","RotAtOr","CiviC","anNA"};
    for (vector<string>::const_iterator it = test.begin(); it != test.end(); ++it)
        if (is_palindrome(*it))
            cout << *it << endl;

    return 0;
}
