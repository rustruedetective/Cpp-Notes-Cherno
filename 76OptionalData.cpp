#include "temp.h"
#include <fstream>

// E.g we read a file but it couldnt be read
// So instead of passing an emtpy string we do something else

// This is a clunky and funny way of doing it:-

std::string ReadFileAsString(const std::string& filepath){
    std::ifstream stream(filepath);
    if(stream){
        std::string result;
        // read it
        stream.close();
        return result;
    }
    // if not read successfully then return empty string
    // std::string() is empty string
    return std::string();
}

int main(void){
    std::string data = ReadFileAsString("data.txt");
    if(data != ""){
        // if data was read then do this
    }
    return 0;
}