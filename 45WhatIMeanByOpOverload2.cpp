#include "temp.h"
#include <string>
#include <cstring>   // strlen defined here

// And no need to use operator overloading and make a new object inside it with a consructor and assign that to the object being copied to...
// It would make 2 objects, (one to copy to and one which will be copies), 2 constructor calls and one destructor as we will kill the old object which is being copied to

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

    String& operator=(String& obj){
        // Local scope vs heap...which one to do...hmm
        String newObj = obj.buffer;   // here i called the constructor to create new object...now to assign it to this same object
        return newObj;   // why not use a smart pointer...lol
    }
};

std::ostream& operator<<(std::ostream& stream, const String& obj){
    stream << obj.buffer;
    return stream;
}

int main(void){
    String string = "Hi there buddy!";
    String string2 = string; 

    string2[0] = 'T';
    logn(string)
    logn(string2)

    return 0;
}