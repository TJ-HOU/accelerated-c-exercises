#include <iostream>

class Base {
    public:
    Base() { std::cout << "base constructor is called\n"; }
    virtual ~Base() { std::cout << "base destructor is called\n"; }
};

class Inherit : public Base {
    public:
    Inherit() { std::cout<< "inherit constructor is called\n"; }
    ~Inherit() { std::cout<< "inherit destructor is called\n"; }
};

int main() {
    Base* ptr_base = new Base();
    delete ptr_base;
    std::cout << "---------------------------\n"; 
    Base* ptr_inherit = new Inherit();
    delete ptr_inherit;
    return 0;

}

