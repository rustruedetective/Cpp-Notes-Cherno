#include "temp.h"
#include <string>
#include <cstring> // strlen defined here

// Instead of writing an operator overload for = which would copy the members of your choice
// Why not call a constructor everytime we copy?
// A Copy Constructor!

// And no need to use operator overloading and make a new object inside it with a consructor and assign that to the object being copied to...
// It would make 2 objects, (one to copy to and one which will be copies), 2 constructor calls and one destructor as we will kill the old object which is being copied to
// Instead use Copy Constructor

// The default copy constructor is C++ can only do shallow copying
// We have seen in previous programs

// Design:- (continued)
// Default Copy constructor that was responsible for shallow copy
class String
{
    char *buffer;
    unsigned int size;

public:
    String(const char *string)
    {
        size = strlen(string);
        buffer = new char[size + 1];
        memcpy(buffer, string, size);
        buffer[size] = 0;
    }

     // Default C++ Copy Constructor 1:-
    String(const String &obj) : buffer(obj.buffer), size(obj.size)   // it does shallow copying
    {

    }
    // Default C++ Copy Constructor 2:-
    // String(const String &obj)
    // {
    //     memcpy(this, &obj, sizeof(String));   // it does shallow copying
    // }

    ~String()
    {
        delete[] buffer;
    }
    char &operator[](unsigned int index)
    {
        return buffer[index];
    }
    friend std::ostream &operator<<(std::ostream &stream, const String &obj);
};

std::ostream &operator<<(std::ostream &stream, const String &obj)
{
    stream << obj.buffer;
    return stream;
}

int main(void)
{
    String string = "Hi there buddy!";
    String string2 = string; // shallow copy

    return 0;
}