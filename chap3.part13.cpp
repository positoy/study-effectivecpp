#include <iostream>
#include <memory>
using namespace std;

class Investment {
public:
    virtual ~Investment() {};
public:
    virtual int print() = 0;
};

class StockInvestment : public Investment {
public:
    StockInvestment();
    ~StockInvestment();
    int print();
private:
    int a,b,c;
};

StockInvestment::StockInvestment()
: a(1),b(2),c(3) {
    cout << "StockInvestment constructor" << endl;
}

StockInvestment::~StockInvestment() {
    cout << "StockInvestment destructor" << endl;
}

int StockInvestment::print() {
    throw exception();
    return a+b+c;
}

Investment* createInvestment() {
    StockInvestment* s = new StockInvestment();
    return s;
}

int main()
{
    std::shared_ptr<Investment> pInv(createInvestment());

    std::shared_ptr<Investment> pInv2(pInv);

    cout << pInv.get() << endl;
    cout << pInv2.get() << endl;

    if(pInv == pInv2)
        cout << "two pointers are same" << endl;
    // try {
    //     cout << "sum:" << pInv->print() << endl;
    // } catch (exception e) {
    //     return 0;
    // }
}