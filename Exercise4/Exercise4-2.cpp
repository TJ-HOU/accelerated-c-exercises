#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::to_string;
using std::max;
using std::cout;
using std::endl;
using std::setw;

int main(){

    vector<int> col1, col2;
    string::size_type maxlen1 = 0;
    string::size_type maxlen2 = 0;

    for (int i = -100; i != 101; ++i){

        col1.push_back(i);
        col2.push_back(i*i);
        maxlen1=max(to_string(i).size(),maxlen1);
        maxlen2=max(to_string(i*i).size(),maxlen2);
   
    }

    cout << maxlen1 << endl;
    cout << maxlen2 << endl;

    for (vector<int>::size_type i=0; i!=col1.size(); ++i){

        cout << setw(maxlen1) << col1[i] << setw(maxlen2+1) << col2[i] << endl;

    }

    return 0;
}

