#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::sort;
using std::cout; using std::endl; 
using std::string; using std::vector;

int main (){

    cout << "Enter a set of words, "
        "followed by end-of-file: ";

    string x;
    vector<string> words;

    while (cin >> x)
        words.push_back(x);

    typedef vector<string>::size_type vec_sz;
    vec_sz size=words.size();

    if (size == 0){
        cout << endl << "You must enter at least 1 word. "
                        "Please try again." << endl;
        return 1;
    }

    string::size_type size1 = words[0].size();
    string::size_type size2 = words[0].size();
    string longest, shortest;

    for (vec_sz i = 1; i != size; ++i){

        string::size_type size_i = words[i].size();

        if (size_i > size1){
            size1 = size_i;
            longest = words[i];
        }
        else{
            if (size_i < size2){
            size2 = size_i;
            shortest = words[i];}
        }            
    }  

    cout << "the longest string and size: " << longest << " " << size1 << endl;
    cout << "the shortest string and size: " << shortest << " " << size2 << endl;

    return 0;
}