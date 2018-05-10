#include <iostream>

int main()
{
    std::string* name = new std::string; // [object]
    *name = "안창규";
    std::cout << *name << std::endl;
    // delete [] name;
    delete name;

    std::string* nameArr = new std::string[100]; // [ 100 ][object][object][object]...[object]
    nameArr[0] = "안창규";
    nameArr[1] = "이필수";
    std::cout << nameArr[0] << std::endl << nameArr[1] << std::endl;
    // delete nameArr;
    delete [] nameArr;

    typedef std::string ageArr[10];
    std::string *hello = new ageArr;
    hello[0] = "1";
    hello[1] = "10";
    std::cout << hello[0] << std::endl << hello[1] << std::endl;
    delete [] hello;


}