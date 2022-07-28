#include "temp.h"

// they are important in polymorphism

// when you want to have the virtual parent's destructor get called along with the inherited object's destructor
// that is virtual destructor

// Notice case 3
// There is a huge memory leak risk
// The destructor of our dynamically allocated object is never called!
// if the child has dynamic data members, they wont be deleted if the delete is put in destructor

class Base{
public:
    Base(){ logn("Base created") }
    ~Base(){ logn("Base Destroyed") }
};

class Derived : public Base{
public:
    Derived(){ logn("Derived created") }
    ~Derived(){ logn("Derived Destroyed") }
};

int main(void){
    // 1.
    Base* objB = new Base();
    delete objB;
    logn("")

    // 2.
    Derived* objD = new Derived();
    delete objD;
    logn("")


    // 3.
    Base* objPolymorphed = new Derived();
    delete objPolymorphed;
    logn("")
    
    return 0;
}