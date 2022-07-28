// Refactored with limiting data types to Level of all places these will be used

// Note if we have enums in class, we can directly call them
// Without the need for object

#include <iostream>

class Log{
    public:
    enum Level{
        Error, Warning, Info
    };

    private:
    Level m_LogLevel = Info;
    
    public:
    void setLevel(Level level){
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
    log.setLevel(Log::Error);
    log.warn("Hello");
    log.error("Hello");
    return 0;
}