// Log systems has these levels:-
// Error
// Warning
// Message/Trace

#include <iostream>

//This is shitty code btw:-

class Log{
    //we seperated the public vars and public functions for clarity
    public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

    private:
    int m_LogLevel = LogLevelInfo;   //m_ tells that this member variable is private, this is the current level, by default its LogLevelInfo
    
    public:
    void setLevel(int level){
        m_LogLevel = level;
    }

    void error(const char* message){   // why is it char* and not *char?
        if(m_LogLevel  >= LogLevelError)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void warn(const char* message){
        if(m_LogLevel  >= LogLevelWarning)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    void info(const char* message){
        if(m_LogLevel  >= LogLevelInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }
};

int main(void){
    Log log;
    log.setLevel(log.LogLevelError);
    log.warn("Hello");
    log.error("Hello");
    return 0;
}