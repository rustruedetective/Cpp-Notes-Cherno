#include "temp.h"
#include <string>
#include <cstring> // strlen defined here

// The default copy constructor is C++ can only do shallow copying
// We have seen in previous programs

// So we make our own Copy Constructor

// Design:- (continued)
// Personally made Copy constructor for deep copy
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

    // Deep copy constructor
    String(const String &obj) : size(obj.size)
    {
        this->buffer = new char[size+1];
        memcpy( this->buffer, obj.buffer, size+1);
    }

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
    String string2 = string; // deep copy

    string2[0] = 'T';
    logn(string)
    logn(string2)

    return 0;
}