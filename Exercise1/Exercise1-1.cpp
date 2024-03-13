#include <iostream>
#include <string>

int main() 
{   
    const std::string hello = "Hello";
    const std::string msg = hello + ", world" + "!";
    std::cout << msg << std::endl;

    return 0; 


}