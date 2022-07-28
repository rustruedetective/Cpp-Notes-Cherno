#include "temp.h"

// you can delete the copy constructor to prevent the copy

// second way

class Singleton{
    Singleton(){}
    static Singleton s_Instance;
public:
    static Singleton& Get(){
        return s_Instance;
    }
    Singleton(const Singleton&) = delete;
    void fun(){}
};
Singleton Singleton::s_Instance;



int main(void){

    Singleton::Get().fun();
    Singleton& instance = Singleton::Get();
    auto& instance2 = Singleton::Get();

    // Now it wont work, cause we made the constructor for copying is deleted
    // Singleton instance3 = Singleton::Get();
    return 0;
}