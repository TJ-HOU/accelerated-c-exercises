#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{   
    const char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0' };   
    string s(hello, hello + strlen(hello));
    cout << s << endl;
    return 0;
}
