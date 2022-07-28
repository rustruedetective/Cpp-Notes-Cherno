#include <iostream>

int Mul(int a, int b){
    return a*b;
}

void logMul(int a, int b){
    int result = Mul(a, b);
    std::cout << result << std::endl;
}

int main(void){
    //we might need to repeat this block so we should create another function for it
    int result = Mul(3, 89);
    std::cout << result << std::endl;

    int result2 = Mul(4, 90);
    std::cout << result2 << std::endl;

    int result3 = Mul(5, 91);
    std::cout << result3 << std::endl;

    logMul(3, 89);
    
    logMul(4, 90);
    
    logMul(5, 91);

    return 0;
}