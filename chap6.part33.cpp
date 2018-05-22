#include <iostream>
using namespace std;

class Base {
public:
    void hello() { cout << "hello" << endl; }
    void hello(double) { cout << "hello double" << endl; }
private:
    void yellow() { cout << "yelllow" << endl; }
};

class DerivedPublic : public Base {
public:
    using Base::hello;
    void hello() { cout << "hello from derived" << endl; }
};

class DerivedPrivate : private Base {
public:
    void hello() { Base::hello(); }
};
    

int main()
{
    DerivedPublic dpublic;
    dpublic.hello(1.23);

    DerivedPrivate dprivate;
    dprivate.hello();
}