#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::domain_error;
using std::streamsize;
using std::setprecision;

int main(){

    vector<double> nums;

    cout << "Please enter numbers: " << endl;
     
    double x;
    while (cin >> x)
    nums.push_back(x);

    vector<double>::size_type size = nums.size();

    if (size == 0) 
        throw domain_error("no numbers provided - vector is empty!");

    double sum = 0;
    for (vector<double>::size_type i = 0; i != size; ++i){
        sum=sum+nums[i];
    }

    streamsize prec = cout.precision();
    cout << "The average of the numbers stored in a vector: " << setprecision(5) <<(sum/size) << setprecision(prec) << endl;

    return 0;
}


