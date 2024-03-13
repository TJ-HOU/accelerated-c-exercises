#include <iostream>

class A {
    public:
    A() { std::cout << "A constructor is called\n"; }
    virtual ~A() { std::cout << "A destructor is called\n"; }
};

class B: virtual public A {};

class C: virtual public A {};

class D: virtual public B, C {};

int main() {
    D* ptr_d = new D();
    delete ptr_d;

    return 0;
}