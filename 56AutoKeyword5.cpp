#include "temp.h"
#include <vector>
#include <unordered_map>

// c++11 needed

// auto still need s & for references and also const
// it only replaces pure data types not their modifications
// such as ref, address, pointer, const, static

// Good use case:
// 1. instead of using a massive type use auto
//    not for int, string, char etc, only for long massive types

class Device {};

class DeviceManager{
    std::unordered_map<std::string, std::vector<Device*>> Devices;
public:
    const std::unordered_map<std::string, std::vector<Device*>>& getDevices() const{
        return Devices;
    }
};

int main(void){
    DeviceManager dmObj;
    const std::unordered_map<std::string, std::vector<Device*>>& devices = dmObj.getDevices();
    
    // of topic, but we could use an alias for such a big type
    // or use typedef

    using DeviceMap = const std::unordered_map<std::string, std::vector<Device*>>&;
    DeviceMap devices2 = dmObj.getDevices();

    //or

    //1. 
    const auto& devices3 = dmObj.getDevices();

    return 0;
}