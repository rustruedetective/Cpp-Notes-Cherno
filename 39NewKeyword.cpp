#include "temp.h"

// The new keyword asks the os to allocate it memory depending on size of type and array length
// Then the os searches for this memory in a smart way (by free list) then sends it back address to this memory
// The new keyword returns us this address

using String = std::string;

class Entity{
    String name;
public:
    Entity() : name("Unkown") {}
    Entity(const String & n) : name(n) {}

    const String & getname() const { return name; }
};

int main(void){
    int a = 2;
    int * b = new int;
    int * c = new int[50];

    // The 'new' keyword not only asks for memory on heap but also calls constructors for classes
    // Both are valid ways to call constructor
    Entity * ptr = new Entity;
    Entity * ptr2 = new Entity();

    // This asks for sizeof(Entity)*50 bytes of memory in heap
    // This memory should be continuous and not like split some here and some there
    Entity * ptr3 = new Entity[50];

    delete b;
    delete[] c;
    delete ptr;
    delete ptr2;
    delete[] ptr3;

    return 0;
}