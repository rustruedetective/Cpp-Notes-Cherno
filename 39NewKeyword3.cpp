#include "temp.h"

// The new keyword can be paced a placement address as an argument
// Then it allocated memory inside this memory whose address we passed in to it

using String = std::string;

class Entity{
    String name;
public:
    Entity() : name("Unkown") {}
    Entity(const String & n) : name(n) {}

    const String & getname() const { return name; }
};

int main(void){
    int * ptr = new int[50];
    Entity * ptr2 = new(ptr) Entity;   // yeah it doesnt even have to be the same type

    delete[] ptr;
    delete ptr2;

    return 0;
}