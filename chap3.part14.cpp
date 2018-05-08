#include <iostream>
#include <memory>
using namespace std;

class Mutex {
public:
    Mutex() : isLock(false) {};
    bool isLock;
};
void lock(Mutex* pmutex) {
    pmutex->isLock = true;
    cout << "locked" << endl;
}
void unlock(Mutex* pmutex) {
    if (pmutex == nullptr || pmutex->isLock == false) {
        cout << "already unlocked" << endl;
        return;
    }
    cout << "unlocked" << endl;
    pmutex->isLock = false;
}

class Lock1 { // 1. 금지
public:
    Lock1(Mutex *_pmutex)
    : pmutex(_pmutex) {
        lock(pmutex);
    }
    ~Lock1() {
        unlock(pmutex);
    }
private:
    Lock1(const Lock1& rhs);
    Lock1& operator=(const Lock1& rhs);
    Mutex *pmutex;
};

class Lock2 { // 2. RCSP
public:
    Lock2(Mutex* ptrMutex)
    : sharedPtrMutex(ptrMutex) {
        lock(sharedPtrMutex.get());
    }
    ~Lock2() {
        unlock(sharedPtrMutex.get());
    }
    Mutex* get() {
        return sharedPtrMutex.get();
    }
private:
    std::shared_ptr<Mutex> sharedPtrMutex;
};


class Lock3 { // 3. 깊은복사
public:
    Lock3(Mutex *_pmutex)
    : pmutex(_pmutex) {
        lock(pmutex);
    }
    Lock3(const Lock3& rhs) {
        pmutex = new Mutex();
        *pmutex = *rhs.pmutex;
    }
    Lock3& operator=(const Lock3& rhs) {
        *pmutex = *rhs.pmutex;
        return *this;
    }
    ~Lock3() {
        unlock(pmutex);
    }
    Mutex* get() { return pmutex; }
private:
    Mutex *pmutex;
};

class Lock4 { // 4. 소유권을 옮기기
public:
    Lock4(Mutex *_pmutex)
    : pmutex(_pmutex) {
        lock(pmutex.get());
    }
    ~Lock4() {
        unlock(pmutex.get());
    }
    Mutex* get() { return pmutex.get(); }
private:
    std::auto_ptr<Mutex> pmutex;
};

int main()
{

    {
        cout << endl << "# RAII : 금지" << endl;
        Lock1 lock1(new Mutex());
        // Lock1 lock1_copy(lock1);
        // Lock1 lock2(ptrmutex);
        // lock1 = lock2;
    }

    {
        cout << endl << "# RAII : RCSP" << endl;
        Lock2 lock2(new Mutex());
        Lock2 lock2_copy(lock2);

        cout << lock2.get() << '/' << lock2_copy.get() << endl;
    }

    {
        cout << endl << "# RAII : 소유권변경" << endl;
        Lock4 lock4(new Mutex());
        Lock4 lock4_copy(lock4);
        std::cout << lock4.get() << '/' << lock4_copy.get() << endl;
    }

    {
        cout << endl << "# RAII : 깊은복사" << endl;
        Lock3 lock3(new Mutex());
        Lock3 lock3_copy(lock3);
        std::cout << lock3.get() << '/' << lock3_copy.get() << endl;
    }


}