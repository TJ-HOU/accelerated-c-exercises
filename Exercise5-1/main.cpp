#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <cmath>
#include "split.h"
#include "cat.h"
#include "permute.h"
#include "read.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;

int main(){
    
    // read and rotate each line of input 

    string line;
    vector<string> lines;
    
    lines=read(cin);

    for (vector<string>::size_type i = 0; i != lines.size(); ++i){

        vector<string> words = split(lines[i]);

        vector<string> r = rotate(words);
    
        sort(r.begin(),r.end());

        vector<string> ur = unrotate(r,words[0],words.back());

        for (vector<string>::size_type i = 0; i != ur.size(); ++i)
            cout << ur[i] << endl;

        cout << endl;

    }

    return 0;   
}