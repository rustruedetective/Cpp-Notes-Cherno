#include "temp.h"
#include <cstring>

// so lets overload the move assignment

class String{
    char* m_Data;
    uint32_t m_Size;
public:
    String() = default;

    String(const char* string){
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(const String& other){
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String(String&& other) noexcept {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    String& operator=(String&& other) noexcept {
        printf("Moved!\n");
        // problem: 2. we need to not delete the data if we assign ourselves to ourselves
        if(&other != this)
        {
            // problem: 1. the data we stored needs to be deleted first, otherwise it would be a memory leak
            delete[] m_Data;

            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        return *this;
    }

    void print(){
        for(uint32_t i = 0; i < m_Size; i++)
            printf("%c", m_Data[i]);
        printf("\n");
    }

    ~String(){
        printf("Destroyed!\n");
        delete m_Data;
    }
};

class Entity{
    String m_Name;
public:
    Entity(const String& name) : m_Name(name) {}

    void printName(){
        m_Name.print();
    }

    Entity(String&& name) : m_Name( std::move(name) ) {

    }
};

int main(void){
    // now we can move assign too due to the overload
    String string = "Hello";
    String dest;
    
    std::cout << "string: ";
    string.print();
    std::cout << "dest: ";
    dest.print();
    dest = std::move(string);
    std::cout << "string: ";
    string.print();
    std::cout << "dest: ";
    dest.print();

    return 0;
}