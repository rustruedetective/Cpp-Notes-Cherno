#include "../temp.h"
#include <vector>
#include "Vector.h"

// instead of copying on each change in size, you can try to move them

// Refer to "94" for a vector class which can take in std::strings

struct Vector3{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    int* m_MemoryBlock;

    Vector3(){
        m_MemoryBlock = new int[5];
    }
    Vector3(float scalar) : x(scalar), y(scalar), z(scalar){
        m_MemoryBlock = new int[5];
    }
    Vector3(float scalar, float scalar2, float scalar3) : x(scalar), y(scalar2), z(scalar3){
        m_MemoryBlock = new int[5];
    }

    // copy constructor:
    Vector3(const Vector3& other) = delete;
    // Vector3(const Vector3& other)
    //  : x(other.x), y(other.y), z(other.z)
    // {
    //     logn( "Copied!" )
    //     // here we wont copy the m_MemoryBlock as it would just copy other's pointer...lol and point to their memory
    // }

    Vector3(Vector3&& other)
     : x(other.x), y(other.y), z(other.z)
    {
        logn( "Moved!" )
        // here we can copy the pointer
        // as we are stealing/moving its resources and will set other's pointer to null
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        
    }

    ~Vector3(){
        logn("Destroyed")
        delete[] m_MemoryBlock;
    }

    Vector3& operator=(const Vector3& other) = delete;
    // Vector3& operator=(const Vector3& other){
    //     logn("Copied")
    //     x = other.x;
    //     y = other.y;
    //     z = other.z;
    //     return *this;
    // }

    Vector3& operator=(Vector3&& other){
        logn("Moved")
        // here we can copy the pointer
        // as we are stealing/moving its resources and will set other's pointer to null
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

template <typename T>
void PrintVector(const Vector<T>& vector){
    for(int i = 0; i < vector.Size(); i++)
        logs( vector[i] )
    logn("")
}

template <>
void PrintVector(const Vector<Vector3>& vector){
    for(int i = 0; i < vector.Size(); i++)
        logs( vector[i].x << " " << vector[i].y << " " << vector[i].z << " " )
    logn("")
}

int main(void){
    // Vector<Vector3> values;
    // values.PushBack(Vector3(1.0f));
    // values.PushBack(Vector3(1.0f,2.0f,3.0f));
    // values.PushBack(Vector3());
    // PrintVector(values);



    logn("-------------")

    // the emplace function instead of taking in the constructor for object, it instead takes in its parameters and constructs the Object itself!!!
    Vector<Vector3> values2;
    values2.EmplaceBack(1.0f);
    values2.EmplaceBack(1.0f,2.0f,3.0f);
    values2.EmplaceBack();
    PrintVector(values2);

    values2.EmplaceBack(10.0f);
    values2.EmplaceBack(10.0f,20.0f,30.0f);
    values2.PopBack();
    PrintVector(values2);
    
    values2.EmplaceBack();
    PrintVector(values2);



    logn("-------------")

    Vector<int> values3;
    values3.EmplaceBack(1);
    values3.EmplaceBack(2);
    values3.EmplaceBack(3);
    PrintVector(values3);

    values3.EmplaceBack(10);
    values3.EmplaceBack(20);
    values3.PopBack();
    PrintVector(values3);
    
    values3.EmplaceBack(40);
    PrintVector(values3);

    return 0;
}