#include <iostream>
#include <list>

template <typename T>
class Set {
public:
    bool member(const T& item) { return std::find(rep.begin(), rep.end(), item) != rep.end(); }
    void insert(const T& item) { if (!member(item)) rep.push_back(item); }
    void remove(const T& item) {
        typename std::list<T>::iterator it = std::find(rep.begin(), rep.end(), item);
        if (it != rep.end()) rep.erase(it);
    }
    std::size_t size() const { return rep.size(); }
private:
    std::list<T> rep;
};

int main()
{
    Set<std::string> set;
    set.insert("hello");
    set.insert("yellow");
    if (set.member("hello"))
        std::cout << "hello in the set (" << set.size() << ")" << std::endl;
    set.remove("hello");
    std::cout << "size(" << set.size() << ")" << std::endl;
}