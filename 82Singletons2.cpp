#include "temp.h"

// you can make the copy constructor private to prevent the copy

class Singleton{
    Singleton(){}
    static Singleton s_Instance;
    Singleton(const Singleton&);
public:
    static Singleton& Get(){
        return s_Instance;
    }
    void fun(){}
};
Singleton Singleton::s_Instance;



int main(void){

    Singleton::Get().fun();
    Singleton& instance = Singleton::Get();
    auto& instance2 = Singleton::Get();

    // Now it wont work, cause we made the constructor for copying private
    // Singleton instance3 = Singleton::Get();
    return 0;
}