#include "temp.h"
#include <cstring>

// We resolve it by writing a move constructor
// which just passes a temp value (rvalue) so we can use it however we like

// and we simply assign the pointer of string to string member of entity
// dont know why we dont just do that directly
// because we saw that the object we copied into the member got destroyed...lol

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

    // Move constructor, rvalue thing...for temporary shit
    // now this will be called when we pass in the string literal char* in the object initialization below
    String(String&& other) noexcept {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        // This is necessary as the old object which is copied also will be destroyed...so we need to point it to null otherwise our currenly in use data will be destroyed
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

    // Move constructor, rvalue thing...for temporary shit
    Entity(String&& name) : m_Name(name) {

    }
};

int main(void){
    // here "Abc" is a actually a string literal so its temporary so it will call the move copy constructor instead of the original copy constructor
    Entity entity( "Abc" );

    entity.printName();

    return 0;
}