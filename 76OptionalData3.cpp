#include "temp.h"
#include <fstream>
#include <optional>

// c++17

// An even better way:-

std::optional<std::string> ReadFileAsString(const std::string& filepath){
    std::ifstream stream(filepath);
    if(stream){
        std::string result;
        // read it
        stream.close();
        return result;
    }

    return {};   // this is std::optional...lol
}

int main(void){
    std::optional<std::string> data = ReadFileAsString("data.txt");   // also could use auto
    if(data.has_value()){   // if it did not just pass {} or empty string
    }
    else{
    }
    // or also could just use
    if(data){
    }
    else{
    }
    return 0;
}