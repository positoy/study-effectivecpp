#include <iostream>

class Uncopyable {
public:
    Uncopyable(){};
private:
    Uncopyable(const Uncopyable& rhs);
    Uncopyable& operator=(const Uncopyable);
};

class Noncopyable {
public:
    Noncopyable(){};
private:
    Noncopyable(const Noncopyable& rhs);
    Noncopyable& operator=(const Noncopyable);
};

class HomeForSale : private Noncopyable {

};

int main()
{
    // 기법1. 복사생성자, 복사대입연산자를 private으로 선언하기
    Uncopyable a;
    // Uncopyable b(a);
    // Uncopyable b = a;
    Uncopyable b;
    // a = b;

    // 기법2. Noncopyable 클래스의 상속
    HomeForSale hfs;
    // HomeForSale hfs2(hfs);
    // HomeForSale hfs2 = hfs;
    HomeForSale hfs2;
    // hfs = hfs2;  
}