#include <iostream>

int main(void){

    struct Union{
        union{
        float a;
        int b;
        };
    };
    
    Union obj;
    obj.b = 10;
    std::cout << obj.a << ", " << obj.b << std::endl;
    // Now we had put in the data in the form of integer
    // so float interprets the same memory differently

    return 0;
}