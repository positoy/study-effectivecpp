#include <iostream>
using namespace std;


class Bird {
};

class FlyingBird : public Bird {
public:
    virtual void fly();
}

class Penguin : public Bird {
public:
};

int main()
{

    Bird *b = new Penguin();
    b->fly();

 }