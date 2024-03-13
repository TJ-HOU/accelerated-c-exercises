#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::endl;
using std::string;
using std::cout;

int main(){

    // create a vector contains 10 values and each value is 100.
    vector<int>u(10, 100);
    
    vector<int>v;

    // the following code won't work
    // copy(u.begin(), u.end(), v.begin());

    // Method 1 Copy from u to v
    // copy(u.begin(),u.end(),back_inserter(v));

    // Method 2 Copy from u to v
    v.insert(v.end(),u.begin(),u.end());

    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;
    
    


    return 0;

}




