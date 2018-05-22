#include <iostream>
#include <functional>
using namespace std;


// NVI method template

class Paladin {
public:
    int healthValue() const
    {
        static int retValue = 0;
        retValue = doHealthValue();
        int copyRet = retValue;
        retValue = 0;
        return copyRet;
    }
private:
    virtual int doHealthValue() const = 0;
};

class PaladinPlayer : public Paladin {
private:
    virtual int doHealthValue() const { return 70; }
};

// Function Pointer

class Magician;
typedef int (*MagicianHealthValuePinter)(const Magician& m);
class Magician {
public:
    Magician(MagicianHealthValuePinter pfunc) : healthValueFunction(pfunc), currentHealth(50) {};
    int healthValue() const { return healthValueFunction(*this); }
    int currentHealth;
private:
    MagicianHealthValuePinter healthValueFunction;
};

int getMagicianHealthValue(const Magician& m) { return m.currentHealth; }

// (Function Object)
class Soceress;
typedef std::function<int (const Soceress&)> SoceressHealthValuePointer;
class Soceress {
public:
    Soceress(SoceressHealthValuePointer pfunc) : healthValueFunction(pfunc), currentHealth(60) {};
    int healthValue() const { return healthValueFunction(*this); }
    int currentHealth;
private:
    SoceressHealthValuePointer healthValueFunction;
};

int getSoceressHealthInt(const Soceress& s) { return s.currentHealth; }
short getSoceressHealthShort(const Soceress& s) { return s.currentHealth; }
struct getSoceressHealthValue2 {
    int operator()(const Soceress& s) {
        return s.currentHealth;
    }
};


class GameCharacter;
class HealthCalcFunc {
public:
    virtual int doHealthValue(const GameCharacter& gc);
};

HealthCalcFunc defaultHealthCalcFunc;
class GameCharacter {
public:
    GameCharacter() : currentHealth(30000), hcf(&defaultHealthCalcFunc) {}
    GameCharacter(int _currentHealth) : currentHealth(_currentHealth), hcf(&defaultHealthCalcFunc) {}
    GameCharacter(HealthCalcFunc* _hcf) : currentHealth(30000), hcf(_hcf) {}
    GameCharacter(int _currentHealth, HealthCalcFunc* _hcf) : currentHealth(_currentHealth), hcf(_hcf) {}
    int healthValue() const { return hcf->doHealthValue(*this); }
    int currentHealth;
private:
    HealthCalcFunc *hcf;
};

int HealthCalcFunc::doHealthValue(const GameCharacter& gc) { return gc.currentHealth; }

class GameCharacterWizard : public GameCharacter {
public:
    GameCharacterWizard() : GameCharacter(20000) {};
    GameCharacterWizard(HealthCalcFunc *_hcf) : GameCharacter(20000, _hcf) {};
};

class HealthCalcFuncForWizard : public HealthCalcFunc {
public:
    int doHealthValue(const GameCharacter& gc) { return 2 * gc.currentHealth; }
};

int main()
{
    // NVI template method
    PaladinPlayer paladin;
    std::cout << paladin.healthValue() << std::endl;

    // Function Pointer
    Magician magician(getMagicianHealthValue);
    std::cout << magician.healthValue() << std::endl;

    // Function Pointer (function object)
    Soceress soceressInt(getSoceressHealthInt);
    std::cout << soceressInt.healthValue() << std::endl;

    Soceress soceressShort(getSoceressHealthShort);
    std::cout << soceressShort.healthValue() << std::endl;

    Soceress soceress2((getSoceressHealthValue2())); // ** vexing parse warning!
    std::cout << soceress2.healthValue() << std::endl;

    // classic strategy pattern
    GameCharacter gc;
    std::cout << gc.healthValue() << std::endl;

    // GameCharacterWizard gcw(new HealthCalcFuncForWizard());
    // std::cout << gcw.healthValue() << std::endl;
    GameCharacterWizard gcw;
    std::cout << gcw.healthValue() << std::endl;

    GameCharacterWizard gcw2(new HealthCalcFuncForWizard());
    std::cout << gcw2.healthValue() << std::endl;



}
