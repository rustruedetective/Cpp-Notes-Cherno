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

    Entity(String&& name) : m_Name( std::move(name) ) {

    }
};

int main(void){
    // if i want to move the string to dest

    // here it will copy it instead
    String string = "Hello";
    String dest = string;

    // we need to make string temporary (rvalue ref) to make it move
    // however this wont work as its an assignment operator instead of a constructor call
    // dest = std::move(string);   // we did not overload the assignemnt operator to use the ref, we only did for constructor so:-
    // we need to use the rvlaue ref constructor
    String dest2 = std::move(string);
    // or
    String dest3( std::move(string) );
    // Note: using std::move instead of using (String&&) means we dont have to explicitly know the type of data
    
    return 0;
}