#include "temp.h"
#include <string>
#include <cstring> // strlen defined here

// The default copy constructor is C++ can only do shallow copying
// We have seen in previous programs

// So we make our own Copy Constructor

// But first!
// In order to prevent default copy constructor from being called use the delete keyword

// Design:- (continued)
// Copy constructor does nothing now!
class String
{
    char *buffer;
    unsigned int size;

public:


    String(const String &obj) = delete;

};

int main(void)
{
    String string = "Hi there buddy!";
    String string2 = string;

    return 0;
}