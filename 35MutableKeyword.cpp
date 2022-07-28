#include "temp.h"

// One case use is in const methods in classes as shown above
// Other case is in lambdas

// mutable: can be changed
// immutable: cannot be changed

// Note: const objects can only call const methods not regular methods***

// what kind of variable we wanna modify in const method? well how about a count!

// Experiment needed: are global variables modifyable in const methods?

class Entity{
    std::string name;
    mutable int funCalls = 0;   // mutable!
public:
    const std::string& getname() const{
        // name = "howdy";   // we cant modify this
        funCalls++;
        return name;
    }
    void fun(){}
};

int main(void){
    const Entity e;
    e.getname();

    // e.fun();   // const objects can only call const methods, thats why we need them

    return 0;
}