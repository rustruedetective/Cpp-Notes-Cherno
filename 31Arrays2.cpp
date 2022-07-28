#include "temp.h"
#include <array>

// Memory fragmentation: it occurs because we have this array's elements pointing to another element etc

// In this example, the memory of class will jump to the memory of array
// Where each element of array will point/jump to memory of next element
// Now jumping memory is a performance hit so we can just use the heap/dynamic memory to avoid this

// There is a standard data structure of array in c++11: bounce checking, keeps track of size of array

// You cant keep track of size of heap array, as it has degenerated to a pointer
// But it should be, how does delete[] figure out how much memory to free?
// The actual way to is compiler dependant, sometimes its stored at -1 index sometimes other, etc

// For normal/stack allocated arrays you can use sizeof method as long as the array is not passed to a function and looses its array characteristics to pointer characteristics

class Entity{
    int array[5];
public:
    Entity(){
        for(int i = 0; i < 5; i++)
            array[i] = 2;
    }
};

class Entity2{
    int *array = new int[5];
public:
    Entity2(){
        for(int i = 0; i < 5; i++)
            array[i] = 2;
    }
    ~Entity2(){
        delete[] array;
    }
};


int main(void){
    Entity e1;   //this stores all memory of array
    Entity2 e2;   //this does not store memory of array as its memory is stored on the heap instead

    // Other way to know size, but size needs to be known at compile time
    static constexpr size = 5;
    int array[size];

    // Standard library array
    std::array<int, 5> arr;
    logn( arr.size() )   //now you have size

    return 0;
}