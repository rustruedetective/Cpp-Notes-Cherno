#include "temp.h"

// When to use?
// Always!!!!***

// virtual destructor makes case 3 same as case 2

// This happens as the virtual keyword tells c++ that this will have more destructors in the child class as well
// or more importantly just also call destructor on child objects

// now you can properly delete the dynamically allocated members

class Base{
public:
    Base(){ logn("Base created") }
    virtual ~Base(){ logn("Base Destroyed") }   // * virtual destructor
};

class Derived : public Base{
    int * ptr;
public:
    Derived(){
        ptr = new int;
        logn("Derived created")
        }
    ~Derived(){
        delete ptr;
        logn("Derived Destroyed") 
    }
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