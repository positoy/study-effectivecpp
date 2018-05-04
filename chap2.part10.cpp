#include <iostream>
#include <string>
using namespace std;

class SnowBall {
public:
    SnowBall& operator=(const string& _snow) {
        snow = _snow;
        return *this;
    }
    SnowBall& operator=(const SnowBall& _snowball) {
        snow = _snowball.snow;
        return *this;
    }
    SnowBall& operator+=(const SnowBall& _snowball) {
        snow += _snowball.snow;
        return *this;
    }
    string snow;
};

int main()
{
    SnowBall a,b,c;
    a=b=c="snow";
    c.snow = "hello";
    b += c;

    cout << a.snow << b.snow << c.snow << endl;

}