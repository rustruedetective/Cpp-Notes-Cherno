#include "temp.h"
#include <cstring>

// in the previous example even with our move constructors it did not work
// well the problem is coming from the entity constructor
// it needs explicit casting

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

    // it needs explicit casting
    // in production cast it like: std::move(var)
    Entity(String&& name) : m_Name( (String&&)name) {

    }
};

int main(void){
    Entity entity( "Abc" );

    entity.printName();

    return 0;
}