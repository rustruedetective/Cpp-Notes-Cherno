#include "temp.h"
#include <string>
#include <cstring> // strlen defined here

// One consequence of copy constructor

// This is the reason we should always pass objects with const reference!
// (if the function needed a copy it can copy later in the function)
// Except in rare optimization cases where copying is faster...lol yeah..pretty fked up

// Design:- (continued)
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

void printy(String obj){
    logn( obj )
}

// Reference so we dont copy unnecessarily
// Const so our reference cant be changed
void printy2(const String& obj){
    logn( obj )
}

int main(void)
{
    String string = "Hi there buddy!";
    String string2 = string; // deep copy

    string2[0] = 'T';

    // here we just copied our objects all over again on each call
    printy(string);
    printy(string2);

    // now these calls dont copy the whole object on each call
    printy2(string);
    printy2(string2);

    return 0;
}