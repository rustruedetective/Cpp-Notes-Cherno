// Refactored with enums

//non-static data member initializers only available with -std=c++11 or -std=gnu++11

#include <iostream>

class Log{
    public:
    enum Level{
        Error, Warning, Info
    };

    private:
    int m_LogLevel = Info;
    
    public:
    void setLevel(int level){
        m_LogLevel = level;
    }

    void error(const char* message){
        if(m_LogLevel  >= Error)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void warn(const char* message){
        if(m_LogLevel  >= Warning)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    void info(const char* message){
        if(m_LogLevel  >= Info)
            std::cout << "[INFO]: " << message << std::endl;
    }
};

int main(void){
    Log log;
    log.setLevel(log.Error);
    log.warn("Hello");
    log.error("Hello");
    return 0;
}