#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::sort;
using std::cout; using std::endl; 
using std::string; using std::vector;
using std::max;

int main(){

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

    vector<string> distincts;
    vector<int> counts;
    string::size_type maxlen;

    sort(words.begin(), words.end());
    distincts.push_back(words[0]);
    counts.push_back(1);
    for (int i = 1; i != size; ++i){
        if (words[i-1]!=words[i]){
            distincts.push_back(words[i]);
            counts.push_back(1);
            maxlen = max(maxlen,words[i].size());
        } 
        else {++counts.back();}             
    }

    for (int j = 0; j != distincts.size(); ++j){
        cout << distincts[j] << string(maxlen + 1 - distincts[j].size(), ' ')  << counts[j] << endl;
    }

    return 0;
}