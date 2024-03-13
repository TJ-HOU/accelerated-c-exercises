#include <iostream>
#include <string>

int main() 
{
    // ask for the person's name
    std::cout << "Please enter your first name: ";
    
    // read the name
    std::string name; //define name
    std::cin >> name; //read into name

    // build the msg
    const std::string greeting = "Hello, " + name + "!";

    // build the 2nd and 4th line
    const std::string spaces (greeting.size(), ' '); // must have space in ' ' 
    const std::string second = "* "+ spaces + " *";

    // build the 1st and 5th line
    const std::string first(second.size(), '*');
    
    // write a greeting
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    return 0; 
    
}