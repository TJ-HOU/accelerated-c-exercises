#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
    
    cout << "Please enter two numbers: ";
    int a,b;
    cin >> a;
    cin >> b;

    if (a>b){
        cout << a << " is larger than "<< b;
    } else
    {
        if (a<b)
            cout<< b << " is larger than "<<a;
        else cout<< a<< " is equal to "<<b;
    }

    cout << endl;
    
    return 0;
}