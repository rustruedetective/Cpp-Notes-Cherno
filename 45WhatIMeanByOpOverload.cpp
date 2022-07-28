#include "temp.h"
#include <string>
#include <cstring>   // strlen defined here

// Instead of writing an operator overload for = which would copy the members of your choice

// The op overload function was never called i dont know why...

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

    void operator=(String& obj){
        // but this is the same code as the constructor!
        delete[] this->buffer;
        size = obj.size;
        this->buffer = new char[size+1];
        memcpy( this->buffer, obj.buffer, size+1);
        logn("Copy by op overloading")
    }
};

std::ostream& operator<<(std::ostream& stream, const String& obj){
    stream << obj.buffer;
    return stream;
}

int main(void){
    String string = "Hi there buddy!";
    String string2 = string; 

    // The op overload and our choice of copying
    string2[0] = 'T';
    logn(string)
    logn(string2)

    return 0;
}