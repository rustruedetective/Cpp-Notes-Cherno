#include "temp.h"
#include <vector>

// Trying to optimize this redundant copying

// Strategy 1:
// Change copying method

// Strategy 2:
// Knowing our environment: if we know how much data we will use the vector for
// We can just pre-initialize it with enough memory for that many elements

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
    // Strategy 2:
    // Recommended way:-
    std::vector<Vertex> arr;
    arr.reserve(3);   //reserves memory for 3 elements
    arr.push_back( {1, 2, 3} );
    arr.push_back( {4, 5, 6} );
    arr.push_back( Vertex(7,8,9) );
    // we get objects copied only 3 times
    //this is a major improvement, otherwise it would be sum of (1 to nth element) no. of copies


    // This is not a good way, actually it wont even compile as vector does not have a default constructor which takes in an int
    // std::vector<Vertex> arr2(3);
    // or maybe its because it constructs three objects as well...

    return 0;
}