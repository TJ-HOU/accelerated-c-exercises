#include <numeric>
#include <string>
#include <vector>
#include <iostream>
    
int main () {
    std::string str = "Hello World!";
    std::vector<std::string> vec(10,str);
    std::string a = std::accumulate(vec.begin(), vec.end(), std::string(""));
    std::cout << a << std::endl;
}