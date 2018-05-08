#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    Customer() : customerName("yellow")
    {
        cout << "basic custructor called" << endl;
    }
    Customer(const Customer& rhs)
    : customerName("hello")
    {
        cout << "copy custructor called" << endl;
        customerName = rhs.customerName;
    }
    Customer& operator=(const Customer& rhs) {
        cout << "copy assignment operator called" << endl;
        this->customerName = rhs.customerName;
        return *this;
    }
private:
    string customerName;
};

int main()
{
    Customer c1;
    Customer c2 = c1;
    Customer c3(c1);
    c3 = c1;
}

