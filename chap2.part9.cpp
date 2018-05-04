#include <iostream>

using namespace std;

class SuperClass {
public:
    SuperClass(const string& transactionContent) {
        logTranscation(transactionContent);
    }
    void logTranscation(const string& transactionContent) {
        cout << "logger activate : " << transactionContent << endl;
    }
};

class SubClass : public SuperClass {
public:
    SubClass(const string currentState);
    const string createLogString(const string& currentState);
};

SubClass::SubClass(const string currentState)
: SuperClass(createLogString(currentState)) {

}

const string SubClass::createLogString(const string& currentState) {
    return "2018.05.03 - time - " + currentState;
}

int main()
{
    SubClass sc("wow");

}
