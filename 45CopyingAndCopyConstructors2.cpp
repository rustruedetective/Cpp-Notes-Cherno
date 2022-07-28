#include "temp.h"
#include <string>
#include <cstring>   // strlen defined here

// Making a string class that is copyable

// in memcpy the dest and src is of type:- (const void* )
// this means pointer of void can be assigned any memory type so dont worry

// This one does not have the null termination character on purpose

// Design:-
// Store a string
// Take in a char array in constructor
// Print the string (e.g std::cout << obj... instead of std::cout << obj.stringmember...)
class String{
    char *buffer;
    unsigned int size;
public:
    String(const char* string){
        size = strlen(string);
        buffer = new char[size];   // note the size+1 is needed for null terminating character

        // now to copy the string from constructor to our own
        // for(int i = 0; i < size; i++)   // puny old method, looser
        //     buffer[i] = string[i];
        memcpy( buffer, string, size);   // this is what men use!
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& obj);
};

std::ostream& operator<<(std::ostream& stream, const String& obj){
    // stream << obj.getBuffer();   // We can also write a getBuffer function instead of making this a friend
    stream << obj.buffer;
    return stream;
}

int main(void){
    String string = "Hi there buddy!";
    logn( string )
    
    return 0;
}