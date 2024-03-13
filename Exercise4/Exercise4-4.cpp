#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::streamsize;
using std::fixed;
using std::setprecision;
using std::endl;
using std::setw;

int main(){

    vector<double> col1, col2;

    double begin = 0;
    double end = 0;
    cout << "To generate double values in [a,b], please enter a and b: " << endl;
    cin >> begin >> end;

    while (begin < end){

        col1.push_back(begin);
        col2.push_back(begin*begin);
        begin = begin + 0.05;

    }

    streamsize prec = cout.precision();
    for (vector<double>::size_type i=0; i!=col1.size(); ++i){

        if (col1[i] < 0) { 
            cout << fixed << setprecision(3) << col1[i] << " " << col2[i]  << endl;
        } else
        {
            cout << fixed << setprecision(3) << col1[i] << "  " << col2[i]  << endl;
        }
        
    }

    cout << setprecision(prec) << endl;

    return 0;
}

/*
*****************
Exercise 4-4 (didn't use manipulator)
*****************

int main(){

    vector<double> col1, col2;
    string::size_type maxlen1 = 0;
    string::size_type maxlen2 = 0;
    double begin = 0;
    double end = 0;
    int i = 1;
    cout << "Please enter begin number: " << endl;
    cin >> begin >> end;

    while (begin < end){

        col1.push_back(begin);
        col2.push_back(begin*begin);
        maxlen1=max(to_string(begin).size(),maxlen1);
        maxlen2=max(to_string(begin*begin).size(),maxlen2);
        begin = begin + 0.05;
        ++i;

    }

    for (vector<double>::size_type i=0; i!=col1.size(); ++i){

        cout << fixed << setw(maxlen1) << col1[i] << setw(maxlen2+1) << col2[i] << endl;

    }

    return 0;
}
*/

