#include<iostream>

using std::cout;
using std::endl;

int main(){
    int j;
    for (int i=1; i!=10; i++){
        j=i;
        while (j<10){
            cout << i*j << " ";
            ++j;
        }
        cout << endl;
    }
}
