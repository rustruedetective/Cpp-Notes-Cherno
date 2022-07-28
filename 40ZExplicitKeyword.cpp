#include "temp.h"

// The explicit keyword infront of the constructor will tell it no shinanigans like implicit conversions

using String = std::string;

class Entity{
    String name;
    int age;
public:
    explicit Entity(const String & n) : name(n), age(-1) {}
    Entity(int a) : name("Unknown"), age(a) {}
};

int main(void){
    // Implicit conversion is disabled by the explicit keyword for the particular constructor
    // Entity obj = String("abc");
    Entity obj2 = 123;   // No explicit keyword for this guy's constructor


    // Another way to initialize/instantiate objects
    Entity objb = (Entity)"abc";
    Entity objb2 = (Entity)123;
    // via type casting

    return 0;
}