#include <iostream>
#include <string>
/*
 항목1. C++을 언어들의 연합체로 바라보는 안목은 필수

 C++의 어느 기능을 사용하느냐에 따라서 프로그래밍의 원칙이 달라진다.
 - C : 값 전달이 효율이 좋다
 - C++ : 객체 참조자에 의한 전달이 효과가 좋다 (깊은복사를 구현하지 않아도 되니깐)
 - 메타프로그래밍 : 역시 참조자
 - STL : 값 전달
*/

/*
 항목2. #define을 쓰려거든 const, enum, inline을 떠올리자
      (전처리보다 컴파일러)

 - const
 - enum
 - inline
*/


// 3. 클래스 내부에 상수가 필요할 때는 static const, enum을 쓰자
class Coffee {
    public:
    static const int CoffeeBeans = 12;
    static const std::string brewery;
    enum { numOfBeans = 3 };
};
const std::string Coffee::brewery("Starbucks");

// 4. 문제가 많은 매크로 대신 템플릿 인라인 함수 사용
template<typename T>
inline T callWithMax(const T& a, const T& b) {
    return a > b ? a : b;
}

int main()
{



    // 1. define 대신 const를 쓰자
    #define ASPECT_RATIO 1.653
    double ar = ASPECT_RATIO;
    const double AspectRatio = 1.653;
    std::cout << ar << ' ' << AspectRatio << std::endl;


    // 2. 문자열 상수가 필요할 때에도 const를 써서 헤더에 정의해주자
    const char* const authorName = "Scott Meyers";
    const std::string title("Effective C++");
    std::cout << authorName << ' ' << title << std::endl;

    // 3. 클래스 내부에 상수가 필요할 때는 static const, enum을 쓰자
    Coffee coffee;
    std::cout << coffee.CoffeeBeans << ' ' << coffee.brewery << ' ' << coffee.numOfBeans << std::endl;

    // 4. 문제가 많은 매크로 대신 템플릿 인라인 함수 사용
    #define CALL_WITH_MAX(a,b) ((a)>(b) ? (a) : (b))
    int x = 7, y = 0;
    std::cout << CALL_WITH_MAX(++x, y) << std::endl;
    std::cout << CALL_WITH_MAX(++x, y+10) << std::endl; // x가 두번씩 증가

    x=7,y=0;
    std::cout << callWithMax(++x, y) << std::endl;
    std::cout << callWithMax(++x, y+10) << std::endl; // x가 두번씩 증가
}