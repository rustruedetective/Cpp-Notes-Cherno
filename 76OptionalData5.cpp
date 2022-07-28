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

    // if we coudnt open the file and got nothing
    // but want to display a default value from it then use this
    std::string value = data.value_or("No data read.");
    
    log(value)
    if(data.has_value()){
        logn(data.value())
    }


    // theres also one for int
    std::optional<int> c;   // we oont have to worry about garbage initialization value lol
    int c2 = c.value_or(10);
    logn(c2)

    return 0;
}