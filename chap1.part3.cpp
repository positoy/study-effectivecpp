#include <iostream>
#include <vector>

// 항목3. 낌새만 보이면 const를 들이대 보자!
// -> 논리적 상수성을 고려하며 개발하자

int main()
{
    char str1[] = "hello!";
    char str2[] = "yello!";

    /************
     * 1. 포인터
     * ***********/

    // 비상수 데이터 비상수 포인터
    char* pstr1 = str1;
    pstr1 = str2;
    pstr1[0]='x';
    std::cout << pstr1 << std::endl;

    const char* pstr2 = str1;
    pstr2 = str2;
    // pstr2[0]='z'; 상수데이터 ; const 키워드가 *의 왼쪽에 있으면 포인터가 가리키는 대상이 상수
                                // void f1(const Widget* pw) 와 void f1(Widget const* pw) 는 똑같이 상수데이터
    std::cout << pstr2 << std::endl;

    char* const pstr3 = str1;
    // pstr3 = str2; 상수포인터 ; const 키워드가 *의 오른쪽에 있으면 포인터가 상수
    pstr3[0] = 'k';
    std::cout << pstr3 << std::endl;

    const char* const pstr4 = str1;
    // pstr4 = str2; 상수포인터
    // pstr4[0] = 's'; 상수데이터
    std::cout << pstr4 << std::endl;

    /************
     * 2. STL Iterator
     * ***********/
    std::vector<int> vec = {1,2,3};
    const std::vector<int>::iterator iter = vec.begin(); // T* const 처럼 동작 (싱수포인터)
    *iter = 10;
    // ++iter; 안됨

    std::vector<int>::const_iterator cIter = vec.begin(); // const T* 처럼 동작 (상수데이터)
    // *cIter = 11; 안됨
    ++cIter;


    /************
     * 3. 함수
     * ***********/
    class Rational {
    public:
        Rational(double value) { this->value = value; };
        const Rational operator*(const Rational &rhs) {
            this->value = this->value * rhs.value;
            return *this;
        };
        double getValue() { return value; }
    private:
        double value;
    };
    Rational a(0.1);
    Rational b(0.2);
    Rational c = a*b;
    std::cout << c.getValue() << std::endl;
    // a * b = c; 같은 실수를 방지할 수 있음


    /************
     * 4. 상수 멤버 함수
     * ***********/
    class TextBlock {
        public:
        TextBlock() : text{"empty"}{}
        TextBlock(std::string _text) { text = _text; }
        char& operator[](std::size_t position) {
            std::cout << "basic operator" << std::endl;
            return text[position];
        }
        const char& operator[](std::size_t position) const {
            std::cout << "const operator" << std::endl;
            return text[position];
        }
        private:
        std::string text;
    };

    TextBlock tb; // 비상수버전 호출
    std::cout << tb[0];
    tb[0] = 'y';

    const TextBlock ctb("hello"); // 상수버전 호출
    std::cout << ctb[0];
    // ctb[0] = 'y'; 컴파일에러!

    /************
     * 4. 상수멤버함수
     * ***********/
    // (1) 비트수준상수성 있음. 논리적상수성 없음.
    class CTextBlock {
        public:
        CTextBlock(std::string str) {
            pText = (char*)malloc(str.length() + 1);
            strcpy(pText, str.c_str());
        }
        char& operator[](std::size_t position) const {
            return pText[position];
        }
        void changeSecondCharacter() {
            pText[1] = '\0';
        }
        private:
        char* pText;
    };

    const CTextBlock cctb("Hello");
    char *pc = &cctb[0];
    *pc = 'Y';
    std::cout << cctb[0] << std::endl;
    // cctb.changeSecondCharacter(); const 지시자가 붇지 않은 멤버변수는 호출할 수 없음

    // (2) 비트수준상수성 없음. 논리적상수성 있음.
    class SmartTextBlock {
        public:
        SmartTextBlock(std::string str) : textLength{0}, lengthIsValid{false}{
            pText = (char*)malloc(str.length() + 1);
            strcpy(pText, str.c_str());
        }
        std::size_t length() /*const*/{
            if (!lengthIsValid) {
                textLength = std::strlen(pText);
                lengthIsValid = true;
            }
            return textLength;
        }
        private:
        char* pText;
        std::size_t textLength;
        bool lengthIsValid;
    };
    
    SmartTextBlock stb("hello"); // 논리적상수. const로 선언하면 length를 호출할 수 없다
    std::cout << stb.length() << std::endl;

    // 더 똑똑해진 SmartTextBlock.
    // - 언제든지 바꿀 수 있는 mutable 지시자 선언으로 const 멤버함수를 만들었다
    // - operator의 코드 중복을 피하기 위해서 캐스팅 사용 (비상수함수에서 상수함수 재활용)
    class CSmartTextBlock {
        public:
        CSmartTextBlock(std::string str) : textLength{0}, lengthIsValid{false}{
            pText = (char*)malloc(str.length() + 1);
            strcpy(pText, str.c_str());
        }
        const char& operator[](std::size_t position) const {
            return pText[position];
        }
        char& operator[](std::size_t position) {
            return const_cast<char&>(
                static_cast<const CSmartTextBlock&>(*this)[position]
            );
        }
        std::size_t length() const {
            if (!lengthIsValid) {
                textLength = std::strlen(pText);
                lengthIsValid = true;
            }
            return textLength;
        }
        private:
        char* pText;
        mutable std::size_t textLength;
        mutable bool lengthIsValid;
    };
    CSmartTextBlock cstb2("hello");
    std::cout << cstb2.length() << std::endl;

    const CSmartTextBlock cstb("hello"); 
    std::cout << cstb.length() << std::endl;



    

}