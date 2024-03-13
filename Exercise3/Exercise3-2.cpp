#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;

int main()
{
    cout << "Enter a set of integers, "
        "followed by end-of-file: ";

    double x;
    vector<double> nums;

    while (cin >> x)
        nums.push_back(x);

    typedef vector<double>::size_type vec_sz;
    vec_sz size=nums.size();

    if (size == 0){
        cout << endl << "You must enter at least 1 integer. "
                        "Please try again." << endl;
        return 1;
    }

    sort(nums.begin(), nums.end());

    vec_sz mid = size*0.5;
    vec_sz q1 = size*0.25;
    vec_sz q3 = size*0.75;
    double qtr1 = 0;
    double median = 0;
    double qtr3 = 0;
    qtr1 = size % 4 == 0 ? nums[q1-1] : nums[q1];
    median = size % 2 == 0 ? (nums[mid]+nums[mid-1])/2 : nums[mid];
    qtr3 = size % 4 == 0 ? nums[q3-1] : nums[q3];

    streamsize prec=cout.precision();
    cout << q1 << " " << mid << " " << q3 << endl;
    cout << "Q1: " << setprecision(3) << qtr1 << endl;
    cout << "Q2: " << median << endl;
    cout << "Q3: " << qtr3 << setprecision(prec) << endl;

    return 0;

}