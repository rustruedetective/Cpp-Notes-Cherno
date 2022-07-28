#include "temp.h"

// steps
// 1. prevent people from making the an object of the class via constructor being private
// 2. make a static singleton object in private, and also delcaring it outside the class
// 3. a get function to get the single instance of this class
class Singleton{
    Singleton(){}
    static Singleton s_Instance;
public:
    static Singleton& Get(){
        return s_Instance;
    }
    void fun(){}
};
Singleton Singleton::s_Instance;



int main(void){
    // This is how to use
    Singleton::Get().fun();
    Singleton& instance = Singleton::Get();   // not recommended

    // This is how not to use...as we would copy all the object members into a newly created object
    // it also kills the purpose of a singleton
    Singleton instance2 = Singleton::Get();
    return 0;
}