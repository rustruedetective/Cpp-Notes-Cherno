#include "temp.h"

// These c++ castings are just to make our life easier

class Base {
public:
    Base(){}
    virtual ~Base(){}
};

class Derived : public Base {
public:
    Derived() {}
    ~Derived() {}   // always put virtual unless you are sure it wont derive any child class
};

class AnotherClass : public Base {
public:
    AnotherClass() {}
    ~AnotherClass() {}
};

int main(void){
    // 1. Static cast compile checking error e.g:-

    int a = 10;
    // AnotherClass obj = (AnotherClass)a;   // c++ isnt dumb so wont allow this, the constructor protects it here
    // AnotherClass* obj = (AnotherClass*)a;   // but c++ is dumb in the pointer domain...
    // now this is bad...lol
    // it will compile with warning
    
    // AnotherClass* obj = static_cast<AnotherClass*>(a);   // now static performed checks and stopped this foolery


    // 2. reinterpret data will re interpret the data lol:-
    // its actually type punning
    // so you interpret the same memory as some other type
    AnotherClass* obj = reinterpret_cast<AnotherClass*>(a);
    

    // 3. dynamic cast e.g:-
    Derived* derived = new Derived();
    Base* base = derived;   // ok so the confusing thing is is base pointer pointing to base class, derived class or anotherclass?
    // to solve this use dynamic cast as it returns null when conversion fails lol...handy for checking
    
    // so what happens is ....since base is not of type AnotherClass the dynamic cast will give ac a value of null
    // if we had used static cast, it would have worked and we would have assigned one class to another which would have been wrong
    AnotherClass * ac = dynamic_cast<AnotherClass*>(base);
    // here it wont assing null as it base actually points to Derived obj
    Derived * d = dynamic_cast<Derived*>(base);

    logn("ac: " << ac)
    logn("d: " << d)

    return 0;
}