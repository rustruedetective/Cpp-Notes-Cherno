#include "temp.h"
#include <cstring>

// here we use the new keyword to allocate memory on the heap simply to copy a constructor
// damn boy thats not wise

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

    // 2. writing the copy constructor
    String(const String& other){
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
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
};

int main(void){
    // Problem is we created an object and copied it, the original created object is destroyed...like i had my concerns
    Entity entity( String("Abc") );

    entity.printName();

    return 0;
}