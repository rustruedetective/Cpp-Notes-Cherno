#include "temp.h"
#include <fstream>
#include <optional>


std::optional<std::string> ReadFileAsString(const std::string& filepath){
    std::ifstream stream(filepath);
    if(stream){
        std::string result;
        // read it
        stream.close();
        return result;
    }

    return {};
}

int main(void){
    std::optional<std::string> data = ReadFileAsString("data.txt");   // also could use auto
    if(data.has_value()){
        // reading from data
        // 1.
        std::string& str = *data;
        // 2.
        // data->stringhere...?
        // 3.
        data.value();
    }
    return 0;
}