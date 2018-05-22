#include <iostream>

class Base {
public:
    void funcA() { std::cout << "funcA" << std::endl; }
    virtual void funcB() { std::cout << "funcB" << std::endl; }
};

class Derived : public Base {
public:
    void funcA() { std::cout << "funcA - from Derived" << std::endl; }
    virtual void funcB() { std::cout << "funcB - from Derived" << std::endl; }
};

int main()
{
    Base* ptrB = new Derived();
    Derived* ptrD = new Derived();

    // Non-virtual function --> static binding (buildtime)
    ptrB->funcA();
    ptrD->funcA();

    // virtual function --> dynamic binding (runtime)
    ptrB->funcB();
    ptrD->funcB();

}