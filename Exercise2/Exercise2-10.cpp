#include<iostream>

int main(){
    
    int k=0;
    while (k!=10){
        using std::cout; // we intend to use cout to mean std::cout exclusively
        cout<<"*";
        ++k;
    }
    std::cout<<std::endl; // explicitly say that the cout and endl comes from the standard library
    
    return 0;
}