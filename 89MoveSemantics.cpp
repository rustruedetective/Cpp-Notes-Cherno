#include "temp.h"
#include <cstring>

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
    // 1. Now this looks good but we need to copy this string obj in the entity object so we need a copy constructor
    // I dont get it though, why dont we just give the ref of object to member of entity instead of copying it
    // I think its because we first make the object inside the string class then assign it values from the "other" object with copy constructor
    Entity entity( String("Abc") );

    entity.printName();

    return 0;
}