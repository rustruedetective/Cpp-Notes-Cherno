#include "temp.h"
#include <vector>

// Vector is just a resizing array!

/*
    - Now should we use <Vertex> and make array of objects or <Vertex*> and make array of pointers?
    - It depends on knowledge yet unknown to me

    - Objects/arrays:-
    - Well one argument is if you have objects in the std::vector array then you have x,y,z in a row
    - x y z x y z x y z...
    - Since this all is in one lane/continuous memory, iterating, reading, writing to them is super fast
    - Something to do with cache lanes

    - But if you store as pointers then the actuall objects are scattered in memory and you no longer have this
    - line of x y z which you can access super fast

    - Pointers:-
    - Even though the scattered objects are not fast to access
    - when it comes time to copy the objects, you just copy pointers which is super fast
    - compared to slowly copying complete objest

    So Use Objects More Than Pointers, use pointers only as last resort
*/

//Example:-

struct Vertex{
    float x, y, z;
    // this is we had a class instead
    // this so we dont need getters
    // friend std::ostream& operator<<(std::ostream& stream, const Vertex& obj);
};

std::ostream& operator<<(std::ostream& stream, const Vertex& obj){
    stream << obj.x << ", " << obj.y << ", " << obj.z;
    return stream;
}

void fun(const std::vector<Vertex>& obj){
    
}

int main(void){
    // Vertex * arrLow = new Vertex[5];   // very less elements
    // Vertex * arrHigh = new Vertex[5000000];   // very high number of elements



    // 1. CREATE:-
    // Why not use some resizing array?
    std::vector<Vertex> arr;   // the <Vertex> is the template data type



    // 2. TO ADD ELEMENT:-
    // arr.push_back(*(new Vertex()));   // dont do this...how will u manage it?
    arr.push_back({1,2,3});   // this is called an initializer list which we passed in the constructor, only available in c++11
    arr.push_back({4,5,6});



    // 3. TO ITERATE:-
    // for(int i = 0; i < arr.size(); i++)
    //     logn( arr[i] )   // we already overloaded the << operator
    
    // How about some c++ shinanigans!
    // for(Vertex v : arr)   // this is bad as it copies v on each iteration
    //     logn( v )

    // for(const Vertex& v : arr)   // you saw this coming right...
    //     logn( v )



    // 4. TO CLEAR AN ELEMENT:-
    // arr.erase(1);   // no we cannot provide int index, we need to provide in an iterator
    arr.erase( arr.begin() +1 );   // yeah... thats the iterator argument we need to provide
    for(const Vertex& v : arr)
        logn( v )


    // 5. TO CLEAR ALL std::vector ARRAY:-
    arr.clear();

    // 6. FUNCTION CALL SHOULD BE WITH CONST REF, OTHERWISE ALL WILL BE COPIED:-
    fun(arr);

    return 0;
}