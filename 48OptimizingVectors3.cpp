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
    // Strategy 1+2:
    // Now we also need to construct the object in vector itself instead of main and then getting it copied
    std::vector<Vertex> arr;
    arr.reserve(3);
    // using emplace_back() we can do that, this function only needs object's constructor parameters
    arr.emplace_back(1, 2, 3);
    arr.emplace_back(4, 5, 6);
    arr.emplace_back(7, 8, 9);
    // no more copied objects, copy constructor never called!

    return 0;
}