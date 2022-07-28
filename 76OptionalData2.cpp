#include "temp.h"
#include <fstream>

// This is a better way:-

std::string ReadFileAsString(const std::string& filepath, bool& outSuccess){
    std::ifstream stream(filepath);
    if(stream){
        outSuccess = true;
        std::string result;
        // read it
        stream.close();
        return result;
    }
    outSuccess = false;

    return std::string();
}

int main(void){
    bool fileOpenSuccess = false;
    std::string data = ReadFileAsString("data.txt", fileOpenSuccess);
    if(fileOpenSuccess){
        // if data was read then do this
    }
    return 0;
}