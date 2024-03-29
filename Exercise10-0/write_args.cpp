// compile: g++ write_args.cpp -o main
// ./main say Hello, world
// output: say Hello, world
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
    // if there are arguments, write them
    if (argc > 1) {
    int i; // declare i outside the for because we need it after the loop finishes
    for (i = 1; i < argc-1; ++i) // write all but the last entry and a space
    cout << argv[i] << " "; // argv[i] is a char*

    cout << argv[i] << endl; // write the last entry but not a space
    }
    return 0;
}

