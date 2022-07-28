#include "temp.h"

using String = std::string;

class Entity{
    String name;
    int age;
public:
    Entity(const String & n) : name(n), age(-1) {}
    Entity(int a) : name("Unknown"), age(a) {}
};

void print(const Entity & obj){
    // Printing here
}

int main(void){
    // Third way to instantiate objects
    // Entity obj = "abc";   this wont work as its char array
    Entity obj = String("abc");   // first constructor called, note we have to convert the char array into string type
    Entity obj2 = 123;   // second constructor called
    // This is called implicit conversion or 'implicit construction'


    // Now implicition construction is not limited to definitons but also can be used here
    print(89);   // the 22 was implicitly constructed into the object due to its constructor
    // print("xyz");   //this wont work as its char array
    print( String("xyz") );

    return 0;
}