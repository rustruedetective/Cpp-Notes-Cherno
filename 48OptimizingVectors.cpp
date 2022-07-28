#include "temp.h"
#include <vector>

// C++ is a good language for optimization
// To optimize you should know a bit about your environment
// Which is a huge shit itself

// To optimize vectors: how they work, how you can change them to make them better

// We focus on copying
// When ever the std::vector array needs to resize, it copies old objects into new ones
// How can we minimize this copying?

struct Vertex
{
    float x, y, z;

    Vertex(float xi, float yi, float zi)
        : x(xi), y(yi), z(zi)
    {
    }

    Vertex(const Vertex &obj)
        : x(obj.x), y(obj.y), z(obj.z)
    {
        logn( "Copied!" )
    }
};

int main(void)
{
    std::vector<Vertex> arr;
    arr.push_back( {1, 2, 3} );   // *** 1. Called copy constructor 1 time : We construct the Vertex object in main function, then put/copy it in the memory allocated by vector
    // {1,2,3} is first constructed on main then put in memory allocated by vector
    // 1 copy constructor call


    // here we inputed new elements, so we copy old data into new array and delete old array
    arr.push_back( {4, 5, 6} );   // *** 2. We copy two objects so we get 2 copy constructors called, one is new push_back element which is constructed on main then copied on the vector's memory, and the first element/object which we already had in it being copied again
    // {1,2,3} is copied to new std::vector array
    // {4,5,6} is constructed on main then copied to the new std::vector array/memory
    // 2 new copy constructor calls
    // Total : 3 copy constructor calls

    arr.push_back( Vertex(7,8,9) );   // *** 3. same as above, (7,8,9) is constructed on main then copied to array, and other two previous/ objects elements also copied
    // {1,2,3} is copied to new std::vector array
    // {4,5,6} is copied to new std::vector array
    // (7,8,9) is constructed on main then copied to the new std::vector array/memory
    // 3 new copy constructor calls
    // Total : 6 copy constructor calls

    return 0;
}