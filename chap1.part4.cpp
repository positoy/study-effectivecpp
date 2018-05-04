/*********************************************
 * 항목4. 객체를 사용하기 전에 반드시 그 객체를 초기화하자
 * *******************************************/

#include <iostream>
#include <string>
#include <list>

class PhoneNumber {
private:
    int number;
};

class ABEntry {
public:
    ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber> phones, PhoneNumber _masterNumber);
    const int data;
    static int staticNumber;
    
private:
    int numTimesConsulted;
    PhoneNumber& masterNumber;
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
};

ABEntry::ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber> phones, PhoneNumber _masterNumber)
// 초기화리스트 사용 "대입은 초기화가 아니다"
// 1. 기본제공타입
: numTimesConsulted{0},
// 2. 상수, 참조자 (대입자체가 불가능)
    data{3},
    masterNumber{_masterNumber},
    // staticNumber{9000}, static 초기화는 넌센스
// 2. 클래스 (기본생성자, 복사생성자, 참조자)
    theName{},
    theAddress{address},
    thePhones{phones}
// 3. 참고
    // * 생성자가 여러개이고 반복되는 대입연산자 초기화가 있다면 함수화하여 코드중복을 피할 수 있다
    // * 멤버의 초기화 순서 원칙 두가지 (1) 기본클래스->파생클래스 (2) 변수의선언순서대로
{
    // 대입은 초기화가 아니다
    // theName = name;
    // theAddress = address;
    // thePhones = phones;
    // numTimesConsulted = 0;
};

int ABEntry::staticNumber = 90000;

int main()
{

    std::cout << ABEntry::staticNumber << std::endl;
    


}