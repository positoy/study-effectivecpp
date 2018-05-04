#include <iostream>

// 생성자, 소멸자
// 복사생성자
// 복사대입연산자

using namespace std;
template<typename T>
class NewClass { 
public:
    NewClass(string title, T value);
    NewClass(char* title, T value);
    NewClass(NewClass& b);
    string getTitle() { return title; }
    T getValue() { return value; }
private:
    const string title;
    T& value;
};

template<typename T>
NewClass<T>::NewClass(string title, T value)
 : title{title}, value{value}
{}

template<typename T>
NewClass<T>::NewClass(char* title, T value)
 : title(title), value(value)
{}

template<typename T>
NewClass<T>::NewClass(NewClass& rhs)
 : title{rhs.title}, value(rhs.value)
{
}

int main()
{
    // 1. 기본생성자. 아무것도 명시하지 않으면 자동으로 만든다. 명시된 것이 있으면 자동으로 만들지 않는다.
    NewClass<int> p("my dog age", 5);
    NewClass<int> s("my dog height", 10);

    std::cout << p.getTitle() << ' ' << p.getValue() << std::endl;
    std::cout << s.getTitle() << ' ' << s.getValue() << std::endl;

    // NewClass<int> t; --> 암시적으로 만들어지지 않음


    // 2. 복사생성자 --> 선언하지 않았으므로 암시적으로 생성
    NewClass<int> x(p); // MyClass<int> x = p; 와 동일
    std::cout << x.getTitle() << ' ' << x.getValue() << std::endl;

    // 3. 복사대입연산자 --> 선언하지 않았으므로 암시적으로 생성
    // x = s; // --> 상수, 참조자 멤버가 있는 경우 컴파일 거부! 
    // std::cout << x.getTitle() << ' ' << x.getValue() << std::endl;
}