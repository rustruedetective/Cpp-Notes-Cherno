#include <iostream>

//function overloading gone wrong

int Mul(int a, int b){
    return a*b;
}

long Mul(long a, long b){
    return a+b;
}

// WTF!!! Now how does the compiler know where what is being called?

int main(void){
    std::cout << Mul(3, 3) << std::endl;   // for values within range of int it calls the int Mul
    std::cout << Mul(3333333333, 3333333333) << std::endl;   //for values outside the range of int it calls the long Mul
    std::cout << Mul(3333333333, 3) << std::endl;   //but here it stubornly says that long has to be greater than the range of int
    //it gets confused

    return 0;
}