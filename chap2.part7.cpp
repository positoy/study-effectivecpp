// factory

// 소멸자

// 가상함수

// 순수가상함수


#include <iostream>

class TimeKeeper {
public:
    enum class ClockType {
        AtomicClock=1,
        WaterClock
    };
    virtual ~TimeKeeper() { std::cout << "TimeKeeper destructor" << std::endl; }
    virtual unsigned long long getCurrentTime() = 0;
};

class AtomicClock : public TimeKeeper {
public:
    virtual ~AtomicClock() { std::cout << "AtomicClock destructor" << std::endl; }
    virtual unsigned long long getCurrentTime() { return 1 * 10; }
};

class WaterClock : public TimeKeeper {
public:
    virtual ~WaterClock() { std::cout << "WaterClock destructor" << std::endl; }
    virtual unsigned long long getCurrentTime() { return 1 * 10000; }
};

TimeKeeper* getTimeKeeper(TimeKeeper::ClockType clockType) {
    
    if (TimeKeeper::ClockType::AtomicClock == clockType)
        return new AtomicClock();
    else if (TimeKeeper::ClockType::WaterClock == clockType)
        return new WaterClock();
    
    return nullptr;
}

int main()
{
    TimeKeeper* ac = getTimeKeeper(TimeKeeper::ClockType::AtomicClock);
    TimeKeeper* wc = getTimeKeeper(TimeKeeper::ClockType::WaterClock);

    std::cout << "atomic clock time : " << ac->getCurrentTime() << std::endl;
    std::cout << "water clock time : " << wc->getCurrentTime() << std::endl;

    delete ac;
    delete wc;
}
