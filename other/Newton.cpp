#include <iostream>
#include <math.h>
double user_func(double err_threshold){
    double x0=1.0;
    double epsilon=1;
    while (abs(epsilon)>=err_threshold){
        epsilon=(pow(x0,3)-0.99)/(3*pow(x0,2));
        x0=x0-epsilon;
    }
    return x0;
}

int main(){
    std::cout << user_func(1e-6) << std::endl;
    return 0;
}