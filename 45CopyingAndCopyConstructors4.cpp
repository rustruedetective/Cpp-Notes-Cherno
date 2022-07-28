#include "temp.h"
#include <string>
#include <cstring>   // strlen defined here

// Copying:-
// Objects are copied like this:-
// All data members values are copied to the other object
// obj2 = obj1; here all data member of obj2 get assigned values of obj1 just like normal variables
// aka shallow copying of javascript

// So we need a deep copy

// Design:- (continued)
class String{
    char *buffer;
    unsigned int size;
public:
    String(const char* string){
        size = strlen(string);
        buffer = new char[size+1];
        memcpy( buffer, string, size);
        buffer[size] = 0;
    }
    ~String(){
        delete[] buffer;
    }
    char& operator[](unsigned int index){
        return buffer[index];
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& obj);
};

std::ostream& operator<<(std::ostream& stream, const String& obj){
    stream << obj.buffer;
    return stream;
}

int main(void){
    String string = "Hi there buddy!";
    String string2 = string;   // buffer of string and string2 is same, so both buffers point to same memory address
    
    // This demonstrates same memory being pointed to by buffer, so same value
    string2[0] = 'T';
    logn(string)
    logn(string2)

    // There is a problem here, when the program will end
    // We will first destruct string which would clear the buffer memory
    // Then string2 will destruct the buffer memory again! But since it was already cleared by string, we are trying to clear the now restricted memory

    return 0;
}