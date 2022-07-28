#include "temp.h"
#include <string>
#include <cstring>   // strlen defined here

// This one has the null termination character***
// two ways:-
// 1. copy the char array in constructor completely
// 2. assign ur own null termination character

// Design:- (continued)
// Make sure string is null terminated
// Deallocate memory on heap
class String{
    char *buffer;
    unsigned int size;
public:
    String(const char* string){
        size = strlen(string);
        buffer = new char[size+1];
        // method 1:-
        // memcpy( buffer, string, size+1);

        //method 2:-
        memcpy( buffer, string, size);
        buffer[size] = 0;
    }
    ~String(){
        delete[] buffer;   //deallocation on heap
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& obj);
};

std::ostream& operator<<(std::ostream& stream, const String& obj){
    stream << obj.buffer;
    return stream;
}

int main(void){
    String string = "Hi there buddy!";
    logn( string )
    
    return 0;
}