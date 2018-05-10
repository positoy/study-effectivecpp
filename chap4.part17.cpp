#include <iostream>
#include <memory>
using namespace std;

int Priority() {
    throw exception();
    return 1;
}

void processWidget(std::shared_ptr<std::string> pw, int priority) {
    std::cout << pw.get() << std::endl;    
}

int main()
{
    try {
        // processWidget(std::shared_ptr<std::string>(new std::string), Priority());
        std::shared_ptr<std::string> pw(new std::string);
        processWidget(pw, Priority());
    } catch (exception e) {
        std::cout << "exception occured" << std::endl;
    }
}