#include <iostream>

// 1. declaration : 어떤 대상의 이름과 타입을 컴파일러에게 알려주는 것
extern int x;
std::size_t nummDigits(int number);
class Widget;
template<typename T>
class GraphNode;

// 2. definition : 선언에서 빠진 구체적인 세부사항을 컴파일러에게 제공하는 것
int x; //?
std::size_t nummDigits(int number) {
    std::size_t digitsSoFar=  1;
    while((number/10) != 0) ++digitsSoFar;
    return digitsSoFar;
}
class Widget {
    public:
    Widget(){};
    ~Widget(){};
};
template<typename T>
class GraphNode {
    public:
    GraphNode(){};
    ~GraphNode(){};
};

// 3. explicit
class A {
    public:
    A(){};
};
class B {
    public:
    explicit B(int x, bool b = true){ integer = x; };
    void print() { std::cout << integer << std::endl; }
    private:
    int integer;
};
class C {
    public:
    explicit C(int x){};
};
void doSomething(B param) {
    param.print();
}

// 4. copy constructor, copy assignment operator
class CC {
    public:
    CC() { hello = 3; };
    CC(const CC& rhs);
    Widget& operator=(const Widget& rhs);
    void print() { std::cout << hello << std::endl; };
    private:
    int hello;
};

int main()
{
    std::cout << "hello world!" << std::endl;
    Widget w;
    GraphNode<int> g;

    // 3. explicit
    B b(0); //ok
    doSomething(b); // ok.
    // doSomething(12); // 암시적 변환실패
    doSomething(B(12));

    // 4. copy constructor, copy assignment operator
    CC c;
    CC c2(c);
    CC c3 = c;
    c.print();
    c2.print();
    c3.print();

    
}