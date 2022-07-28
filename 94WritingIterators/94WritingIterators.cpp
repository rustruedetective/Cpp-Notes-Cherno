#include "../temp.h"
#include <vector>
#include "Vector.h"

// our own implementation

// iterator is just a pointer to the current location of element
// then just incrementing and decrementing it to change location
// but for complex data structures we make iterator pointer go to lets say child nodes of tree etc

// read other people's code

int main(void){
    Vector<int> values;
    values.EmplaceBack(1);
    values.EmplaceBack(2);
    values.EmplaceBack(3);
    values.EmplaceBack(4);
    values.EmplaceBack(5);


    logn("Not using iterators:")
    for(int i = 0; i < values.Size(); i++)
        logs(values[i]);
    logn("")


    logn("Range Based for loop:")
    for(int value : values)
        logs(value)
    logn("")


    logn("Iterator:")
    for(Vector<int>::Iterator it = values.begin(); it != values.end(); it++)
        logs(*it)
    logn("")


    Vector<std::string> values2;
    values2.EmplaceBack("this is string 1");
    values2.EmplaceBack("this is string 2");
    values2.EmplaceBack("this is string 3");
    values2.EmplaceBack("this is string 4");
    values2.EmplaceBack("this is string 5");


    logn("Not using iterators:")
    for(int i = 0; i < values2.Size(); i++)
        logs(values2[i]);
    logn("")


    logn("Range Based for loop:")
    for(std::string value : values2)
        logs(value)
    logn("")


    logn("Iterator:")
    for(Vector<std::string>::Iterator it = values2.begin(); it != values2.end(); it++)
        logs(*it)
    logn("")

    return 0;
}