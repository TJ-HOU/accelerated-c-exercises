#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::min;

int main() 
{   
    cout << "a square: " << endl;
    int rows = 5;
    int cols = 5;

    for (int r = 0; r != rows; ++r){
        
        int c = 0;
        while(c != cols){
            if(r == rows - 1 || r == 0 || c == 0 || c == cols - 1)
            cout << "*";
            else
            cout << " ";
            ++c;
            }
        cout << endl;
    }

    cout << endl;

    cout << "a rectangle: " << endl;
    rows = 10;
    cols = 5;

    for (int r = 0; r != rows; ++r){
        
        int c = 0;
        while(c != cols){
            if(r == rows - 1 || r == 0 || c == 0 || c == cols - 1)
            cout << "*";
            else
            cout << " ";
            ++c;
            }
        cout << endl;
    }

    cout << endl;
    
    cout << "a triangle: " << endl;
    rows = 5;
    cols = 10;
    for (int r = 0; r != rows; ++r){
        
        int c = 0;
        while(c != min(rows,cols)){
            if(r == rows - 1 || c == 0 || c == r)
            cout << "*";
            else
            cout << " ";
            ++c;
            }
        cout << endl;}

    return 0;
}
