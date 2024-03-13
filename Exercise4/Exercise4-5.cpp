#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::string;
using std::istream;
using std::cin;
using std::endl;
using std::cout;
using std::domain_error;

vector<string> words_vec (istream& in){

    vector<string> words;

    // read words 
    string x;
    while (in >> x)
    words.push_back(x);

    return words;
        
}

int main(){

    cout << "Please enter words: " << endl;
    vector<string> words = words_vec(cin);

    typedef vector<string>::size_type vec_sz;
    vec_sz size = words.size();
    cout << "The number of words: " << size << endl;

    if (size == 0) 
        throw domain_error("no numbers provided - vector is empty!");

    vector<string> distincts;
    vector<vec_sz> counts;
    sort(words.begin(), words.end());

    distincts.push_back(words[0]);
    counts.push_back(1);
      
    for (vec_sz i = 1; i != words.size(); ++i){
        if (words[i-1]!=words[i]){
            distincts.push_back(words[i]);
            counts.push_back(1);
        } 
        else {++counts.back();}             
    }
    
    for (vec_sz i = 0; i != distincts.size(); ++i){
        cout << distincts[i] << ' ' << counts[i] << endl;
    }    

    return 0;
}

