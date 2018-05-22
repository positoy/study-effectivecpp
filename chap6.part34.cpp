#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual void error(const std::string& msg);
    int objectID() const { return 1; }
};

void Shape::draw() {
    cout << "------" << endl;
}
void Shape::error(const std::string& msg) {
    cout << msg << endl;
}

class Ellipse : public Shape {
public:
    virtual void draw();

};

void Ellipse::draw() {
    cout << "ellipse draw" << endl;
}

int main()
{
    Shape* sptr = new Shape();
    sptr->Shape::draw();
        
}