#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

class ThrowExceptionInDestructor {
public:
    ~ThrowExceptionInDestructor() {
        throw exception();
    }
};

int main()
{
    vector<ThrowExceptionInDestructor> v;

    ThrowExceptionInDestructor teid, teid2;

    v.push_back(teid);
    v.push_back(teid2);

    cout << v.size() << endl;


}